#!/bin/bash

# Check if filename is provided
if [ $# -ne 1 ]; then
  echo "Usage: $0 <filename>"
  exit 1
fi

file="$1"

if [ -f "$file" ]; then
  stat -f "Last modification time of '%N': %Sm" -t "%Y-%m-%d %H:%M:%S" "$file"
else
  echo "File '$file' does not exist."
fi
