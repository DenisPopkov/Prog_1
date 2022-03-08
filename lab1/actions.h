#include <stdio.h>
#include <math.h>
#include <string.h>

char* additionNumbers(char* firstNumber, char* secondNumber, unsigned short int base) {
    int firstNumberLength = strlen(firstNumber);
    int secondNumberLength = strlen(secondNumber);
    static char additionResult[0];
    int diff = abs(firstNumberLength - secondNumberLength);

    printf("First number - %s\n", firstNumber);
    printf("Second number - %s\n", secondNumber);

    char formattedFirstNumber[10] = "";
    char formattedSecondNumber[10] = "";

    if (firstNumberLength > secondNumberLength) {
        for (int i = 0; i <= diff - 1; i++)
            formattedSecondNumber[i] = '0';
    } else {
        for (int i = 0; i <= diff - 1; i++)
            formattedFirstNumber[i] = '0';
    }

    strcat(formattedFirstNumber, firstNumber);
    strcat(formattedSecondNumber, secondNumber);

    int val1, val2, val3, c = 0;
    int index = 0;

    for (int i = strlen(formattedSecondNumber) - 1; i >= 0; i--) {
        
        if (formattedFirstNumber[i] >= '0' && formattedFirstNumber[i] <= '9')
            val1 = formattedFirstNumber[i] - '0';
        else if (formattedFirstNumber[i] >= 'A' && formattedFirstNumber[i] <= 'F')
            val1 = formattedFirstNumber[i] - 'A' + 10;

        if (formattedSecondNumber[i] >= '0' && formattedSecondNumber[i] <= '9') {
            val2 = formattedSecondNumber[i] - '0';
        } else if (formattedSecondNumber[i] >= 'A' && formattedSecondNumber[i] <= 'F') {
            val2 = formattedSecondNumber[i] - 'A' + 10;
        }

        val3 = (val1 + val2 + c) % base; 
        c = (val1 + val2 + c) / base;

        if (val3 <= 9) {
            additionResult[index++] = val3 + '0';
        } else {
            additionResult[index++] = val3 + 'A' - 10;
        }
    }

    if (c == 1) {
        additionResult[index++] = '1';
    }

    strrev(additionResult);
    printf("Result of addition - %s\n", additionResult);

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