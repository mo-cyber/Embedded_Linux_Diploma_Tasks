#!/bin/bash

add() {
    result=$(echo "$1 + $2" | bc)
    echo "Result: $result"
}

sub() {
    result=$(echo "$1 - $2" | bc)
    echo "Result: $result"
}

mul() {
    result=$(echo "$1 * $2" | bc)
    echo "Result: $result"
}

div() {
    if [ "$2" -eq 0 ]; then
        echo "Cannot dividr by 0."
    else
        result=$(echo "scale=2; $1 / $2" | bc)
        echo "Result: $result"
    fi
}

while true; do
    echo "Calculator Menu:"
    echo "1. Addition"
    echo "2. Subtraction"
    echo "3. Multiplication"
    echo "4. Division"
    echo "5. Exit"
    read -p "Enter your choice (1/2/3/4/5): " choice

    case $choice in
        1)
            read -p "Enter the first number: " num1
            read -p "Enter the second number: " num2
            add $num1 $num2
            read -p "Press Enter to continue..."
            ;;
        2)
            read -p "Enter the first number: " num1
            read -p "Enter the second number: " num2
            sub $num1 $num2
            read -p "Press Enter to continue..."
            ;;
        3)
            read -p "Enter the first number: " num1
            read -p "Enter the second number: " num2
            mul $num1 $num2
            read -p "Press Enter to continue..."
            ;;
        4)
            read -p "Enter the dividend: " num1
            read -p "Enter the divisor: " num2
            div $num1 $num2
            read -p "Press Enter to continue..."
            ;;
        5)
            echo "Goodbye!"
            exit 0
            ;;
        *)
            echo "Invalid choice. Please select a valid option (1/2/3/4/5)."
            read -p "Press Enter to continue..."
            ;;
    esac
done