#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

int setBit(int num, int pos);
int clearBit(int num, int pos);
int toggleBit(int num, int pos);
int readBit(int num, int pos);

int main() {
    int choice, num, pos;

    while (1) {
        printf("\nBit Manipulation Menu:\n");
        printf("1) Set a Bit\n");
        printf("2) Clear a Bit\n");
        printf("3) Toggle a Bit\n");
        printf("4) Read a Bit\n");
        printf("5) Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        // check if choice is Exiting
        if (choice == 5) {
            printf("Exiting\n");
            break;
        }

        printf("Enter a number: ");
        scanf("%d", &num);
        
        printf("Enter the bit pos lie in range(0-31): ");
        scanf("%d", &pos);

        // check if is valid position
        if (pos >= 0 && pos < 32)
        {
            switch (choice) {
                // Set
                case 1:
                    num = setBit(num, pos);
                    printf("Result after setting bit %d: %d\n", pos, num);
                    break;
                // Clear
                case 2:
                    num = clearBit(num, pos);
                    printf("Result after clearing bit %d: %d\n", pos, num);
                    break;
                // Toggle
                case 3:
                    num = toggleBit(num, pos);
                    printf("Result after toggling bit %d: %d\n", pos, num);
                    break;
                // Read
                case 4:
                    printf("Bit %d is: %d\n", pos, readBit(num, pos));
                    break;
                default:
                    printf("Invalid choice! Please select a valid option.\n");
            }
        }
        else {
            printf("Invalid bit pos! Please enter a value between 0 and 31.\n");
            continue;
        }
        // time delay to see result
        Sleep(1000);
    }

    return 0;
}



int setBit(int num, int pos) {
    return num | (1 << pos);
}

int clearBit(int num, int pos) {
    return num & ~(1 << pos);
}

int toggleBit(int num, int pos) {
    return num ^ (1 << pos);
}

int readBit(int num, int pos) {
    return (num >> pos) & 1;
}