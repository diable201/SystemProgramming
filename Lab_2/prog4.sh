shopt -s nullglob

for ext in txt sh c; do 
  files=( *."$ext" )
  printf 'number of %s files: %d\n' "$ext" "${#files[@]}"
done