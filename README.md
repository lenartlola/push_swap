# push swap

The goal of this project is to sort data on a **stack**, with a limited set of operations, using the lowest possible number of instructions.

## Subject resume:

The project is simple and highly straightforward algorithm project, data must be sorted.

We are allowed to use at most two stack and manipulate them using a limited set of operations in order to sort a range of integers.

## The rules of the game:
 - Implement 2 **stacks** named **a** and **b**.
 - At the beginning:
   * The **stack a** contains a random amount of negative and/or opsetive numbers which cannot be duplicated.
   * The **stack b** is empty.
 - The allowed operations are as followings
   * *sa* (swap a): Swap the first 2 elements at the top of **stack a**.
   * *sb* (swap b): Swap the first 2 elements at the top of **stack b**.
   * *ss* : Do *sa* and *sb* at the same time.
   * *pa* (push a): Take the first element at the top of **stack a** and put on the top of **stack b**.
   * *pb* (push b): Take the first element at the top of **stack b** and put on the top of **stack a**.
   * *ra* (rotate a): Take the first element at the top of **stack a** and put at the bottom.
   * *rb* (rotate b): Take the first element at the top of **stack b** and put at the bottom.
   * *rr* : Do *ra* and *rb* at the same time.
   * *rra* (reverse rotate a): Take the element at the bottom of **stack a** and put on the top.
   * *rrb* (reverse rotate b): Take the element at the bottom of **stack b** and put on the top.
   * *rrr* : Do *rra* and *rrb* at the same time.
 - The limited instructions are as followings
   * To sort 3 numbers, we should do in no more than 2 instructions.
   * To sort 5 numbers, we should do in no more than 12 instructions
   * To sort 100 numbers, points are as followings
     - less than 700 instructions -> 5 points.
     - between 700 - 900 instructions -> 4 points.
     - between 900 - 1100 instructions -> 3 points.
     - between 1100 - 1300 instructions -> 2 points.
     - between 1300 - 1500 instructions -> 1 point.
   * To sort 500 numbers, points are as followings
     - less than 5500 instructions -> 5 points.
     - between 5500 - 7000 instructions -> 4 points.
     - between 7000 - 8500 instructions -> 3 points.
     - between 8500 - 10000 instructions -> 2 points.
     - between 10000 - 11500 instructions -> 1 point.

## Illustrated operations:

Figure(1):
```
  Stacks at init       Stacks after "pb", "pb"   Stacks after "pb", "pb"
        ^                         ^                       ^
+-------+                         |                       |
|  42   |                         |                       |
|  20   |               +-------+                +-------+
|  178  |               |  178  |                |  178  |
|   1   |               |   1   | +-------+      |   1   | +-------+
|  99   |               |  99   | |  20   |      |  99   | |  20   |
|   8   |               |   8   | |  42   |      |   8   | |  42   |
+-------+ +-------+     +-------+ +-------+      +-------+ +-------+
|Stack a| |Stack b|     |Stack a| |Stack b|      |Stack a| |Stack b|
+-------+ +-------+     +-------+ +-------+      +-------+ +-------+

Stacks after "sa"    Stacks after "sb"     Stacks after "ss"
         ^                    ^                     ^
         |                    |                     |
         |                    |                     |
+-------+            +-------+             +-------+
|   1   |            |   1   |             |  178  |
|  178  | +-------+  |  178  | +-------+   |   1   | +-------+
|  99   | |  20   |  |  99   | |  42   |   |  99   | |  20   |
|   8   | |  42   |  |   8   | |  20   |   |   8   | |  42   |
+-------+ +-------+  +-------+ +-------+   +-------+ +-------+
|Stack a| |Stack b|  |Stack a| |Stack b|   |Stack a| |Stack b|
+-------+ +-------+  +-------+ +-------+   +-------+ +-------+

 Stacks after "ra"    Stacks after "rb"     Stacks after "rr"
         ^                    ^                     ^
         |                    |                     |
         |                    |                     |
+-------+            +-------+             +-------+
|   1   |            |   1   |             |  99   |
|  99   | +-------+  |  99   | +-------+   |   8   | +-------+
|   8   | |  20   |  |   8   | |  42   |   |  178  | |  20   |
|  178  | |  42   |  |  178  | |  20   |   |   1   | |  42   |
+-------+ +-------+  +-------+ +-------+   +-------+ +-------+
|Stack a| |Stack b|  |Stack a| |Stack b|   |Stack a| |Stack b|
+-------+ +-------+  +-------+ +-------+   +-------+ +-------+

 Stacks after "rra"   Stacks after "rrb"    Stacks after "rrr"
         ^                    ^                     ^
         |                    |                     |
         |                    |                     |
+-------+            +-------+             +-------+
|   1   |            |   1   |             |   1   |
|  99   | +-------+  |  99   | +-------+   |  99   | +-------+
|   8   | |  20   |  |   8   | |  42   |   |   8   | |  42   |
|  178  | |  42   |  |  178  | |  20   |   |  178  | |  20   |
+-------+ +-------+  +-------+ +-------+   +-------+ +-------+
|Stack a| |Stack b|  |Stack a| |Stack b|   |Stack a| |Stack b|
+-------+ +-------+  +-------+ +-------+   +-------+ +-------+

                    Stacks after "pa", "pa"
                            ^
                    +-------+ 
                    |  42   |
                    |  20   |
                    |   1   |
                    |  99   |
                    |   8   |
                    |  178  |
                    +-------+ +-------+
                    |Stack a| |Stack b|
                    +-------+ +-------+

```

## Approach:

**A word about recursion**
Before diving deeper, let's take a little overview about recursion and how stack frames look like in C,
I think it's a crucial part to understand in order to avoid further problems.

It's all about stack frames, whenever you call a function there's a stack frame poping up, holding all the information
about the function including the return address of where it should return and continue whe the function call ends.
I don't go into detail about it, but there are great information under the hood if you want to learn more check out
this great paper about [Calling conventions and stack layout](https://www.cs.cornell.edu/courses/cs4120/2020sp/lectures/18callconv/lec18-sp18.pdf)

For instance that's how a stack frame may look like:

Figure(2)
```
+--------------------+
|  Some_function()   |
|                    |
|  some_variable     |
|  another_variable  |
|         .          |
|         .          |
|         .          |
|         .          |
|  Some_logics       |
|  return_address    |
+--------------------+
```

*Be aware the return address is not the same as the return value of a function in C-like programs but rather the address
of where it was just before the function call in order to the program know where to re-start its execution.*

Let's break it down with some examples.

Let's take as example this pseudocode and illustrate the stack frames:

```c
function(index):
    index++;
    if index is 5
        break;
    function(index);
    return;

main_function():
    index = 0;
    function(index);
```

Let's see how each frame looks like.

The first and Initial frame:

Figure(3)
```
     +---------------------+
     | main_function()     |
     |                     |
     | index = 0           |
     |                     |
 +---+-function(index = 0) |
 |   |                     |
 |   | return <------------+---+
 |   +---------------------|   |
 |   +---------------------+   |
 +-->| function(index = 0) |   |
     |                     |   |
     | index++;            |   |
     |                     |   |
     | if index is 5       |   |
     |                     |   |
     |    break;           |   |
     |                     |   |
 +---+-function(index = 1) |   |
 |   |                     |   |
 |   | return  <-----------+---+
 |   +---------------------|   |
 |   +---------------------+   |
 +-->| function(index = 1) |   |
     |                     |   |
     | index++;            |   |
     |                     |   |
     | if index is 5       |   |
     |                     |   |
     |    break;           |   |
     |                     |   |
 +---+-function(index = 2) |   |
 |   |                     |   |
 |   | return  <-----------+---+
 |   +---------------------|   |
 |   +---------------------+   |
 +-->| function(index = 2) |   |
     |                     |   |
     | index++;            |   |
     |                     |   |
     | if index is 5       |   |
     |                     |   |
     |    break;           |   |
     |                     |   |
 +---+ function(index = 3) |   |
 |   |                     |   |
 |   | return  <-----------+---+
 |   +---------------------|   |
 |   +---------------------+   |
 +-->| function(index = 3) |   |
     |                     |   |
     | index++;            |   |
     |                     |   |
     | if index is 5       |   |
     |                     |   |
     |    break;           |   |
     |                     |   |
 +---+-function(index = 4) |   |
 |   |                     |   |
 |   | return  >-----------+---+
 |   +---------------------|   |
 |   +---------------------+   |
 +---+ function(index = 4) |   |
     |                     |   |
     | index++;            |   |
     |                     |   |
     | if index is 5       |   |
     |                     |   |
     |    break;           |   |
     |                     |   |
+----+ function(index = 5) |   |
|    |                     |   |
|    | return  <-----------+---+
|    +---------------------|   |
|    +---------------------+   |
+--->| function(index = 0) |   |
     |                     |   |
     | index++;            |   |
     |                     |   |
     | if index is 5       |   |
     |                     |   |
     |    break;  ---------+---+
     +---------------------+
```

As you can see each frame has its own variables, one the recursion function reaches the specified condition it breaks
and return to where it was in the last frame.

**Why even bother with all that?**

That's a good question, I have based my algorithm to solve the push_swap problem on quicksort which in turn is based
on recursion, let's see how a simple quicksort breaks the problem down.

For the case of three and five, I can actually do it manually which was a good exercise to better understand the project,
and test my operations functions.
So I wrote an algorithm for three and for the case of five I just put two elements in the **stack b** then apply
the three algorithm and then push back the elements from **stack b** into the **stack a**.

The three and five cases was pretty easy the real challenge begun for bigger numbers,
we want an algorithm whose complexity remains constant despite a potentially increasing number of elements.
It is important as it'll make our algorithm more reliable and whose potential usefulness is greater than most algorithm.  

Here is the idea, find two pivots in the **stack a**, a **median** and a **median of median**.

``` mathematics
median = biggest number in stack a / 2

median_of_median = median / 2
```

The idea is to separate the **stacks** into three chunks in each stack frame, let's say `big, medium, small` for instance
(The ideal result is shown in figure(4)), and doing it repeatedly until we reach a condition where the **stack a** 
contains only `5` or `3` or under `3` elements, once it reaches this condition then we call the manual algorithms 
which I discussed above to sort the rest, and then return to the last frame and do something similar 
in the reverse order (More on it later).

Figure(4):
```
   Stack a      Stack b           
  +---------+  +---------+        
  |   xxx   |  |   xxx   |        
  |   xxx   |  |   xxx   |        
  |   xxx   |  |  medium |        
  |   xxx   |  |   xxx   |        
  |   xxx   |  |   xxx   |        
  |   Big   |  +---------+        
  |   xxx   |  |   xxx   |
  |   xxx   |  |   xxx   |
  |   xxx   |  |  Small  |
  |   xxx   |  |   xxx   |
  |   xxx   |  |   xxx   |
  +---------+  +---------+
```

***Some technical details:***

`When I solved this problem I have encountered some problems, I had to initialise so many variables to track the state
of the stacks in each frame, there are probably better and smarter solutions, but I'm not bother fix it right now.`

* First of all, it was all difficult to sort the chunks in the **stack_b**, I came with an idea of checking
the pushed number if it's part of the medium chunk, if so I would rotate **stack_b** this way I have something similar
to the Figure(5), and I would track the number of rotation I do in order to reverse rotate the **stack_b** once I have
done with my loop (Not very smart I know xD), so I created a variable *rrb*, each time I rotate the **stack_b** 
I increment this variable to track the number of rotation I do, once reverse rotation is done I get the ideal result from the Figure(4).
One may ask `if we want medium chunk on the top of the stack_b` so why not directly rotate the small instead
of rotate medium and then reverse rotate it? sounds right, but believe me you will see in a second that would be more
problematic in the next stack frames.
* One key thing is to track the number of elements in the **stack_a** inside each frame, let's say for example we have
  100 initial elements, we know then that we push 50 elements to the **stack_b** and what is rest in the **stack_a** is
  50, I have created another variable to track this, everytime I rotate the **stack_a**, I increment this variable
  in order to have the right amount of the elements in the **stack_a**, I will then pass this variable to the function
  at each frame.


Figure(5):
```
   Stack a      Stack b           
  +---------+  +---------+        
  |   xxx   |  |   xxx   |        
  |   xxx   |  |   xxx   |        
  |   xxx   |  |  Small  |        
  |   xxx   |  |   xxx   |        
  |   xxx   |  |   xxx   |        
  |   Big   |  +---------+        
  |   xxx   |  |   xxx   |
  |   xxx   |  |   xxx   |
  |   xxx   |  |  Medium |
  |   xxx   |  |   xxx   |
  |   xxx   |  |   xxx   |
  +---------+  +---------+
```

Here is a pseudocode:
``` c
Step(1)
a_to_b(stacks, size_of_stack):
    if sizeof(stack_a) is 5 or sizeod(stack_a) is 3 or sizeof(stack_a) is smaller than 3
        sort_stack_a_manually(stacks);
    find_pivots(stack_a);
    while stack_a:
        if the current element in the stack_a us bigger than median:
            rotate_stack_a(stack_a);
        else:
            push_to_stack_b(stacks);
            if the pushed number is bigger than the median of median:
                rotate_stack_b(stack_b);
    Step(2)
    while tracker--
        reverse_rotate_stack_b(stack_b);
    a_to_b(stacks, number_rotate_stack_a);
```


Figure(6):
```
+--------------------------------------------------------+
|                                                        |
|  Stack a contains rondom numbers:                      |
|            +--------+                                  |
|            |  xxxx  |                                  |
|            |  xxxx  | Biggest number somewhere / 2     |
|            |  xxxx  |                                  |
|            |  xxxx  |             ^                    |
|            |  xxxx  |             |                    |
|            |  xxxx  |             |                    |
|            |  xxxx -+-------------+                    |
|            |  xxxx  |                                  |
|            |  xxxx  |                                  |
|            |  xxxx  |                                  +--------+
|            |  xxxx  |                                  |        |
|            |  xxxx  |                                  |        |
|            |  xxxx  |                                  |        |
|            |  xxxx  |                                  |        |
|            |  xxxx  |                                  |        |
|            |  xxxx  |                                  |        |
|            |  xxxx  |                                  |        |
|            |  xxxx  |                                  |        |
|            |  xxxx  |                                  |        |  Becomes something like this
|            |  xxxx  |                                  |        |
|            |  xxxx  |                                  |        |
|            +--------+                                  |        |
|                                                        |        |
+--------------------------------------------------------+        |
                                                                  |
                                                                  |
+--------------------------------------------------------+        |
| Step(1)                      Step(2)                   |        |
|    Stack a      Stack b         Stack a      Stack b   |        |
|  +---------+  +---------+     +---------+  +---------+ |        |
|  |   xxx   |  |   xxx   |     |   xxx   |  |   xxx   | |        |
|  |   xxx   |  |   xxx   |     |   xxx   |  |   xxx   | |        |
|  |   xxx   |  |  Small  |     |   xxx   |  |  Middle | |        |
|  |   xxx   |  |   xxx   |     |   xxx   |  |   xxx   | |        |
|  |   xxx   |  |   xxx   |     |   xxx   |  |   xxx   | |        |
|  |   Big   |  +---------+     |   Big   |  +---------+ |        |
|  |   xxx   |  |   xxx   |     |   xxx   |  |   xxx   | |<-------+
|  |   xxx   |  |   xxx   |     |   xxx   |  |   xxx   | |
|  |   xxx   |  |  Middle |     |   xxx   |  |  Small  | |
|  |   xxx   |  |   xxx   |     |   xxx   |  |   xxx   | |
|  |   xxx   |  |   xxx   |     |   xxx   |  |   xxx   | |
|  +---------+  +---------+     +---------+  +---------+ |
|                                                        |
+--------------------------------------------------------+
```

That's what we get after the first function call, two equal stacks, one contains all the big numbers, the other one
separated by two partially sorted chunks. We will then recall the same function to the rest of the **stack_a** and
do the same logic on it (Note that the two partially sorted chunks would stay in the last stack frame, we won't be able
to modify them which is a great news because we come back to them in the right time).

Figure(7):

```
    Step(1)                                                           Step(2)

             +----------+ ---------+                                          +----------+ ---------+
             |          |          |                                          |          |          |
             | Second   |          |                                          |  Second  |          |
             | Frame    |          |                                          |  Frame   |          |
             |          |          | From the current frame call              |          |          |
             | Small    |          |                                          |  Big     |          |
             |          |          |                                          |          |          |
             +----------+ ---------+                                          +----------+          | From the current frameall
             |          |          |                                          |          |          |
             | First    |          |                                          |  Second  |          |
             | Frame    |          |                                          |  Frame   |          |
             |          |          |                                          |          |          |
             | Big      |          |                                          |  Small   |          |
             |          |          |                                          |          |          |
             +----------+          | From the last frame call                 +----------+ ---------+
             |          |          |                                          |          |          |
             | First    |          |                                          |  First   |          |
             | Frame    |          |                                          |  Frame   |          |
             |          |          |                                          |          |          |
             | Small    |          |                                          |  Big     |          |
             |          |          |                                          |          |          |
+----------+ +----------+ ---------+                             +----------+ +----------+          | From the last frame ca
|          | |          |          |                             |          | |          |          |
|  Second  | | Second   |          |                             |  Second  | |  First   |          |
|  Frame   | | Frame    |          |                             |  Frame   | |  Frame   |          |
|          | |          |          | From the current frame call |          | |          |          |
|  Big     | | Big      |          |                             |  Big     | |  Small   |          |
|          | |          |          |                             |          | |          |          |
+----------+ +----------+ ---------+                             +----------+ +----------+ ---------+
```


**So now what?** I don't know just do it until you reach the condition, and then we would do some similar process in the
reverse order.

TODO: write reverse process pseudo...

## Data structures

To implement the stacks, we have some choices, we cam with either an array of integer or a linked list, for me it was more reasonable to use a linked list, because we are working on dynamic stacks so we need dynamic structures.

I myself used a doubly linked list, because I find it easier to work on.

Struct diagram:
<p align="center">
  <img width="80%" src="https://github.com/ioscreams/push_swap/blob/main/diagrams/struct.png">
</p>

## Analyze of the complexity:
TODO

## Visualizer:
TODO
