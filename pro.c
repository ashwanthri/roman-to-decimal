#include <stdio.h>
#include <string.h>

int romanToDecimal(char roman[]) {
    int i, decimal = 0;
    int prevValue = 0;

    for (i = strlen(roman) - 1; i >= 0; i--) {
        int value;
        switch (roman[i]) {
            case 'I':
                value = 1;
                break;
            case 'V':
                value = 5;
                break;
            case 'X':
                value = 10;
                break;
            case 'L':
                value = 50;
                break;
            case 'C':
                value = 100;
                break;
            case 'D':
                value = 500;
                break;
            case 'M':
                value = 1000;
                break;
            default:
                printf("Invalid Roman numeral.\n");
                return -1;
        }

        if (value < prevValue) {
            decimal -= value;
        } else {
            decimal += value;
        }

        prevValue = value;
    }

    return decimal;
}

int isValidRoman(char roman[]) {
    int i;
    int validLetters[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
    int valid = 1;

    for (i = 0; i < strlen(roman); i++) {
        int j;
        int found = 0;

        for (j = 0; j < 7; j++) {
            if (roman[i] == validLetters[j]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            valid = 0;
            break;
        }
    }

    return valid;
}

int main() {
    char romanNumeral[50];
    int decimalValue;

    printf("Enter a Roman numeral between 1 to 3999: ");
    scanf("%s", romanNumeral);

    if (!isValidRoman(romanNumeral)) {
        printf("Invalid Roman numeral.\n");
        return 1;
    }

    decimalValue = romanToDecimal(romanNumeral);

    if (decimalValue >= 1 && decimalValue <= 3999) {
        printf("The decimal equivalent of %s is %d.\n", romanNumeral, decimalValue);
    } else {
        printf("The Roman numeral is out of the valid range (1 to 3999).\n");
    }

    return 0;
}
