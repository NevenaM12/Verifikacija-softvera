#!/bin/bash

SOURCE_DIR="../2048"

cppcheck --enable=all --inconclusive --suppress=missingIncludeSystem $SOURCE_DIR
