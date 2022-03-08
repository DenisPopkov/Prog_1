#include <stdio.h>
#include "helper.h"
#include <string.h>
#include <math.h>

void main() {
    char firstNum[10];
    char secondNum[10];
    strcpy(firstNum, getUserFirstNumber());
    strcpy(secondNum, getUserSecondNumber());
    printf("first - %s. second - %s\n", firstNum, secondNum);
    ACTION action = askAction();
    callAction(action, firstNum, secondNum);

    #ifndef additionTest
    #endif
}