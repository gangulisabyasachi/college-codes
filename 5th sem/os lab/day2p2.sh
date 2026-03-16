#!/bin/bash

# Check if exactly two arguments are passed
if [ $# -ne 2 ]; then
  echo "Usage: $0 <OS1_directory> <OS2_directory>"
  exit 1
fi

OS1="$1"
OS2="$2"

# Check if both directories exist
if [ ! -d "$OS1" ]; then
  echo "Directory '$OS1' does not exist."
  exit 1
fi

if [ ! -d "$OS2" ]; then
  echo "Directory '$OS2' does not exist."
  exit 1
fi

# Loop through all files in OS1
for file in "$OS1"/*; do
  # Extract the base file name (strip path)
  filename=$(basename "$file")

  # Check if a file with same name exists in OS2
  if [ -f "$OS2/$filename" ]; then
    rm "$OS2/$filename"
    echo "Deleted: $OS2/$filename"
  fi
done
