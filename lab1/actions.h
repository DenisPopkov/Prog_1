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

char* multiplyNumbers(char* firstNumber, char* secondNumber, unsigned short int base) {

    int firstNumberLength = strlen(firstNumber);
    int secondNumberLength = strlen(secondNumber);
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
    int len = strlen(formattedFirstNumber);
    int mult1[len];
    int mult2[len];

    for (int i = len; i >= 0; i--) {
        
        if (formattedFirstNumber[i] >= '0' && formattedFirstNumber[i] <= '9')
            val1 = formattedFirstNumber[i] - '0';
        else if (formattedFirstNumber[i] >= 'A' && formattedFirstNumber[i] <= 'F')
            val1 = formattedFirstNumber[i] - 'A' + 10;

        if (formattedSecondNumber[i] >= '0' && formattedSecondNumber[i] <= '9') {
            val2 = formattedSecondNumber[i] - '0';
        } else if (formattedSecondNumber[i] >= 'A' && formattedSecondNumber[i] <= 'F') {
            val2 = formattedSecondNumber[i] - 'A' + 10;
        }

        mult1[i] = val1;
        mult2[i] = val2;
    }

    int mult[6] = { 0, 0, 0, 0, 0, 0 };

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            mult[j+i] += mult1[i] * mult2[j];
        }
    }

    int add = 0;
    for (int i = 0; i < 6; i++) {
        mult[i] += add;
        if (mult[i] >= base) {
            add = mult[i] / base;
            mult[i] = mult[i] % base;
        } else {
            add = 0;
        }
    }

    static char mulResult[5]; 

    for (int i = 0; i < 6; i++) {
        mulResult[i] = notationOperators[mult[i]];
    }

    strrev(mulResult);
    printf("Multiply result - ");
    
    for (int i = 0; i < 6; i++) {
        if (mulResult[i] != '0') {
            printf("%c", mulResult[i]);
        }
    }

    return mulResult;
}

double divideNumbers(char* firstNumber, char* secondNumber) {

    int firstNumberLength = strlen(firstNumber);
    int secondNumberLength = strlen(secondNumber);
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

    double val1, val2, divisionResult = 0.0;

    for (int i = strlen(formattedSecondNumber) - 1; i >= 0; i--) {
        
        if (formattedFirstNumber[i] >= '0' && formattedFirstNumber[i] <= '9')
            val1 += formattedFirstNumber[i] - '0';
        else if (formattedFirstNumber[i] >= 'A' && formattedFirstNumber[i] <= 'F')
            val1 += formattedFirstNumber[i] - 'A' + 10;

        if (formattedSecondNumber[i] >= '0' && formattedSecondNumber[i] <= '9') {
            val2 += formattedSecondNumber[i] - '0';
        } else if (formattedSecondNumber[i] >= 'A' && formattedSecondNumber[i] <= 'F') {
            val2 += formattedSecondNumber[i] - 'A' + 10;
        }
    }

    divisionResult += val2 / val1;

    printf("Deriviate result is - %lf\n", divisionResult);

    return divisionResult;
}


char* subtractionNumbers(char* firstNumber, char* secondNumber, unsigned short int base) {

    int firstNumberLength = strlen(firstNumber);
    int secondNumberLength = strlen(secondNumber);
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
    int flag = 0;
    static char subtractionResult[10];

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

        if (flag == 1) {
            val1 -= 1;
            flag = 0;
        }

        if (val1 - val2 < 0) {
            val1 += base;
            flag = 1;
        }

        val3 = val1 - val2;

        if (val3 >= 0 && val3 <= 9) {
            subtractionResult[index++] = val3 + '0';
        } else if (val3 >= 10 && val3 < 16) {
            subtractionResult[index++] = val3 + ('A' - 10);
        }
    }

    strrev(subtractionResult);
    printf("Subtraction result is - %s\n", subtractionResult);

    return subtractionResult;
}

void createFile() {
    FILE * file;
    file = fopen("file1.txt", "w");

    static char firstLine[1000000];
    strcat(firstLine, "        base 2        base 3        base 4        base 5        base 6        base 7        base 8        base 9        base 10        base 11        base 12        base 13        base 14        base 15        base 16");
    strcat(firstLine, "\n\n");
    strcat(firstLine, table);

    fputs(firstLine, file);
    fclose(file);
}