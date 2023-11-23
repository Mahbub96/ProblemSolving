#!/bin/bash

:<<"echo"
it's multiline comment from this line to echo 
this block of code is same code using recursive 
# Function to calculate the nth Fibonacci number
fibonacci() {
    if [ $1 -le 1 ]; then
        echo $1
    else
        echo $(( $(fibonacci $(( $1 - 1 ))) + $(fibonacci $(( $1 - 2 ))) ))
    fi
}

# Specify the number of Fibonacci numbers to generate
n=40

# Loop to generate and print the first n Fibonacci numbers
for ((i=0; i<n; i++))
do
    result=$(fibonacci $i)
    echo -n "$result "
done

echo

# Specify the number of Fibonacci numbers to generate
n=40

# Initialize variables for the first two Fibonacci numbers
a=0
b=1

# Loop to generate and print the first n Fibonacci numbers
for ((i=0; i<n; i++))
do
    echo -n "$a "

    # Calculate the next Fibonacci number and update variables
    temp=$a
    a=$b
    b=$((temp + b))
done

echo
