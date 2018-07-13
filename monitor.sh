#!/bin/bash
echo "This script should be called from the directory which contains exercise.c"

command -v inotifywait >/dev/null 2>&1 || { echo >&2 "I require inotifywait but it's not installed. You may want to try apt-get install inotify-tools."; exit 1; }
make check && make && ./solution
FILE=$DIR/exercise.c
while [ 1 ]
do
	while inotifywait -e modify exercise.c ;
		do : ; 
	done
	clear
	make check && make && ./solution
	echo 
	echo
done
