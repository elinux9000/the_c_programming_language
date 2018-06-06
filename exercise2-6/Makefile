#-std=c11 directs compiler to use c11 standard
solution: exercise2-6.c
	gcc -std=c11 -Wall -Werror -o solution exercise2-6.c
	../checkpatch.pl -terse -file -no-tree exercise2-6.c
clean: 
	rm solution *.o
