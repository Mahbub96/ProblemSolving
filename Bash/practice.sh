#!/bin/bash

# Function to get two numbers from the user and return their sum
getAndSumNumbers() {
    echo "Enter the first number:"
    read num1

    echo "Enter the second number:"
    read num2

    sum=$((num1 + num2))
    echo "The sum of $num1 and $num2 is: $sum"
}

# Call the function
getAndSumNumbers

