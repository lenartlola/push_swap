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

For the case of three and five, I can actually do it manually wich was a good exercise to better understand the project. So I wrote an algorithm for three and for the five I just put two elements in the **stack b** then apply the three algorithm and then push back the elements from **stack b** into the **stack a**.

The three and five cases was pretty easy the real challenge begun for bigger numbers, we want an algorithm whose complexity remains constant despite a potentially increasing number of elements. It is important as it'll make our algorithm more reliable and whose potential usefulness is greater than most algorithm.  

After analyzing a bit the existing algorithms I soon realized that the quick sort idea would be a good fit.
So I based my algorithm on the top of said algorithm.

The idea is to find two pivots in the stack a, one in the middle and one middle of middle,

``` mathematics
middle = biggest number in stack a / 2

middle of middle = middle / 2
```
This way we can separate our stack a by three different chunks, there is the pseudo code of my algorithm:

``` c
Step(1)
recursively iterate on stack a
    if the remaining elemnt in stack a is 5 or three or under three
        sort_five/three;
    find the pivots;
    if the current element is bigger than the middle pivot
        do ra;
    else
        do pb;
        if the current elemnt is bigger than the number at the middle of the middle pivot
            do rb;
            increment a tracker;

Step(2)
while tracker--
    do rrb;
```

Those moves gives us something like this:

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

Then as illustrated in the pseudocode, we continue doing this recursively, until we get 5, 3 or under three elements.

This way we first work on and sort chunks of different sizes, then we can work more easily on the elements of these chunks.

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
