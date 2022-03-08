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
        return DERIVATE;
        break;
    case '2':
        return MULTIPLY;
        break;
    default:
        return SUBTRACTION;
        break;
    }
}

void callAction(ACTION action, char* firstNum, char* secondNum) {
    switch (action) {
    case ADDITION:
        additionNumbers(firstNum, secondNum, NOTATION);
        break;
    case DERIVATE:
        derivateNumbers(firstNum, secondNum, NOTATION);
        break;
    case MULTIPLY:
        multiplyNumbers(firstNum, secondNum, NOTATION);
        break;
    case SUBTRACTION:
        subtractionNumbers(firstNum, secondNum, NOTATION);
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

    if (type >= '0' && type <= '3') {
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

char* convertNumbersToCurrentNotation(int number) {
    static char numberInCurrentNotation[10];
    int index = 0;

    while (number > 0) {
        numberInCurrentNotation[index++] = checkRange(number % NOTATION);
        number /= NOTATION;
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
            return convertNumbersToCurrentNotation(atoi(number));
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