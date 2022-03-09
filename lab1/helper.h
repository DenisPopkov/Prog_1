#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "model.h"
#include "actions.h"
#include <stdlib.h>

const unsigned short int NOTATION = (21 % 15) + 10;

const char * const throwableMessage[] = {
    [NOT_DIGIT] = "Isn't digit\n",
    [INCORRECT_RANGE] = "Incorrect range!\n",
    [INCORRECT_ACTION] = "Incorrect action!\n"
};

void printErrorMessage(EXCEPTION typeOfError) {
    printf("%s", throwableMessage[typeOfError]);
}

ACTION getActionType(char type) {
    switch (type) {
    case '0':
        return ADDITION;
        break;
    case '1':
        return SUBTRACTION;
        break;
    case '2':
        return DERIVATE;
        break;
    case '3':
        return MULTIPLY;
        break;
    default:
        return CREATE_FILE;
        break;
    }
}

void callAction(ACTION action, char* firstNum, char* secondNum) {
    switch (action) {
    case ADDITION:
        additionNumbers(firstNum, secondNum, NOTATION);
        break;
    case SUBTRACTION:
        subtractionNumbers(firstNum, secondNum, NOTATION);
        break;
    case DERIVATE:
        divideNumbers(firstNum, secondNum);
        break;
    case MULTIPLY:
        multiplyNumbers(firstNum, secondNum, NOTATION);
        break;
    case CREATE_FILE:
        createFile();
        break;
    default:
        printErrorMessage(INCORRECT_ACTION);
        break;
    }
}

ACTION askAction() {
    char type;
    printf(askActionMessage);
    scanf(" %c", &type);

    if (type >= '0' && type <= '4') {
        return getActionType(type);
    } else {
        printErrorMessage(INCORRECT_ACTION);
    }
}

char checkRange(int number) {
    if (number >= 0 && number <= 9)
        return (char)(number + '0');
    else
        return (char)(number - 10 + 'A');
}

char* convertNumbersToCurrentNotation(int number, int base) {
    static char numberInCurrentNotation[10];
    int index = 0;

    while (number > 0) {
        numberInCurrentNotation[index++] = checkRange(number % base);
        number /= base;
    }

    numberInCurrentNotation[index] = '\0';
    strrev(numberInCurrentNotation);

    return numberInCurrentNotation;
}

char* isNumber(char number[]) {
    for (int i = 0; number[i] != '\0'; i++) {
        if (!isdigit(number[i]) && number[i] >= '0') {
            printErrorMessage(NOT_DIGIT);
            break;
        } else if (number[i] < '0') {
            printErrorMessage(INCORRECT_RANGE);
            break;
        } else {
            return convertNumbersToCurrentNotation(atoi(number), NOTATION);
        }
    }
}

char* getUserFirstNumber() {
    char firstNumber[10];

    printf("Enter firstNumber: ");
    fgets(firstNumber, 10, stdin);

    return isNumber(firstNumber);
}

char* getUserSecondNumber() {
    char secondNumber[10];

    printf("Enter secondNumber: ");
    fgets(secondNumber, 10, stdin);

    return isNumber(secondNumber);
}

void additionTest() {
    char *firstNumbers[5] = { "13", "17", "432", "123", "873" };
    char *secondNumbers[5] = { "43", "18", "12", "3", "233" };
    char *additionAnswers[5] = { "38", "23", "1BC", "7E", "452" };

    for (int i = 5; i <= 0; i++) {
        if (additionNumbers(firstNumbers[i], secondNumbers[i], NOTATION) == additionAnswers[i]) {
            continue;
        } else {
            printf("Test failed!\n");
            break;
        }
    }

    printf("Test passed!\n");
}

void subtractionTest() {
    char *firstNumbers[5] = { "14", "231", "432", "123", "873" };
    char *secondNumbers[5] = { "13", "76", "12", "3", "233" };
    char *additionAnswers[5] = { "1", "9B", "1A4", "78", "280" };

    for (int i = 5; i <= 0; i++) {
        if (subtractionNumbers(firstNumbers[i], secondNumbers[i], NOTATION) == additionAnswers[i]) {
            continue;
        } else {
            printf("Test failed!\n");
            break;
        }
    }

    printf("Test passed!\n");
}

void fillTable() {

    char currentLine[2];

    for (int i = 1; i <= 25; i++) {
        itoa(i, currentLine, 10);
        strcat(table, currentLine);
        strcat(table, "       ");
        for (int j = 2; j <= 16; j++) {
            
            if (j > 10) strcat(table, " ");

            if (strlen(convertNumbersToCurrentNotation(i + 1, j)) == 1) {
                strcat(table, convertNumbersToCurrentNotation(i + 1, j));
                strcat(table, "             ");
            }  else if (strlen(convertNumbersToCurrentNotation(i + 1, j)) == 2) {
                strcat(table, convertNumbersToCurrentNotation(i + 1, j));
                strcat(table, "            ");
            } else if (strlen(convertNumbersToCurrentNotation(i + 1, j)) == 3) {
                strcat(table, convertNumbersToCurrentNotation(i + 1, j));
                strcat(table, "           ");
            } else if (strlen(convertNumbersToCurrentNotation(i + 1, j)) == 4) {
                strcat(table, convertNumbersToCurrentNotation(i + 1, j));
                strcat(table, "          ");
            } else if (strlen(convertNumbersToCurrentNotation(i + 1, j)) == 5) {
                strcat(table, convertNumbersToCurrentNotation(i + 1, j));
                strcat(table, "         ");
            }
        }

        strcat(table, "\n\n");
    }
}