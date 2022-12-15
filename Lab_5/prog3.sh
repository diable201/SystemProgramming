#!/bin/bash
echo "Enter the file name: "
read FILE 
if [ -f "$FILE" ];
then
   echo "File $FILE exists"
else
   echo "File $FILE does not exist"
fi