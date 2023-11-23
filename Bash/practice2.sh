#!/bin/bash

# Function to read two numbers from a file and return their sum
getAndSumNumbersFromFile() {
    filename=$1

    # Check if the file exists
    if [ ! -e "$filename" ]; then
        echo "Error: File '$filename' not found."
        exit 1
    fi

    # Read the numbers from the file
    read -r num1 < "$filename"
    read -r num2 < "$filename"

    # Calculate the sum and print the result
    sum=$((num1 + num2))
    echo "The sum of $num1 and $num2 is: $sum"
}

# Check if a filename is provided as a command-line argument
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

# Call the function with the provided filename
getAndSumNumbersFromFile "$1"

