# ft_printf

## What are  variadic functions?
Variadic functions are functions that take in a fixed parameter and any number of arguments, they can be prototyped like so:
> 'return_type	name(fixed_arg, ...);'


## How do they work?

### A few new things are needed:
- va_list variable: stores arguments, pointer to a struct which holds the elements of the variadic function
- va_start function: takes va_list + fixed parameter of function as parameters and initializes va_list
- va_arg: takes va_list variable + its desired return type and it moves to the next element of va_list and returns it as type
- va_copy:(copied from man) The va_copy() macro copies the state of the variable argument list, src, previously initialized
     by va_start(), to the variable argument list, dest, which must not have been previously
     initialized by va_start(), without an intervening call to va_end().  The state preserved in dest
     is equivalent to calling va_start() and va_arg() on dest in the same way as was used on src.  The
     copied variable argument list can subsequently be passed to va_arg(), and must finally be passed
     to va_end() when through with it.
- va_end: takes va_list variable and marks the last variadic variable was taken into account
- "stdarg" library

### How is va_list arg a pointer but takes no star?
va_list is a type defined in the strdag library. It is tipically declared as a pointer to struct, which holds information about the arguments passed to the variadic function.Therefore it is already defined as a pointer, which makes it possible for us to declare it as:
> 'va_list	ap;'

Which means there is now a va_list type variable, which is a pointer to a struct containing the variable arfuments.

### What about the 4 va_function macros?
va_list, va_arg, va_copy and va_end are functions which take va_list as input  and enable us to interact with the struct it points to.
They're prototyped as follows:
va_start
> 'void	va_start(va_list ap, fixed_arg);'

va_arg
> 'type	va_arg(va_list ap, type);'

va_copy
> 'void	va_copy(va_list dest, va_list src);'

va_end
> 'void	va_end(va_list ap);'

Note: By convention, the va_list is called ap, which refers to argument pointer.
## Alright, what about printf now?

### What is it?
The printf function produces output according to a format, it returns the number of characters it printed (excluding nulls). It is a variadic function, which as we've seen can take a variable number of arguments, of different data types.
It is prototyped as follows:
> 'int	printf(const char	*format, ...);'

### Requirements
- Deal with the following conversions: &c (single char), %s (string of chars), %p (argument of void* in hexadecimal form), %d (base 10 decimal, int), %i (base 10 nb, int), %u (unsigned decimal number), %x (number in hexadecimal form with lowercase), %X (number in hexadecimal form with uppercase), %% (percentage sign)
- no need to deal with buffers
- library has to be called libftprintf.a/h
- (if doing bonus part): deal with all different combinations of using the "-O" flag and min width of field for every conversion
- (if doing bonus part): deal with the following flags — "#", " ", "+"
### How will we implement ft_printf?
in the following example:
> 'ft_printf("%d, %c", 42, n);'

"%d, %c" is the fixed variable — the const char * , which is a string of characters to be printed to the standard output, with specific data types where format specfiers figure. 
42 and n are the variable arguments, which are the variables that the format specifiers refer to and replace within the string.
 
1. implement necessary auxiliary functions and utilities
2. itterate through the input string and check each character individually
3. if it is not a string format specifier, print it to the standard output
4. if it is a string format specifier, do the needed conversions and print it to the standard outpu
5. return the number of characters printed
