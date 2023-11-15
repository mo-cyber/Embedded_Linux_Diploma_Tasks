#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <project_name>"
    exit 1
fi

project_name="$1"
project_directory="$HOME/Embedded Linux Diploma/4- Bash/01_Introduction/$project_name"

if [ -d "$project_directory" ]; then
    echo "Project directory '$project_name' already exists."
    exit 1
fi

mkdir -p "$project_directory"
cd "$project_directory" || exit 

touch main.c

cat > Makefile <<EOL
CC = gcc
CFLAGS = -Wall

# List of source files
SOURCES = main.c

# Output executable name
EXECUTABLE = $project_name

all: \$(SOURCES)
\t\$(CC) \$(CFLAGS) -o \$(EXECUTABLE) \$(SOURCES)

clean:
\trm -f \$(EXECUTABLE)

.PHONY: all clean
EOL

echo "Project '$project_name' has been created in '$project_directory'."
echo "You can now add your source files and run 'make' to build the project."