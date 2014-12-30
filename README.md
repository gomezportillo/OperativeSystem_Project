Operative System- Proccess Management Proyect
=======================

In this activity we have to implement several exercises related to proccess management in Unix. 

For this duty, a directory with several folders has been created. In *src/* is set the code of all the exercises, in *obj/* the object files and in *exec/* all the the executables.  When compiling with the set makefile, in each direcory will be generated all its related files.

For compiling all files, a makefile has been set. For using it, set the terminal in the proyect root directoty and type

    make
	
For removing all generated files in the different direcories, type 

    make clean 

For executing the different files, after had executed the makefile set the terminal in the proyect root directory and type

    ./exec/<program> <arg1> <arg2> … <argn>

being program the name of the program and argn its different arguments.

Although it is normal to declare the variables at the beginning of the program, in this proyect they will be declared after the number of arguments error handler for not saving memory needlessly.

Avoid executing *ll* comand in any program as it will crash.
***
escudo1
=======
	
This program has to execute an infinite loop ignoring the signal passed through the arguments. The sintaxis will be;

    escudo1 <n>

where *n* is the number of the signal to be ignored. e.g. *./exec/escudo1.exe 2*
***
escudo2
=======

This program has to execute an infinite loop responding to the signal passed through the arguments, printing *Recibida la señal n* and finishing. The sintaxis will be;

    escudo2 <n>

where *n* is the number of the signal to answer to. e.g. *./exec/escudo2.exe 2*
***
escudo3
=======

This program has to execute an infinite loop responding to the signal passed through the arguments, printing *Recibida la señal n* continuing with the program. The sintaxis will be;

    escudo3 <n>

where *n* is the number of the signal to answer to. e.g. *./exec/escudo3.exe 2*
***
alarma
======

This program has to print each n seconds *Alarma number*, where *number* is the number of the alarm. The sintaxis will be;
	
    alarma <n>

where *n* is the number of waiting seconds. e.g. *./exec/alarma.exe 3*
***
mikill
======

This program has to send a signal to a proccess whose pid is passed through the arguments. The sintaxis will be;
	
    mikill <signal> <pid>

where *signal* is the number of desired signal to be sent and *pid* the proccess identifier of the proccess. e.g. *./exec/mikill.exe 2 1560*
***
entrada
=======

This program has to execute the program passed in the arguments emulating its **stdin** with the file in the args. The sintaxis will be;
	
    entrada <file> <program> <arg1> ... <argn>

*e.g. ./exec/entrada.exe data/stdin.txt wc -l -c*
***
salida
======
This program has to execute the program passed in the arguments emulating its **stdout** with the file in the args. The sintaxis will be;
	
    salida <file> <program> <arg1> ... <argn>

*e.g. ./exec/salida.exe data/stdout.txt ls -l*
***
tuberia
=======

This program has to emulate the functionality of the Unix pipe, it means, similar to *program1 | program2*. The sintaxis will be;

    tuberia <program1> <program2> 

e.g. *./exec/tuberia.exe ls wc*
***
consumidor
==========
This program has read from the pipe passed through the arguments printing the data on *stdout*. The sintax will be;

    consumidor <my_pipe>

e.g. *./exec/consumidor.exe my_pipe*
***
mimkfifo
===
This program has to create a new pipe with the name and the permissions in octal passed in the arguments. The sintaxis will be;

    mimkfifo <octal_permissions> <name> 

e.g. *./exec/mimkfifo.exe 664 my_pipe*
***
padre
====
This program has to execute as many child proccess as it has defined in a constant (by default  3) and make them sleep for a random number of secons between 1 and *max_sec*, provided through the arguments, announcing everything that happens. The sintaxis will be;

    padre <max_sec>

e.g. *./exec/padre.exe 4*

hijo
===
**This program will be the one called by padre.exe**. 

It must sleep for a random number of secons between 1 and *max_sec*, provided through the arguments, announcing everything that happens. Although it is not thought to be executed, it can be called by

    hijo <max_sec>

e.g. *./exec/hijo.exe 3*
