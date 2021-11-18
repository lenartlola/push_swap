# ft_printf
## Final result: [![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/hsabir/ft_printf)](https://github.com/JaeSeoKim/badge42)
##### Because putnbr and putstr aren’t enough...

###### ft_printf is a project at 42, in which we had to recode the standard printf function from the stdio library. The goal of this project is not only recreating the wheel, but learning about [Variadic Functions](https://en.wikipedia.org/wiki/Variadic_function#In_C), and improving algorithmic methodology.

## Table of Contents
1. [The subject](#The-subject)
2. [The bonus part](#The-bonus-part)
3. [Implementation](#Implementation)
4. [Build](#Build)
5. [How does it work?](#How-does-it-work?)

## The subject
You have to recode the libc’s printf function, It must not do the buffer management like the real printf, It will manage the following conversions specifiers: cspdiuxX%.

We can solve the printf problem by abstracting it. But first, we have to learn and understand how printf actually works.
Here is a template of printf, it can respectevly take all this informations.
```sh
%[flag][min-width].[precision][length modifier][conversion specifier]
```

But only by looking at the template and thinking about solving it, I can tell that I have to take care about the flag, width, precision and the length modifier before the specifiers. But it was actually in the bonus part without me knowing it, so looking at the bonus part later in the pdf, it did actually tell us: `If you plan to do bonuses you should think about how to do them from the beginning to avoid a naive approach.`
## The bonus part
 If the Mandatory part is not perfect don’t even think about bonuses. Manage any combination of the following flags: ’-0.’ and minimum field width
with all conversions, Manage all the following flags: ’# +’ (yes, one of them is a space).
And if we focus enough we'll see a big note!


 I used to reference to these two great resources, to understand better the nature of printf in detail: [cpp reference of printf](https://www.cplusplus.com/reference/cstdio/printf/), [Secrets of “printf”](https://www.cypress.com/file/54441/download).
 
 As of course in order to play around these details, I did use the struct data type, so I can easily determine what flag or kind or information is set after the %.

## Implementation
For the sake of place in the diagram and time , I couln't put all the details, but here is a simple architecture of my implementation, the reste is all about our functions in [Libft](https://github.com/1mthe0wl/libft.git) with some adaptation, please refer to it in case of any questions.

![alt text](https://github.com/1mthe0wl/ft_printf/blob/main/ft_printf.png?raw=true)

## Build
The Makefile consists some basic and standard rules.

Create the library:
```sh
    make
```
Clean all the object files:
```sh
    make clean
```
Clean all the object and library files.
```sh
    make fclean
```
Recompile all:
```sh
    make re
```

## How does it work?
First, build the library then include it into your project.
```
    #include "ft_printf.h"
```
The way it works is way too similiar to the actuall printf, though it does not the buffer management. And I did Manage only the combination of the following flags: ’-0.’ and minimum field width.
``` Note that it does not work properly with the following flags: ’# +’ ```, though it is not really that complicated to implement at this point, but again ``` TIME ```.
 
[![forthebadge](https://forthebadge.com/images/badges/made-with-crayons.svg)](https://forthebadge.com)[![forthebadge](https://forthebadge.com/images/badges/powered-by-coffee.svg)](https://forthebadge.com)[![forthebadge](https://forthebadge.com/images/badges/built-by-codebabes.svg)](https://forthebadge.com)[![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)[![forthebadge](https://forthebadge.com/images/badges/fuck-it-ship-it.svg)](https://forthebadge.com)
