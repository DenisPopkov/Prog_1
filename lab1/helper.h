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
        add(firstNum, secondNum, NOTATION);
        break;
    case DERIVATE:
        derivateNumbers(firstNum, secondNum);
        break;
    case MULTIPLY:
        multiplyNumbers(firstNum, secondNum);
        break;
    case SUBTRACTION:
        subtractionNumbers(firstNum, secondNum);
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

void stringRevert(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

char* convertNumbersToCurrentNotation(int number) {
    static char numberInCurrentNotation[10];
    int index = 0;

    while (number > 0) {
        numberInCurrentNotation[index++] = checkRange(number % NOTATION);
        number /= NOTATION;
    }

    numberInCurrentNotation[index] = '\0';
    stringRevert(numberInCurrentNotation);

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
    static char firstNumber[10];

    printf("Enter firstNumber: ");
    scanf("%s", firstNumber);

    return isNumber(firstNumber);
}

char* getUserSecondNumber() {
    static char secondNumber[10];

    printf("Enter secondNumber: ");
    scanf("%s", secondNumber);

    return isNumber(secondNumber);
}