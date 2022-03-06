#include <stdio.h>
#include <math.h>
#include <string.h>

char* additionNumbers(char* firstNumber, char* secondNumber, unsigned short int base) {
    int firstNumberLength = strlen(firstNumber);
    int secondNumberLength = strlen(secondNumber);

    static char s[0];
    static char additionResult[0];
    int diff = abs(firstNumberLength - secondNumberLength);

    for (int i = 1; i <= diff; i++)
        strcat(s, "0");
    
    printf("First number - %s\n", firstNumber);
    printf("Second number - %s\n", secondNumber);
    
    int val1, val2, val3, c = 0;
    int currentLen = strlen(additionResult);

    for (int i = strlen(firstNumber) - 1; i >= 0; i--) {
        if (firstNumber[i] >= '0' && firstNumber[i] <= '9')
            val1 = firstNumber[i] - '0';
        else if (firstNumber[i] >= 'A' && firstNumber[i] <= 'F')
            val1 = firstNumber[i] - 'A' + 10;

        if (secondNumber[i] >= '0' && secondNumber[i] <= '9')
            val2 = secondNumber[i] - '0';
        else if (secondNumber[i] >= 'A' && secondNumber[i] <= 'F')
            val2 = secondNumber[i] - 'A' + 10;

        val3 = (val1 + val2 + c) % base; 
        c = (val1 + val2 + c) / base;

        if (val3 <= 9) {
            additionResult[currentLen] = val3 + '0';
        } else {
            additionResult[++currentLen] = val3 + ('A' - 10);
        }
    }

    if (c == 1) {
        additionResult[currentLen] = '1';
    }

    strrev(additionResult);
    printf("Result is - %s\n", additionResult);

    return additionResult;
}
 

char* derivateNumbers(char* firstNumber, char* secondNumber, unsigned short int base) {

    return "";
}

char* multiplyNumbers(char* firstNumber, char* secondNumber, unsigned short int base) {

    return "";
}

char* subtractionNumbers(char* firstNumber, char* secondNumber, unsigned short int base) {

    return "";
}