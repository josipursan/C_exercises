/*
    gcc -c -std=c17 ./goto.c -o ./goto.o            |   -std=c17 is not necessary if you don't need it; ./goto.c is source file we want to compile; goto.c is compiled to goto.o; -o flag demarcates the object name

    gcc -c std=c17 include/file.c -o obj/file.o     |  Some random file.c that we need for goto.c is compiled to object file.o in dir obj

    gcc ./goto.o obj/file.o -o /bin/prog.exe        |  Objects goto.o and obj/file.o get linked and we get an executable /bin/prog.exe
*/