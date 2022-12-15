echo "Enter the file name: "
read fname
count=0

if [ -f $fname ]; then
	for var in $(cat $fname); do
		count=$(echo $count+1 | bc)
	done
	echo $count
else
	echo "File doesnt exist"
fi
