#include <stdio.h>
#include "helper.h"
#include <string.h>
#include <math.h>

void main() {
    static char firstNum[0];
    strcpy(firstNum, getUserFirstNumber());
    char* secondNum = getUserSecondNumber();
    ACTION action = askAction();
    callAction(action, firstNum, secondNum);
}