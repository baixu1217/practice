#!/bin/bash
net='192.168.127.'
i=1
count=0
while [ $i -le 254 ]
do
	if [ $count -eq 20 ];then
		count=0
		sleep 1
	fi
		ping -c1 $net$i &
		let i++
		let count++

done

wait
arp -a | grep -v 'incomplete'
