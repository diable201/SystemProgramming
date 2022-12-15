echo "Enter the string: "
read STRING
echo $STRING > TMP
REVERSE_STRING="$(rev TMP)"
if [[ $STRING == $REVERSE_STRING ]]; then
	echo "This is palindrome!"
else
	echo "It is not palindrome!"
fi
