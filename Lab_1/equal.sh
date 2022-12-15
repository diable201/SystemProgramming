echo "Enter first string: "
read VAR1
echo "Enter second string: "
read VAR2

if [[ "$VAR1" == "$VAR2" ]]; then
	echo "These 2 strings are equal"
else
	echo "These 2 strings are not equal"
fi
