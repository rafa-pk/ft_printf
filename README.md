# ft_printf

## What are  variadic functions?
Variadic functions are functions that take in a fixed parameter and any number of arguments, they can be prototyped like so:
> return_type	name(fixed_arg, ...);


## How do they work?
A few new things are needed:
- va_list variable: stores arguments
- va_start function: takes va_list + fixed parameter of function as parameters and initializes va_list
- va_arg: takes va_list variable + its desired return type and it moves to the next element of va_list and returns it as type
- va_copy: 
- va_start: takes va_list variable and marks the last variadic variable was taken into account
- "stdarg" library

