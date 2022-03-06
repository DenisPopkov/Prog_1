#include <stdio.h>
#include <math.h>
#include <string.h>

char* additionNumbers(char* firstNumber, char* secondNumber, unsigned short int base) {
    int firstNumberLength = strlen(firstNumber);
    int secondNumberLength = strlen(secondNumber);

    static char s[0];
    static char sum[0];
    int diff = abs(firstNumberLength - secondNumberLength);
    int curr, carry = 0;

    for (int i = 1; i <= diff; i++) {
        strcat(s, "0");
    }

    if (firstNumberLength < secondNumberLength) {
        firstNumber = strcat(s, firstNumber);
    } else {
        secondNumber = strcat(s, secondNumber);
    }

    for (int i = fmax(firstNumberLength, secondNumberLength) - 1; i > -1; i--) {
        curr = carry + (firstNumber[i] - '0') + (secondNumber[i] - '0');
        carry = curr / base;
        curr = curr % base;
        strcpy(sum, (char)(carry + '0') + sum);
    }

    // if (carry > 0) {
    //     strcpy(sum, (char)(carry + '0') + sum);
    // }

    return sum;
}
 

char* derivateNumbers(char firstNumber[], char secondNumber[]) {

    return "";
}

char* multiplyNumbers(char firstNumber[], char secondNumber[]) {

    return "";
}

char* subtractionNumbers(char firstNumber[], char secondNumber[]) {

    return "";
}