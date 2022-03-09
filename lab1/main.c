#include <stdio.h>
#include "helper.h"
#include <string.h>
#include <math.h>

void main() {
    fillTable();
    createFile();
    char firstNum[10];
    char secondNum[10];
    strcpy(firstNum, getUserFirstNumber());
    strcpy(secondNum, getUserSecondNumber());
    ACTION action = askAction();
    callAction(action, firstNum, secondNum);
}