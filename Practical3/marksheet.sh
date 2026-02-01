#!/bin/bash
echo "Enter Student Name:"
read name
echo "Enter marks for Subject 1 :"
read m1
echo "Enter marks for Subject 2:"
read m2
echo "Enter marks for Subject 3:"
read m3
total=$((m1+m2+m3)) 
percentage=$((total / 3))
if [ $percentage -ge 75 ]; then 
	class="Distinction"
elif [ $percentage -ge 60 ]; then 
	class="First Class"
elif [ $percentage -ge 50 ]; then 
	class="Second Class"
elif [ $percentage -ge 35 ]; then 
	class="Pass"
else
	class="Fail"
fi
echo "Total: $total"
echo "Percentage: $percentage"
echo "Grade: $class"
