#!/bin/bash

# Get the battery status
battery_status=$(acpi -b | awk '{print $3}')

# Check if the battery is "Full"
if [ "$battery_status" = "Full," ]; then
  echo "Battery is full."
else
  echo "Battery is not full."
fi
