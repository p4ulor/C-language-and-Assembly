## Contents:
1. Problem/exercice solving, quick programs, notes, assignments done in college, etc.
2. Some explanations of some topics, since most stuff is already out there on the internet. I will also not explain or go too much into detail on little concepts that are pretty uniform between languages, like if's else's, order or priority of math operations, incrementations, decrementations, etc
3. This repo still has a lot tasks to complete (but I will very likely leave it as it is)

**Don't take my statements for granted. I might be wrong, if so, please correct me. I had a hard time learning this curricular subject in college. I understand it's importance, but currently I prefer to learn other things**

## About the C language
- Middle-High level language. Since you have more control over memory allocation and you can join high-level code with low-level code to compile
- Simple, efficient and has a wide range of [applications](https://data-flair.training/blogs/applications-of-c/)
- You can handle/edit memory addresses (through pointers) more easily
- It can work along with Assembly language (it allows manipulations of internal processor registers per example)
- C is not portable because it compiles to a specific hardware architecture once it has been compiled. Unlike Java, since it uses the JVM to handle how the binary output is ran for the current computer
- Created in 1972
- It's an important language to know, since it's very popular and has influenced the design of other languages
- It's mostly a procedural language([unlike](https://softwareengineering.stackexchange.com/questions/113533/why-is-c-not-considered-an-object-oriented-language) its successor: C++, which makes it easier to apply object oriented designs)
- It's a language that is compiled into Assembly

## Resources
- [c for dummies](https://c-for-dummies.com/caio/), contains source code files
- [cplusplus.com](http://www.cplusplus.com/doc/tutorial)
- [C library in cplusplus.com](http://www.cplusplus.com/reference/clibrary/)
- [learnc.net](https://www.learnc.net/)
- [Wikipedia for C](https://en.wikipedia.org/wiki/C_(programming_language))
- [C data types](https://en.wikipedia.org/wiki/C_data_types) (specially good reference when using the printf() function and when you need to check the total bytes a type of a variable can hold)
- [CodeVault](https://www.youtube.com/channel/UC6qj_bPq6tQ6hLwOBpBQ42Q/playlists)
- [thenewboston AKA Bucky big playlist, very lit!](https://www.youtube.com/playlist?list=PL6gx4Cwl9DGAKIXv8Yr6nhGJ9Vlcjyymq)
- [thenewboston AKA Bucky small playlist](https://www.youtube.com/playlist?list=PL78280D6BE6F05D34)
- [Programiz](https://www.programiz.com/c-programming)
- [Data flair](https://data-flair.training/blogs/c-tutorial/)
- [tutorialspoint](https://www.tutorialspoint.com/c_standard_library/)
- [GeeksForGeeks](https://www.geeksforgeeks.org/c-programming-language/?ref=leftbar)
- [Sololearn](https://www.sololearn.com/learning/1089/)
- [Study tonight](https://www.studytonight.com/c/programs/)
- [CodeSansar](https://www.codesansar.com/c-programming/introduction-c-language.htm)
- [Wikipedia for Assembly](https://en.wikipedia.org/wiki/Assembly_language)
- [Wikipedia for Unix](https://en.wikipedia.org/wiki/Unix)
- [Compiler Explorer](https://godbolt.org/)

## Gravações aulas com prof Ezequiel 
- https://educast.fccn.pt/results?channel=z806w1vcf

## Books
- The C Programming Language, 2nd Edition by Brian W Kernighan and Dennis Ritchie
- Randal E. Bryant, David R. O’Hallaron - Computer Systems. A Programmer’s Perspective [3rd ed.] (2016, Pearson) (also contains other advanced and detailed topics)

## Good paid courses
- https://www.udemy.com/course/c-programming-for-beginners-

## What to use to compile & run programs in C in Windows
1. At the time, I used Oracle VirtualBox to run Xubuntu 20.04 to compile and debug
And I use Visual Studio Code(preferably, because of the autocomplete, auto parenthesis and indentation and intelisense warnings)
You can also use Geany (part of linux distributions), Eclipse or something else to run C code in the virtual machine
2. You can install "Mingw" or other stuff and add it to environment variables and some other stuff to run in VSC. [Tutorial on how to run C in VSC](https://www.javatpoint.com/how-to-run-a-c-program-in-visual-studio-code)
3. You can use a Linux WSL shell or Ubuntu for windows

## Tutorial make virtual machine access your computer disk
- First of, you need to have the machine fully shutdown. No state can be saved. 
- Select the virtual machine in virtual box, clcik "Settings" (orange mechanic wheel)
- Go to the 2nd last option: "Shared folders"
Add your path and check the box "Auto-mount"
- And now, after you run/boot your machine, and go to "File System" AKA "File manager", in the section "Devices" you will find your shared folders. Named like: "sf_{name of the folder}"

### [My stared C and assembly repos](https://github.com/stars/p4ulor/lists/c-and-assembly)

