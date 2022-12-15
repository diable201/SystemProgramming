echo "Enter file name: "
read file
if [ -f "$file" ];
then
    echo "File $file exists"
    if [ -w $file ]; then 
        W="Write = yes"
    else
        W="Write = No"
    fi

    if [ -x $file ]; then 
        X="Execute = yes"
    else
        X="Execute = No"
    fi

    if [ -r $file ]; then
        R="Read = yes"
    else
        R="Read = No"
    fi
    echo "$file permissions"
    echo "$W"
    echo "$R"
    echo "$X"
else
   echo "File $file does not exist"
fi
