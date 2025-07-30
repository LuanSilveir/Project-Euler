#!/bin/bash

# Check if argument is given
if [ -z "$1" ]; then
    echo "Usage: $0 <file_to_run>"
    exit 1
fi

FILE="./$1"
NUM_RUNS=$2
sum=0

# Check if the file is executable
if [ ! -x "$FILE" ]; then
    echo "Error: '$FILE' is not executable or doesn't exist."
    exit 1
fi

# Run the file NUM_RUNS times and sum the outputs
for i in $(seq 1 $NUM_RUNS); do
    output=$($FILE)
    
    # Optional: show each output
    # echo "Run $i: $output"

    # Add to sum using bc for floating-point support
    sum=$(echo "$sum + $output" | bc -l)
done

# Calculate and print average
average=$(echo "$sum / $NUM_RUNS" | bc -l)
echo "Average after $NUM_RUNS runs: $average"
