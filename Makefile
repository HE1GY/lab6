lab6: filesys.o main.o
	gcc filesys.o main.o -o lab6
filesys.o: filesys.c filesys.h
	gcc -c filesys.c
main.o: main.c
	gcc -c main.c
clean: 
	rm -f lab6 filesys.o main.o 
install:
	sudo cp lab6 /usr/local/bin/lab6
uninstall: 
	sudo rm -f /usr/local/bin/lab6