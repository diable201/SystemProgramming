# do the following for loop
echo "Can you see the following:" # outer loop
for ((i = 1; i <= 5; i++)); do
	#inner loop
	for ((j = 1; j <= i; j++)); do
		echo -n "$i"
	done
	echo ""
done
