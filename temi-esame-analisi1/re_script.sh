#!/bin/sh
#[0-9] significa carattere da 0 a 9
for pdf in `find . -name "[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]AnI.pdf" -maxdepth 3`; do
	#echo AAAA
	#[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]AnI.pdf 
	#									GIORNO1		     MESE2		  	   ANNO3				RINOMINO
	new_name=`echo $pdf | sed 's/\([0-9][0-9]\)\([0-9][0-9]\)\([0-9][0-9][0-9][0-9]\)\(AnI.pdf\)/Appello_\1-\2-\3_AnI.pdf/'`
#	new="./`basename $directory`"
	#echo $new_name
	echo Moving $pdf to... $new_name
	mv $pdf $new_name
	#echo Moving $directory to... ./	
	#mkdir $new
	#rm -r $new
	#cp -r $directory .
	#base=`basename $new_name`
	#new=${base%.*}
	#echo $new_name
	#echo `basename $directory`
	#mv $directory $new_name
	#cp $pdf 
	#echo $new_name
done