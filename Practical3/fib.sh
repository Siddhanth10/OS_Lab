#!/bin/bash
read -p "Enter value of n: " n
a=1
b=1
echo "Fibonacci Series:"
for ((i=1; i<=n; i++))
do
    echo -n "$a "
    c=$((a + b))
    a=$b
    b=$c
done
echo ""
