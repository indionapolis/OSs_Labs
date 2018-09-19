echo '0' > new_file
for i in $(seq 1000)
do
  if ln new_file new_file.lock
  then
    echo $(($(tail < new_file -n 1) + 1)) >> new_file
    rm new_file.lock
  fi
done
