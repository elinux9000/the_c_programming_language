#!/bin/bash
while [ 1 ]
do
	while inotifywait -e modify exercise.c ;
		do ls ; 
	done
	clear
	make && ./solution
done
