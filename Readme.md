<h1>Project structur</h1>

```
/push_swap         (root project folder)
    |
    |____/bin        (the final executable file)
    |
    |___/include     (header files, .h)
    |
    |____/src        (source files, .c)
    |
    |____/obj        (where the generated .o files will be)
    |
    |____/lib        (any library dependences)
    |
    |____Makefile    (make instructions file)
    |
    |____README      (general readme of the project)
    |
    |___/bonus
        |
        |____/bin        (the final executable file)
        |
        |___/include     (header files, .h)
        |
        |____/src        (every source file, .c and .c)
        |
        |____/obj        (where the generated .o files will be)
        |
        |____/lib        (any library dependences)
        |
        |____Makefile    (make instructions file)
```
<h1>Usage</h1>

<h3>Mandatory part</h3>

open a terminal window in the project directory
~~~
$> make
~~~
for mandatory part you can execute commands like
~~~
$> bin/push_swap <random numbers>
~~~
replace the place holder \<numbers> with random numbers so the program displays needed instructions to sort this numbers like a stack using the help of another stack otherwise "Error" if their are any duplictae or no numeric caracters

<h3>bonus part</h3>

open a terminal window in the project directory
~~~
$> make bonus
~~~
for bonus part you have to make mandatory part and you can execute commands like
~~~
$> ARG="<random numbers>"; bin/push_swap $ARG | bonus/bin/checker $ARG
~~~
the program will display "OK" if the stack sorted with thos instructions otherwise print "KO" or "Error" if their  any duplictae or no numeric caracters

<h3>Cleaning</h3>

to delete object file
~~~
$> make clean
~~~

to delete object files and executable files

~~~
$> make fclean
~~~
