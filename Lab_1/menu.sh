while : 
do
	echo "MAIN MENU"
	echo "1. Contents of current directory"
    echo "2. Search word in file"
	echo "3. Show content of file"
	echo "4. Exit"
	echo "Please enter option [1 - 4]"
	read opt
	case $opt in
	1)
		echo "Contents of current directory (ls)"
		ls -la
		;;
	2)
		echo "Grep command (grep)"
        echo "Enter the word to search: "
        read searchName
        echo "Enter the file name: "
        read fname
        grep --color $searchName $fname
		;;
    3)
		echo "Show content of file (cat)"
		echo "Enter the file name: "
        read fname
        cat $fname
		;;
	4)
		echo "Bye $USER"
		exit 1
		;;
	esac
done
