#!/bin/bash
read -p "Enter value of desired prime numbers: " n
count=0
num=2

while [ $count -lt $n ]
do
    flag=0
    for ((i=2; i<=num/2; i++))
    do
        if [ $((num % i)) -eq 0 ]; then
            flag=1
            break
        fi
    done
    if [ $flag -eq 0 ]; then
        echo -n "$num "
        count=$((count + 1))
    fi
    num=$((num + 1))
done
echo ""
