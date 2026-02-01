#!/bin/bash
echo "Enter file name:"
read fname
while true
do
    echo "1. Create File"
    echo "2. Write Content to File"
    echo "3. Append File Content"
    echo "4. Delete File Content"
    echo "5. Exit"
    read -p "Enter your choice: " ch
    case $ch in
        1)
            touch $fname
            echo "File created"
            ;;
        2)
            echo "Enter content (Ctrl+D to save):"
            cat > $fname
            ;;
        3)
            echo "Enter content to append (Ctrl+D to save):"
            cat >> $fname
            ;;
        4)
            > $fname
            echo "File content deleted"
            ;;
        5)
            exit
            ;;
        *)
            echo "Invalid choice"
            ;;
    esac
done
