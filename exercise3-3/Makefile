#-std=c11 directs compiler to use c11 standard
# phony targets are used when the command should always be run.  If a file gets created with for eg. clean, then make clean
# won't run unless it is a prerequisite of the phony target
.PHONY: clean check

solution: exercise.c
	gcc -std=c11 -Wall -Werror -o solution exercise.c

check:
	../checkpatch.pl -terse -file -no-tree exercise.c
	

clean: 
	rm solution *.o
