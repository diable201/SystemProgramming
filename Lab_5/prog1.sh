#!/bin/bash

echo "List of Files which have Read, Write and Execute Permissions in Current Directory"
for file in *; do
	if [ -r $file -a -w $file -a -x $file ]; then
		echo $file
	fi
done
