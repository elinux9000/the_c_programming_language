#!/bin/bash
echo "This script should be called from the directory which contains exercise.c"

command -v inotifywait >/dev/null 2>&1 || { echo >&2 "I require inotifywait but it's not installed. You may want to try apt-get install inotify-tools."; exit 1; }

function finish 
{
	echo
	echo "Restoring terminal settings"
	stty icanon echo
}
trap finish EXIT

stty -icanon -echo

make check && make && ./solution
FILE=$DIR/exercise.c
while [ 1 ]
do
	inotifywait -e modify exercise.c 
	clear
	make check && make && ./solution
	echo 
	echo
done
