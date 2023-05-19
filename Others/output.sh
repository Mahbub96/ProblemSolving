#!/bin/bash

cpp_file="$1"
input_file="$2"

# Compile the C++ file
g++ "$cpp_file" -o output

# Check if compilation was successful
if [ $? -eq 0 ]; then
    # Check if the input file exists
    if [ -f "$input_file" ]; then
        # Run the compiled executable and provide the input from the file
        ./output < "$input_file"
    else
        echo "Input file not found."
    fi
else
    echo "Compilation failed."
fi

# Clean up the compiled executable
rm output

