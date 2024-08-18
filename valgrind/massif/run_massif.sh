#!/bin/bash

executable=../../2048/bin/2048

echo "Running massif..."
valgrind --tool=massif --massif-out-file=massif.out ./$executable

if [ $? -ne 0 ]; then
    echo "Massif failed to run."
    exit 1
fi

echo "Processing massif output with ms_print..."
ms_print massif.out

if [ $? -ne 0 ]; then
    echo "ms_print failed to process the massif output."
    exit 1
fi
