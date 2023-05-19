#!/bin/bash
run_cpp_file() {
    # Get the name of the C++ file from the command-line argument
    cpp_file="$1"

    # Compile the C++ file
    g++ "$cpp_file" -o output

    # Check if compilation was successful
    if [ $? -eq 0 ]; then
        # Run the compiled executable and store the output
        output=$(./output)

        # Display the output
        echo "$output"
    else
        echo "Compilation failed."
    fi

    # Clean up the compiled executable
    rm output
}

