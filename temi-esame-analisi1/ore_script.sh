#!/bin/sh
#[0-9] significa carattere da 0 a 9
for directory in `find . -name "[0-9][0-9][0-9][0-9][0-9][0-9]" -maxdepth 1`; do 
	new_name=`echo $directory | sed 's/\([0-9][0-9]\)\([0-9][0-9]\)\([0-9][0-9]\)/appello_\3-\2-20\1/'`
	mv $directory $new_name
	#echo $new_name
done