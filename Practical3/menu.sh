#!/bin/bash
while true
do
    echo "1. Display calendar of current month"
    echo "2. Display today's date and time"
    echo "3. Display currently logged in users"
    echo "4. Display terminal number"
    echo "5. Exit"
    echo -n "Enter your choice: "
    read choice
    case $choice in
        1)
            echo "Calendar of current month:"
            cal
            ;;
        2)
            echo "Today's date and time:"
            date
            ;;
        3)
            echo "Currently logged in users:"
            who
            ;;
        4)
            echo "Your terminal number:"
            tty
            ;;
        5)
            echo "Exiting program..."
            exit 0
            ;;
        *)
            echo "Invalid choice! Please try again."
            ;;
    esac
    echo
done
