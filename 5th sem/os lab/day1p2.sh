#!/bin/bash

# Prompt for user's name
echo -n "Enter your name: "
read username

# Get current hour in 24-hour format
hour=$(date +"%H")

# Determine greeting based on time
if [ "$hour" -ge 5 ] && [ "$hour" -lt 12 ]; then
  greeting="Good Morning"
elif [ "$hour" -ge 12 ] && [ "$hour" -lt 17 ]; then
  greeting="Good Afternoon"
elif [ "$hour" -ge 17 ] && [ "$hour" -lt 21 ]; then
  greeting="Good Evening"
else
  greeting="Good Night"
fi

# Get current date and time
current_datetime=$(date +"%A, %d %B %Y %I:%M:%S %p")

# Get the process ID of this terminal session
terminal_pid=$$

# Display the greeting and details
echo ""
echo "$greeting, $username!"
echo "Current date and time: $current_datetime"
echo "Your terminal session PID is: $terminal_pid"
