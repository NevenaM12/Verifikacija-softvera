#!/bin/bash

executable="../../2048/bin/2048"

valgrind --tool=callgrind --cache-sim=yes ./$executable

output=$(ls -t callgrind.out.* | head -n 1)

echo "Profiling complete. Output saved to file $output"

if ! command -v kcachegrind &> /dev/null; then
    echo "kcachegrind is not installed. Please install it to view profiling results. Run sudo apt-get install kcachegrind."
    exit 1
fi

echo "Opening kcachegrind..."
kcachegrind $output
