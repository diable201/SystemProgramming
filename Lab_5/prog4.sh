echo "Enter file name: "
read file
 
# find out if file has write permission or not
if [ -w $file ]; then 
    W="Write = yes"
else
    W="Write = No"
fi
# find out if file has excute permission or not
if [ -x $file ]; then 
    X="Execute = yes"
else
    X="Execute = No"
fi
# find out if file has read permission or not
if [ -r $file ]; then
    R="Read = yes"
else
    R="Read = No"
fi

echo "$file permissions"
echo "$W"
echo "$R"
echo "$X"