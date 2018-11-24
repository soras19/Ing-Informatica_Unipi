#!/bin/bash
url="http://users.dma.unipi.it/berselli/dida/esami/"
for i in {10..17}
do
	let ii=$i+1
	wget -r --no-parent --accept pdf `echo $url$i-$ii`
	#echo $url$i-$ii
done
#wget -r --no-parent --accept pdf  