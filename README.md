# Control Flow

This section discusses control flow, meaning how to control the order in which
steps in your program are run.

## Conditional Statements (If-Else)

The `if` statement is fundamental to control flow, and is at the core of most
constructs we will talk about.  Consider for example, getting the maximum of
two numbers, a previous assignment.  True, you can accomplish this through the
ternary operator, but the `if` statement allow for far more complex cases.
Below is an example.

```c
#include <stdio.h>

int main() {
    int x = 10;
    int y = 5;
    int max;
    max = y;
    if (x > y)
        max = x;
    printf("max = %d\n", max);
}
```
```
max = 10
```

Formally, if the condition (in the parentheses) is true (nonzero) then the
statement is executed.  Often we also want to do something in the case that the
condition is false, and this is where `else` comes in.  Simply slap an `else`
on the line after the statement like so:

```c
#include <stdio.h>

int main() {
    int x = 10;
    int y = 5;
    int max;
    if (x > y)
        max = x;
    else
        max = y;
    printf("max = %d\n", max);
}
```
```
max = 10
```

Now, suppose you wanted to keep track of say, if `y` was greater than `x`.  One
way to do this is to create a variable for it and set it as demonstrated below.

```c
#include <stdio.h>

int main() {
    int x = 10;
    int y = 5;
    int max;
    int y_was_greater = 0;
    if (x > y)
        max = x;
    else
        max = y;
        y_was_greater = 1;
    printf("y_was_greater? %d\n", y_was_greater);
}
```
```
y_was_greater? 1
```

Huh that's weird...  `y` is `5` and `x` is `10` so why did `y_was_greater` get
set to `1`?  Well, our spacing is misleading.  Even though we indented
`y_was_greater=1`, it is actually not "inside" the `else`.  When we use
`if/else` in this fashion, only one statement is covered.

## Code Blocks

The way to avoid the previous confusion is to use a *block *.  A block is code
within braces: `{}`.  Any code within braces is equivalent to a single
statement, so we can load as much as we want into them.  For example, the
correct way to achieve what we want is this:

```c
#include <stdio.h>

int main() {
    int x = 10;
    int y = 5;
    int max;
    int y_was_greater = 0;
    if (x > y) {
        max = x;
    } else {
        max = y;
        y_was_greater = 1;
    }
    printf("y_was_greater? %d\n", y_was_greater);
}
```
```
y_was_greater? 0
```

More complexity is introduced with nested if statements.  Consider the case of
modeling a stduent's reaction to a grade illustrated below.

```c
#include <stdio.h>

int main() {
    int grade = 75;
    int credits = 2;
    if (credits != 0) {
        if (grade >= 90) {
            printf("No problem!\n");
        } else if (grade >= 80) {
            printf("Not bad.\n");
        } else if (grade >= 70) {
            if (credits < 3) {
                printf("All right...\n");
            } else {
                printf("Not good.\n");
            }
        } else {
            printf("Panic!\n");
        }
    } else {
        printf("Who cares?\n");
    }
}
```
```
All right...
```

Note that the logic of this example, while not very easy to follow, is aided by
judicious use of "whitespace".  After every `if` or `else` is a new line and an
additional 4 spaces to show the statement is *nested* one level deeper.  These
newlines and spaces are technically not needed to get the same result, as shown
in the following equivalent example.

```c
#include <stdio.h>

int main() {
    int grade = 75;
    int credits = 2;
    if (credits != 0) { if (grade >= 90) {
    printf("No problem!\n"); } else if (grade >= 80) {
    printf("Not bad.\n"); } else if (grade >= 70) {
    if (credits < 3) { printf("All right...\n"); } else {
    printf("Not good.\n"); } } else { printf("Panic!\n");
    } } else { printf("Who cares?\n");}
}
```
```
All right...
```

Just because you can, does not mean you should however.  The above is very poor
style and it is impossible to read.  Never do it!  Always align your `else` and
`if` statements at the same level.

## Switch

A `switch` statement can be used if you have many possible constant values you
want to check against.  It is more or less equivalent to a long chain of
`if-else` statements, though slightly easier to write out.  The example program
below uses switch statements to selec a dwarf to quote from Snow White

```c
#include <stdio.h>

int main() {
    /*
    dopey = 0 grumpy = 1 sleepy = 2 happy = 3
    bashful = 4 sneezy = 5 doc = 6
    */
    int dwarf = 3;
    switch (dwarf) {
        case 0:
            printf("...\n");
        case 1:
            printf("Mark my words, there's trouble a-brewin'.\n");
        case 2:
            printf("*yawns*\n");
        case 3:
            printf("I'll take a chance for her.\n");
        case 4:
            printf("Ohhhhh goooosh.\n");
        case 5:
            printf("Sink's empty. Hey, someone stole our dishes!\n");
        case 6:
            printf("We're gonna go down and chase it up, uh uh uh, up...down.\n");
    return 0;
    }
}
```
```
I'll take a chance for her.
Ohhhhh goooosh.
Sink's empty. Hey, someone stole our dishes!
We're gonna go down and chase it up, uh uh uh, up...down.
```

Hmm, something seems not quite right.  We selected 3 and got the quote for 3,
but then we also got all the following quotes.  The reason this happened is
because the switch essentially just says to go to whatever case and then
continue running the code from there.  The cases do not strictly seperate code,
they only act as labels for where to go.  If we want to execute only the code
inside that case, we must `break` out of the `switch` as follows

```c
#include <stdio.h>


int main() {
    /*
    dopey = 0 grumpy = 1 sleepy = 2 happy = 3
    bashful = 4 sneezy = 5 doc = 6
    */
    int dwarf = 3;
    switch (dwarf) {
        case 0:
            printf("...\n");
            break;
        case 1:
            printf("Mark my words, there's trouble a-brewin'.\n");
            break;
        case 2:
            printf("*yawns*\n");
            break;
        case 3:
            printf("I'll take a chance for her.\n");
            break;
        case 4:
            printf("Ohhhhh goooosh.\n");
            break;
        case 5:
            printf("Sink's empty. Hey, someone stole our dishes!\n");
            break;
        case 6:
            printf("We're gonna go down and chase it up, uh uh uh, up...down.\n");
            break;
    return 0;
    }
}
```
```
I'll take a chance for her.
```

Not including the `break` can be helpful if we want to combine cases, and this
is one of the advantages of the `switch` case over `if-else`.  For example
check out the following code which counts down from a chosen number:

```c
#include <stdio.h>

int main() {
    int countDownFrom = 3;
    switch (countDownFrom) {
        case 5:
            printf("5\n");
        case 4:
            printf("4\n");
        case 3:
            printf("3\n");
        case 2:
            printf("2\n");
        case 1:
            printf("1\n");
        case 0:
            printf("0\n");
        default:
            printf("Lift off!\n");
    return 0;
    }
}
```
```
3
2
1
0
Lift off!
```

Note that this code also makes use of the `default` keyword.  In switch
statements, `default` just means go here if none of the other cases worked.
For example, if had entered `int countDownFrom = 100`, the output would have
been only `Lift off!`.

This code has an obvious weakness however.  What if want to count down from a
number higher than 5?  We would have to add more and more code.  If we wanted
to count down from 100 our code would be gigantic.  Luckily as we will see,
loops provide a better way!

## While Loop

A `while` loop is our way of telling our machine: "While this condition is
true, do X."  This can be used for example, to create a countdown from some
arbitrary integer as in the following example:

```c
#include <stdio.h>

int main() {
    int countDownFrom = 100;
    while (countDownFrom >= 0) {
        printf("%d, ", countDownFrom);
        countDownFrom--;
    }
    printf("Lift off!\n");
}
```
```
100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, Lift off!
```

As you can see, we can use a `while` loop to repeat lines of code multiple
times.  This means we can fit a potentially infinite number of actions into a
small number of lines of code, and that is very powerful.

What follows is a much more complex example of using a `while` loop to
approximate the square root of 2.

```c
#include <stdio.h>

int main() {
    double square = 2;
    double precision = 1e-3;
    double lowerBound = 0;
    double upperBound = square;
    double currentGuess = lowerBound;
    while (upperBound - lowerBound > precision) {
        printf("Guessing: %g...  ", currentGuess);
        if (currentGuess*currentGuess > square) {
            printf("That was too big\n");
            upperBound = currentGuess;
            currentGuess = (currentGuess + lowerBound) / 2.0;
        } else {
            printf("That was too small\n");
            lowerBound = currentGuess;
            currentGuess = (currentGuess + upperBound) / 2.0;
        }
        printf("Now I know the answer is between %g and %g\n",
               lowerBound, upperBound);
    }
    printf("The square root of %g is about %g\n", square, currentGuess);
}
```
```
Guessing: 0...  That was too small
Now I know the answer is between 0 and 2
Guessing: 1...  That was too small
Now I know the answer is between 1 and 2
Guessing: 1.5...  That was too big
Now I know the answer is between 1 and 1.5
Guessing: 1.25...  That was too small
Now I know the answer is between 1.25 and 1.5
Guessing: 1.375...  That was too small
Now I know the answer is between 1.375 and 1.5
Guessing: 1.4375...  That was too big
Now I know the answer is between 1.375 and 1.4375
Guessing: 1.40625...  That was too small
Now I know the answer is between 1.40625 and 1.4375
Guessing: 1.42188...  That was too big
Now I know the answer is between 1.40625 and 1.42188
Guessing: 1.41406...  That was too small
Now I know the answer is between 1.41406 and 1.42188
Guessing: 1.41797...  That was too big
Now I know the answer is between 1.41406 and 1.41797
Guessing: 1.41602...  That was too big
Now I know the answer is between 1.41406 and 1.41602
Guessing: 1.41504...  That was too big
Now I know the answer is between 1.41406 and 1.41504
The square root of 2 is about 1.41455
```

This is an algorithm called the bisection method.  It works taking a lower
bound for the answer and an upper bound for the answer and shifting them toward
each other until they are nearly the same.  We can do this reliably in this
case because the function we are guessing and checking on is monotonically
increasing in a known range (the square function).

Essentially, guess a number, if the square is too high go down.  If the square
is too low, go higher.  That is the essence of the alorithm.  The `while` loop
allows us to keep going until our guess is within some distance of the real
answer.

*Question: Can you write code to use the same algorithm to find cube roots?*


## For Loop

As we saw with the last example, `while` loops are quite useful, especially in
cases where you don't know how many steps some computation will take.  Some
commonalities in the loops we have seen are:

* Initialize a value Check a condition Do something at the end

A `for` loop can make these steps more clear in simple cases.  For example
consider again the case of counting down from some number:

```c
#include <stdio.h>

int main() {
    int countDownFrom;
    for (countDownFrom = 100; countDownFrom >= 0; countDownFrom--) {
        printf("%d, ", countDownFrom);
    }
    printf("Lift off!\n");
}
```
```
100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, Lift off!
```

The `for` loop is typically preferable when you have some simple
initialization, condition, and increment/decrement.  Note that this `for` loop
is a little more readable than the `while` loop we had before. However, you
should note that you can always get away with using one or the other and its
fine to stick with the one you are most comfortable with.

Here is a slightly more complex example including a *nested* loop (meaning a
loop within a loop) to produce a times table.

```c
#include <stdio.h>

int main() {
    int n, m, max, product;
    max = 13;
    for (m = 1; m <= max; m++) {
        for (n = 1; n <= max; n++) {
            product = m*n;
            printf("%4d", product);
        }
        printf("\n");
    }
}
```
```
   1   2   3   4   5   6   7   8   9  10  11  12  13
   2   4   6   8  10  12  14  16  18  20  22  24  26
   3   6   9  12  15  18  21  24  27  30  33  36  39
   4   8  12  16  20  24  28  32  36  40  44  48  52
   5  10  15  20  25  30  35  40  45  50  55  60  65
   6  12  18  24  30  36  42  48  54  60  66  72  78
   7  14  21  28  35  42  49  56  63  70  77  84  91
   8  16  24  32  40  48  56  64  72  80  88  96 104
   9  18  27  36  45  54  63  72  81  90  99 108 117
  10  20  30  40  50  60  70  80  90 100 110 120 130
  11  22  33  44  55  66  77  88  99 110 121 132 143
  12  24  36  48  60  72  84  96 108 120 132 144 156
  13  26  39  52  65  78  91 104 117 130 143 156 169
```

## Do-While Loop

The `do-while` loop is a slight modification to the `while` loop.  The only
difference is that the `do-while` loop guarantees that the body is executed
at least once.  Is is structured like this:

```
do
    statement
while (expression);
```

This essentially says "do (whatever) while (the expression) is true"

An example of using a `do-while` to generate a random number between 0 and 100
is shown below:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = -1;
    do {
        n = rand();
    }
    while (n > 100);
    printf("Random number between 0 and 500: %d\n", n);
}
```
```
Random number between 0 and 500: 92
```

Note that there are better methods for generating random numbers in a certain
range, this is shown only as a simple example.  You should also note that
any `do-while` can loop can be replaced by a `while` loop, and they are not
ever strictly necessary.  For example, the program below performs the same
computation.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = -1;
    n = rand();
    while (n > 100) {
        n = rand();
    }
    printf("Random number between 0 and 100: %d\n", n);
}
```
```
Random number between 0 and 100: 92
```

You can see we translated the `do-while` into a `while` loop by adding the body
right before the loop.  You can imagine this might be excessive if you have a
lot in the body, so we will now discuss some other helpful constructs that
will make this more elegant.

## Break and Continue

The `break` and `continue` statements allow us to have more control over our
loops.  `break` breaks us out of the loop and sends us to the end while
`continue` places us back at the start of the loop.

Below is an example that uses `break` that is used to generate a random number
is a similar fashion as the previous two examples.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = -1;
    while (1) {
        n = rand();
        if (n <= 100) {
            break;
        }
    }
    printf("Random number between 0 and 100: %d\n", n);
}
```
```
Random number between 0 and 100: 92
```

The `while 1` means loop forever (since 1 is always true) which may not be
a good idea in many cases.  However, because of the `break` statement, we
are still able to exit the loop once we have generated a number less than
or equal to 100.

The `continue` statement is good for avoiding nesting `if` statements very
deeply inside your loop.  A typical case would be where you are performing
a sequence of steps, and after each step you check if you are able to skip
the rest.

The following is a contrived example of such a form of processing.  For every
number 0 through 49, we print it if:

* It is divisible by 3
* Its square is less than 500
* Its cube is not divisible by 5

```c
#include <stdio.h>

int main() {
    int n;
    for (n = 0; n < 50; n++) {
        if (n % 3 == 0) {
            continue;
        }
        int square = n*n;
        if (square > 500) {
            continue;
        }
        int cube = n*n*n;
        if (cube % 5 == 0) {
            continue;
        }
        printf("%d\n", n);
    }
}
```
```
1
2
4
7
8
11
13
14
16
17
19
22
```

Here, we could have computed the square and cube at the start and then put
all of the conditions in one big statement.  However, that method would
potentially waste time on later computations which could have been skipped.
To avoid the wasted time, we could instead nest the `if` statements though
most would consider that harder to read.

On a practical note, you should generally try to avoid using `continue` and
`break` especially far from the start of the loop, or the code may become
confusing to read.  The reader will have to jump all over the place to
understand the flow of the program.  That brings us to our next point, you
should almost never use...

## Goto and Labels

With all of this jumping around inside loops.  You may ask whether it is
possible to simply jump anywhere in the program, and the answer is yes!  Using
`goto` you can jump basically andwhere you desire.  The following example
uses `goto` to find one Pythagorean triple.  As soon as it finds it, it
immediately jumps all the way out of the deeply nested loop, rather than
spending any extra time inside.

```c
#include <stdio.h>

int main() {
    int a, b, c, max;
    max = 13;
    for (a = 1; a <= max; a++) {
        for (b = 1; b <= max; b++) {
            for (c = 1; c <= max; c++) {
                if (a*a + b*b == c*c) {
                    goto found;
                }
            }
        }
    }
found:
    printf("%d %d %d\n", a, b, c);
}
```
```
3 4 5
```

This is indeed very useful.  But you should still try to avoid it, and note
that you never **need** a `goto`.  The following is similar code that uses
the `break` statement instead.

```c
#include <stdio.h>

int main() {
    int a, b, c, max;
    int found = 0;
    max = 13;
    for (a = 1; a <= max; a++) {
        for (b = 1; b <= max; b++) {
            for (c = 1; c <= max; c++) {
                if (a*a + b*b == c*c) {
                    found = 1;
                }
                if (found) {
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        if (found) {
            break;
        }
    }
    printf("%d %d %d\n", a, b, c);
}
```
```
3 4 5
```

It does seem a lot harder to read, and the `if` statement does take some time
to perform, but it is usually a cost worth paying.  It is hard to see the
benefit because the code presented is very compact to start with, but `goto`
makes things much harder in large code projects.  We will see a better way to
write this when we learn functions in an upcoming section.  For more reading,
see [XKCD 292](https://xkcd.com/292/) or 
[Go To Statement Considered Harmful](http://www.u.arizona.edu/~rubinson/copyright_violations/Go_To_Considered_Harmful.html).

Now that I've given you all the warnings, there are some cases where `goto` is
really the right thing to do.  One common case is error handling.  If your
program reaches some unexpected state and you want one place to go in the case
of an error, it is acceptable to use `goto` in C.  Other programming languages
have much better support for error handling and so they have actually removed
`goto` all together.

# Conclusion

You now have all the tools you need to fully control your program's flow.
From here on out, we will discuss tools to make that flow easier to build
and read.
# Functions

This section discusses functions, another fundamental building block of almost
all programming languages.  Functions allow us to use the same code more than
once without copy pasting it.  They are similar to mathematical functions in
that they take an input, and provide and output.

## Basic Anatomy

Below is a general outline of a function definition.

```
RETURN_TYPE FUNCTION_NAME(TYPE_1 PARAM_1, TYPE_2 PARAM_2... TYPE_N PARAM_N) {
    STATEMENTS;
    return RETVAL;
}
```

Here is what each of these means:

* Return Type: The type of the output variable
* Function Name: What the function is called
* Param 1...N: The parameters (inputs) to be passed in
* Type 1...N: The types expected of each parameter (input)
* Statements: The code of the function
* return: The value is computed and returned to the caller

The first line in the outline is known as the **function signature**,
which defines the input and outputs types.

Now we will go through many examples of different functions, increasing in
complexity.

## No Input, No Output

The simplest possible function has no inputs and no outputs.  This can be
*defined* and *called* as follows.

```c
// snippets/func.c
void myFunction() {

}

int main() {
    myFunction();
}
```


```
```


To say that a function returns nothing, one can set the return type to `void`.

Void functions are particularly useful when the function's main purpose is to
produce some side effect.  An example you are already familiar with is
`printf`.  Below is an example of a `void` function that actually does
something.

Note that because there are no inputs to the function, we call it simply by
writing the function name followed by empty parentheses: `()`.

```c
// snippets/void.c
#include <stdio.h>

void sayHi() {
    printf("Hi\n");
}

int main() {
    sayHi();
}
```


```
Hi
```


## One Input, No Output

The code below is an example of a function which takes only one input, an
integer to print, and outputs nothing.

Note that in the function signature, we added `int num` to specify that the
function takes one integer as its input.  We also called the function with
`(42)` instead of empty parentheses to feed the value 42.

```c
// snippets/param.c
#include <stdio.h>

void printInt(int num) {
    printf("%d\n", num);
}

int main() {
    printInt(42);
}
```


```
42
```


## One Input, One Output

This code is an example of a function which takes one input, does something
with it, and returns a value.  We picked the particularly simple example of
adding two to the input.

Note that we changed the return type of the function in the signature from
`void` to `int`.  Then, when calling the function we **assigned** the output to
the variable `three`.

```c
// snippets/output.c
#include <stdio.h>

int addTwo(int num) {
    return num + 2;
}

int main() {
    int three = addTwo(1);
    printf("three = %d\n", three);
}
```


```
three = 3
```


## Multiple Inputs, One Output

The code below demonstrates the definition of a function with two inputs and
one output.  The function simply takes two integers and adds them.

```c
// snippets/multi.c
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int five = add(2, 3);
    printf("five = %d\n", five);
}
```


```
five = 5
```


Note that we added one more parameter in the signature.

## Multiple Inputs, Multiple Outputs

Unfortunately, it is not really possible to return multiple values in C.  In
future sections we will see how we can simulate returning multiple values.

## Function Prototypes

In some cases, it is convenient to place function
definitions separate from their implementation.  A
definition without an implementation is called a
`prototype`.

In the below example we define the `add` function first with no body, and then
later we define it again with a body.  The definition can be used to check that
the function call in `main` is valid.

```c
// snippets/prototype.c
#include <stdio.h>

int add(int a, int b);

int main() {
    int res = add(1.5, 2);
    printf("res = %d\n", res);
}

int add(int a, int b) {
    return a + b;
}
```


```
res = 3
```


If you do not place the prototype before calling the function, you may get
strange results as shown in the following example.

```c
// snippets/noprototype.c
#include <stdio.h>

int main() {
    int res = add(1.5, 2);
    printf("res = %d\n", res);
}

int add(int a, int b) {
    return a + b;
}
```


```
res = -283269278
```


## Function Composition

You can use functions as many times as you want, and feed their outputs as
inputs to other functions.  The code below demonstrates a simple example.

```c
// snippets/composition.c
#include <stdio.h>

int multiply(int a, int b) {
    return a * b;
}

int add(int a, int b) {
    return a + b;
}

int main() {
    int a = 3;
    int b = 4;
    int c = 5;
    int sum = add(add(a, b), multiply(b, c));
    int product = multiply(add(a, b), multiply(b, c));
    printf("product = %d\n", product);
}
```


```
product = 140
```


*Question: what is the value of the sum variable above?*

## Returning Early

Functions may return a value early, before all code has been executed.  In this
example we see how this can be useful for breaking out of multiple loops.

```c
// snippets/functriple.c
#include <stdio.h>

int find_triple(int max) {
    int a, b, c;
    for (a = 1; a <= max; a++) {
        for (b = 1; b <= max; b++) {
            for (c = 1; c <= max; c++) {
                if (a*a + b*b == c*c) {
                    return 1;
                }
            }
        }
    }
    return 0;
}


int main() {
    int triple_exists = find_triple(13);
    printf("Triple exists? %d\n", triple_exists);
}
```


```
Triple exists? 1
```


This function is not quite so useful, as it only says whether a triple exists
rather than what the triple is.  We will have to wait to see how we can return
all three numbers.

## Recursion

Functions may call themselves, as demonstrated by the following code which
calculates Fibonacci numbers.  The Nth fibonacci number is defined the be the
sum of the (N-1)th fibonacci number and the (N-2)th fibonacci number.  The 0th
and 1st fibonacci numbers are defined to be 1.  These are the "base case" for
the `fib` function meaning they are not in terms of other values, and all other
values can be computed from these.

```c
// snippets/fibonacci.c
#include <stdio.h>

int fib(n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return fib(n-1) + fib(n-2);
    }
}

int main() {
    int result;
    int n;
    for (n = 0; n <= 15; n++) {
        result = fib(n);
        printf("fib(%d) = %d\n", n, result);
    }
}
```


```
fib(0) = 1
fib(1) = 1
fib(2) = 2
fib(3) = 3
fib(4) = 5
fib(5) = 8
fib(6) = 13
fib(7) = 21
fib(8) = 34
fib(9) = 55
fib(10) = 89
fib(11) = 144
fib(12) = 233
fib(13) = 377
fib(14) = 610
fib(15) = 987
```


## Interactive Example

Let's write a function that raises one number to the power of another.

## Scope Rules

The following is an excerpt from *The C Programming Language* on scope:

> The scope of a name is the part of the program within which the name can be
> used. For an automatic variable declared at the beginning of a function, the
> scope is the function in which the name is declared. Local variables of the
> same name in different functions are unrelated. The same is true of the
> parameters of the function, which are in effect local variables.

For example, note in the following example that there are two scopes for
`func` and `main`.  Even though they use the same variables name, `myVar`,
it has two distinct values in each scope.

```c
// snippets/scopebasic.c
#include <stdio.h>

int func()
{
    int myVar = 1;
    return myVar;
}

int main() {
    int myVar = 0;
    printf("%d\n", myVar);
    printf("%d\n", func());
    printf("%d\n", myVar);
}
```


```
0
1
0
```


## Global Variables

Functions can of course read and write variables that are defined interally but
they can also read and write *global* varialbes which are defined externally
These variables are also sometimes called *external* variables.  The rule
for external variable scope is given by *The C Programming Language* here:

> The scope of an external variable or a function lasts from the point at which
> it is declared to the end of the file being compiled.

The following examples demonstrates how this can be useful for keeping some
*state* in between calls.  The `countCalls` function returns the number of
times it has been called.

```c
// snippets/countcalls.c
#include <stdio.h>

int COUNTER = 0;

int countCalls() {
    COUNTER += 1;
    return COUNTER;
}

int main() {
    printf("%d\n", countCalls());
    printf("%d\n", countCalls());
    printf("%d\n", countCalls());
}
```


```
1
2
3
```


Another possible, though not necessarily recommended
use of global variables is as a way of returning 
multiple values from a computation.  For example,
consider the function for finding Pythagorean triples
demonstrated below.

```c
// snippets/returnextern.c
#include <stdio.h>

int A = 0;
int B = 0;
int C = 0;

void find_triple(int max) {
    int a, b, c;
    for (a = 1; a <= max; a++) {
        for (b = 1; b <= max; b++) {
            for (c = 1; c <= max; c++) {
                if (a*a + b*b == c*c) {
                    A = a;
                    B = b;
                    C = c;
                    return;
                }
            }
        }
    }
}

int main() {
    find_triple(13);
    printf("Triple: %d %d %d\n", A, B, C);
}
```


```
Triple: 3 4 5
```


External variables can also be useful for sharing
information between function without explicitly
passing it back and forth.  Consider this program
which implements functions to simulate the (X, Y)
position of something:

```c
// snippets/share.c
#include <stdio.h>

int X = 0;
int Y = 0;

void moveLeft() {X--;}
void moveRight() {X++;}
void moveUp() {Y++;}
void moveDown() {Y--;}

int main() {
    moveLeft();
    printf("Position: (%d, %d)\n", X, Y);
    moveUp();
    printf("Position: (%d, %d)\n", X, Y);
    moveRight();
    printf("Position: (%d, %d)\n", X, Y);
    moveDown();
    printf("Position: (%d, %d)\n", X, Y);
}
```


```
Position: (-1, 0)
Position: (-1, 1)
Position: (0, 1)
Position: (0, 0)
```


*Note on Style* Global variables are generally quite frowned upon for the cases
above because it makes the flow of larger programs much harder to follow.
However, it is generally okay to use global variables that are *read only*
meaning that you do not modify them.  For this purpose you should use the
`const` keyword as demonstrated below:

```c
// snippets/constglobal.c
#include <stdio.h>

const double EULERS_NUMBER = 2.7182818284590452;

int main() {
    printf("%g\n", EULERS_NUMBER);
}
```


```
2.71828
```


If you try to change it, you will get an error:

```c
// snippets/constglobalmodify.c
#include <stdio.h>

const double EULERS_NUMBERS = 2.7182818284590452;

int main() {
    EULERS_NUMBER = 3.14;
    printf("%g\n", EULERS_NUMBER);
}
```

```
gcc snippets/constglobalmodify.c
```

```
snippets/constglobalmodify.c:6:5: error: use of undeclared identifier 'EULERS_NUMBER'; did you mean 'EULERS_NUMBERS'?
    EULERS_NUMBER = 3.14;
    ^~~~~~~~~~~~~
    EULERS_NUMBERS
snippets/constglobalmodify.c:3:14: note: 'EULERS_NUMBERS' declared here
const double EULERS_NUMBERS = 2.7182818284590452;
             ^
snippets/constglobalmodify.c:6:19: error: cannot assign to variable 'EULERS_NUMBERS' with const-qualified type 'const double'
    EULERS_NUMBER = 3.14;
    ~~~~~~~~~~~~~ ^
snippets/constglobalmodify.c:3:14: note: variable 'EULERS_NUMBERS' declared const here
const double EULERS_NUMBERS = 2.7182818284590452;
~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
snippets/constglobalmodify.c:7:20: error: use of undeclared identifier 'EULERS_NUMBER'; did you mean 'EULERS_NUMBERS'?
    printf("%g\n", EULERS_NUMBER);
                   ^~~~~~~~~~~~~
                   EULERS_NUMBERS
snippets/constglobalmodify.c:3:14: note: 'EULERS_NUMBERS' declared here
const double EULERS_NUMBERS = 2.7182818284590452;
             ^
3 errors generated.

```



Note also that in all of these cases, the names of the global variables are
all capital.  This makes it easy to distinguish them from regular variables,
and you always follow this style.

## Static Variables

Static variables allow us to replicate some of the behavior of global variables
without the messiness of sharing involved.  Static variables let us store
information in a function permanently, rather than destroying it when the
function is over.  This example demonstrates how to use a static variable
to keep track of the number of times a function has been called wihtout using
a global variables:

```c
// snippets/countcallsstatic.c
#include <stdio.h>

int countCalls() {
    static int counter = 0;
    counter += 1;
    return counter;
}

int main() {
    printf("%d\n", countCalls());
    printf("%d\n", countCalls());
    printf("%d\n", countCalls());
}
```


```
1
2
3
```


You might think that assigning the value `0` to `counter` at the beginning of
the `countCalls` function would mean the value returned is always `1` and you
would be right if the variable wasn't declared as `static`.  However because
we used the `static` keyword, the value is stored forever and can be modified
and read later.
# Multiple File Programs

Now, while the examples we have looked at so far are small, programs in
the real world consist of thousands upon thousands of lines.  Not only
do individual programs consists of thousands of lines, but they may depend
upon other programs which have aleady been compiled.  This section will
show you how to deal with such cases in C.

## Including Other Files

It is quite simple to include other files in your C program.  Check out this
simple example:

```c
// snippets/multifile2.c
int add(int x, int y) {
    return x + y;
}
```

```c
// snippets/multifile1.c
#include <stdio.h>
#include "multifile2.c"

int main() {
    printf("%d\n", add(1, 2));
}
```

```
gcc snippets/multifile1.c -o multifile.out
```

```
$ ./multifile.out
3
```


Yes it turns out we have been doing it this whole time with `#include`!  You
will notice one difference between the `#include` we have been using and the
one we used to include our own file: angle brackets `<>` vs quotes `""`.  Using
quotes simply says to check our current directory for the file, and if nothing
is found, search same way `<>` would search (which is implementation defined).
So what does `#include` actually do?  It's actually extremely simple, it just
takes the contents of the file it finds, and puts it in place of the statement
just before compliation.  So if you are ever trying to figure out the effect of
a `#incldue` statement, just imagine copy pasting the file there instead.


## Including Already Compiled Files

Now, there are cases in which you want to use code but
not compile from the source directly

1. You do not want to spend time re-compiling old code
2. You do not have access to the source code

In either of these cases you will be using *object code* which is essentially
just code that has already been compiled.  To compile object code of a C
program, you can run `gcc filename.c -c` which by default produces a file with
name `filename.o` (`o` for object).  For example, you can run `gcc
snippets/multifile2.c -c` and you should see `multifile2.o` appear.

Now, how do we include this with our compilation of `snippets/multifile1.c`?
Lets try running: `gcc snippets/multfile3.c multifile2.o`

```c
// snippets/multifile2.c
int add(int x, int y) {
    return x + y;
}
```

```c
// snippets/multifile3.c
#include <stdio.h>

int main() {
    printf("%d\n", add(1, 2));
}
```

```
gcc snippets/multifile2.c -c
```

```
gcc snippets/multifile3.c multifile2.o -o multifile.out
```

```
snippets/multifile3.c:4:20: warning: implicit declaration of function 'add' is invalid in C99 [-Wimplicit-function-declaration]
    printf("%d\n", add(1, 2));
                   ^
1 warning generated.

```

```
$ ./multifile.out
3
```


Note that the only modification we made to the file was excluding the
`#include` since we are simulating a case in which we do not use the original
source code.  However now we get a nice big warning saying that `add` has not
been defined.  This is because the definition is not present anywhere in the
source code we have.  Now you might go ahead and ingore the warning, and if you
run the resulting file, you may even get the right result!

However, warnings are there for a reason, and you should almost never ignore
them.  Check the *Function Prototypes* section of the last session to
understand this particular warning's danger.

Now, you first gut reaction to this warning may be to put the prototype in
the file we are compiling like so:

```c
// snippets/multifile2.c
int add(int x, int y) {
    return x + y;
}
```

```c
// snippets/multifile4.c
#include <stdio.h>

int add(int x, int y);

int main() {
    printf("%d\n", add(1, 2));
}
```

```
gcc snippets/multifile2.c -c
```

```
gcc snippets/multifile4.c multifile2.o -o multifile.out
```

```
$ ./multifile.out
3
```


And this will work!  However you should consider ahead of time that this
will become tedious especially if there are multiple files that depend on
this object code, or if you are giving object code to someone, they probably
don't want to copy paste your prototypes everywhere they use your code.  This
is where *header files* come in.

A header file isn't a special file format, it is regular C code.  However, it
is an agreed upon good practice.  A header should generally only include
function definitions, as in the next iteration of our example shows below:

```c
// snippets/addition.h
int add(int x, int y);
```

```c
// snippets/addition.c
int add(int x, int y) {
    return x + y;
}
```

```c
// snippets/properheader.c
#include <stdio.h>
#include "addition.h"

int main() {
    printf("%d\n", add(1, 2));
}
```

```
gcc snippets/addition.c -c
```

```
gcc snippets/properheader.c addition.o -o properheader.out
```

```
$ ./properheader.out
3
```


## Scope Rules in Multiple Files

Now let's think about what happens to our old global variables in this new
system of multiple files.  We said earlier that you can think of the `#include`
statement as simply copy pasting the file, so a global variable in the first
file will become a global variable in the result.  But what happens when we
first compile an external file and then use the global?  Let's consider two
cases:

1. We *declare* the variable but do not *initialize* it.  You can think of this
as declaring a function but not defining it (a function prototype)

```c
// snippets/sine.c
#include <math.h>

const double PI = 3.14159265359;

double sinDegrees(double x) {
    return sin((PI / 180) * x);
}
```

```c
// snippets/globalmulti.c
#include <stdio.h>

const double PI;
double sinDegrees(double x);

int main() {
    printf("%g\n", sinDegrees(45));
    printf("%g\n", PI);
}
```

```
gcc snippets/sine.c -c
```

```
gcc snippets/globalmulti.c sine.o -o globalmulti.out
```

```
$ ./globalmulti.out
0.707107
3.14159
```


In this case, the value is pulled from the compiled code just fine.

2. We *declare* the variable **and** *initialize* it.

```c
// snippets/sine.c
#include <math.h>

const double PI = 3.14159265359;

double sinDegrees(double x) {
    return sin((PI / 180) * x);
}
```

```c
// snippets/globalmultiinit.c
#include <stdio.h>

const double PI = 3.14159265359;
double sinDegrees(double x);

int main() {
    printf("%g\n", sinDegrees(45));
    printf("%g\n", PI);
}
```

```
gcc snippets/sine.c -c
```

```
gcc snippets/globalmultiinit.c sine.o -o globalmultiinit.out
```

```
duplicate symbol '_PI' in:
    /var/folders/wl/lfwxtbp53l7c1fcchd3w__cc0000gr/T/globalmultiinit-412c99.o
    sine.o
ld: 1 duplicate symbol for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)

```



In this case, it is as if we have declared the variable twice which is not
allowed!  This can grow troublesome if we are using a lot of external code
and we accidentally use their global variables.  A way of protecting against
this is using the *static* keyword in the original code, which hides the
variable from future users.

```c
// snippets/sinestatic.c
#include <math.h>

static const double PI = 3.14159265359;

double sinDegrees(double x) {
    return sin((PI / 180) * x);
}
```

```c
// snippets/globalmultiinit.c
#include <stdio.h>

const double PI = 3.14159265359;
double sinDegrees(double x);

int main() {
    printf("%g\n", sinDegrees(45));
    printf("%g\n", PI);
}
```

```
gcc snippets/sinestatic.c -c
```

```
gcc snippets/globalmultiinit.c sinestatic.o -o globalmultiinit.out
```

```
$ ./globalmultiinit.out
0.707107
3.14159
```


Now, since the original `PI` is hidden and unusable, we can declare a new one
and use it as we please.


## Block Structure

In general, code inside curly braces `{}` may initialize new variables, even if
they have the same name as variables outside of the braces.  Consider this
example which only uses one variable name `i` but assigns it many different
values.

```c
// snippets/block.c
#include <stdio.h>

int main() {
    {
        int i = 5;
        printf("%d\n", i);
    }
    {
        double i = 3.14;
        printf("%g\n", i);
        {
            char i = 'i';
            printf("%c\n", i);
        }
        printf("%g\n", i);
    }
}
```

```
gcc snippets/block.c -o block.out
```

```
$ ./block.out
5
3.14
i
3.14
```


Note that if you try to defined a variable with the same name as one in the
outer scope after using it in the block, you will get a compiler error as
demonstrated here.

```c
// snippets/badblock.c
#include <stdio.h>

int main() {
    {
        int i = 5;
        printf("%d\n", i);
    }
    {
        double i = 3.14;
        printf("%g\n", i);
        {
            printf("%c\n", i);
            char i = 'i';
        }
        printf("%g\n", i);
    }
}
```

```
gcc snippets/badblock.c -o badblock.out
```

```
snippets/badblock.c:12:28: warning: format specifies type 'int' but the argument has type 'double' [-Wformat]
            printf("%c\n", i);
                    ~~     ^
                    %f
1 warning generated.

```



*Note on design* While you can use the same name as variables in the outer
scope, it is generally unwise and likely to cause confusion.

## Macro Substitution

Macro substitution allows you to define a piece of replacement text for text in
your code.  You can do this with the `#define` statement.  This statement is
similar to `#include` in that it essentially copy-pastes code but it does have
a few caveats that make it dangerous.

For example, the macro demonstrated below lets you write `forever` instead of
`while (1)` to create an infinite loop.

```c
// snippets/forevermacro.c
#include <stdio.h>

#define forever while (1)

int main() {
    int i = 0;
    forever {
        if (i < 3) {
            i++;
            printf("%d\n", i);
        } else {
            break;
        }
    }
}
```

```
gcc snippets/forevermacro.c -o forevermacro.out
```

```
$ ./forevermacro.out
1
2
3
```


You can also define macros similar to functions which take multiple values:

```c
// snippets/multimacro.c
#include <stdio.h>

#define max(A, B) ((A) > (B) ? (A) : (B))

int main() {
    int i = 0;
    int j = 0;
    int m = max(++i, ++j);
    printf("%d %d %d\n", i, j, m);
}
```

```
gcc snippets/multimacro.c -o multimacro.out
```

```
$ ./multimacro.out
1 2 2
```


Hmm, that's strange...

Because the macro is a simple copy paste, the line `int m = max(++i, ++j)`
is equivalent to `int m = (++i) > (++j) ? (++i) : (++j))` and the increment
is applied once before `?` and once after, resulting in a value of `2`.

The copy-paste nature of `#define` can also lead to unexpected results when
taking into account precedence:

```c
// snippets/precedencemacro.c
#include <stdio.h>

#define square(x) x * x

int main() {
    int s = square(3 + 1);
    printf("%d\n", s);
}
```

```
gcc snippets/precedencemacro.c -o precedencemacro.out
```

```
$ ./precedencemacro.out
7
```

