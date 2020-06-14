import re
import os
import json
import subprocess
import argparse

parser = argparse.ArgumentParser(description='Compile notes')
parser.add_argument('-i', dest='infiles', action='append', help='Files to compile')
parser.add_argument('-o', dest='outfiles', action='append', help='Files to write to')
args = parser.parse_args()

if not args.infiles:
    raise ValueError('Must provide input files')

if len(args.infiles) != len(args.outfiles):
    raise ValueError('Must provide same number of input and output files')

for infile, outfile in zip(args.infiles, args.outfiles):
    with open(infile) as f, open(outfile, 'w') as g:
        filestr = f.read()
        snippet_pattern = "(```snippet\n(\{.*?\})\n```)"
        matches = re.findall(snippet_pattern, filestr, flags=re.DOTALL)
        for match, args in matches:
            builds = []
            shows = []
            runs = []
            print(args)
            fail = False
            args = json.loads(args)
            for cmd in args['build']:
                proc = subprocess.run(cmd.split(), capture_output=True)
                err = proc.stderr
                builds.append(cmd)
                if err:
                    fail = True
                    builds.append(err.decode('ascii'))
                    break
            builds = [f'```\n{b}\n```\n' for b in builds]
            for filename in args['show']:
                with open(filename) as f:
                    shows.append(f.read())
            shows = [f'```c\n// {fn}\n{s}```\n' for fn, s in zip(args['show'], shows)]
            for cmd in args.get('run', []):
                output = subprocess.check_output(cmd.split())
                output_ascii = output.decode('ascii')
                runs.append(f'$ {cmd}\n{output_ascii}')
            runs = [f'```\n{r}```\n' for r in runs]
            for cmd in args.get('clean', []):
                proc = subprocess.run(cmd.split())
            all_out = '\n'.join(('\n'.join(shows),
                                 '\n'.join(builds),
                                 '\n'.join(runs)))
            filestr = filestr.replace(match, all_out)
        g.write(filestr)
