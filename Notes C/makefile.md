make file format is .mk

Even if the file is named "makefile" but with the file format specified with .mk, when trying to run in the conssole `$ make`, it will not work. Only if the file is named "makefile" or "Makefile" or "GNUmakefile" AND with **no file format** it will run.

If you put in the file format. Run like
```
make -f makefile.mk
```

Makefile example to compile multiple programs separately. Makes multiple .out file for each .c file
```makefile
output: ex1 ex2 ex3 ex4 ex5

ex1: ex1.c
	gcc ex1.c -o ex1.out

ex2: ex2.c
	gcc ex2.c -o ex2.out

ex3: ex3.c
	gcc ex3.c -o ex3.out

ex4: ex4.c
	gcc ex4.c -o ex4.out

ex5: ex5.c
	gcc ex5.c -o ex5.out

```

## Sources
- https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
- https://www.dummies.com/computers/operating-systems/linux/linux-how-to-run-make/
- https://stackoverflow.com/questions/5950395/makefile-to-compile-multiple-c-programs~
- https://www.thegeekstuff.com/2010/08/make-utility/
- https://makefiletutorial.com/