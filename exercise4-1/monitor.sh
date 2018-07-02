#!/bin/bash
command -v inotifywait >/dev/null 2>&1 || { echo >&2 "I require inotifywait but it's not installed. You may want to try apt-get install inotify-tools."; exit 1; }
make && ./solution
while [ 1 ]
do
	while inotifywait -e modify exercise.c ;
		do ls ; 
	done
	clear
	echo 
	echo
done
