# Option 1
## Creation of the library
### Compile the files to include in the library
- gcc -c -fpic main.c -o main.out
### Make a library with those files
- gcc -shared -o mylib.so main.out
## Incorporation of the library in another program
- gcc ex3.c -o ex3.out -L. mylib.so -lcurl -ljansson -Wl,-rpath,"/media/sf_C-language-and-Assembly/Exams and assignments/Trabalhos/2022inv-FORDALASTIME/T3"
## Execution
- ./ex3.out

# Inspect the contents
- nm mylib.so (dump the symbol table and their attributes from a binary executable file)

# Note
- -fpic -> Makes code position independent so it can be loaded in any place of the ram at runtime
- Add -g to enable debug. And then run like `insight ex4.out`

# Referencias
- pdf 8 - biblotecas, prof Ezequiel
- https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html