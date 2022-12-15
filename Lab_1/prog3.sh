if [ $# -ne 0 ]; then
	echo enter the word
	read word
	for fname in $*; do
		if [ -f $fname ]; then
			echo the given input filename is:$fname
			grep -v "$word" $fname
		else
			echo its not a file
		fi
	done
else
	echo "enter atleast one argument as input"
fi
