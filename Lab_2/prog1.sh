echo enter the filename
for fname in *; do
    if test -f $fname; then
        echo "file" $fname
        echo "number of lines" `cat $fname | wc -l` 
        else 
        if test -d $fname; then
                echo "dir" $fname
        fi
    fi
done
 