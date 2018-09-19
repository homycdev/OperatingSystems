touch file.txt
 
num=0
cond=999
while [ $num -lt $cond ]; do
    err=$( { ln file.txt file.txt.lock ; } 2>&1)
    if [[ "$err" == "" ]]; then
        num=$((num+1)) 
        echo $num >> file.txt
        num=`cat file.txt | tail -n 1`
        wait
        rm file.txt.lock
    fi
done
