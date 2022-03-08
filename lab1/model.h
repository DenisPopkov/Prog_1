typedef enum { 
    NOT_DIGIT = 0, 
    INCORRECT_RANGE,
    INCORRECT_ACTION
} EXCEPTION;

typedef enum {
    ADDITION = 0,
    DERIVATE,
    MULTIPLY,
    SUBTRACTION
} ACTION;

char* askActionMessage = 
    "Please enter the number of action in console\n"
    "0 - addition numbers\n"
    "1 - derivate numbers\n"
    "2 - multiply numbers\n"
    "3 - subtraction numbers\n\n"
    "Action: ";

char notationOperators[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
char *notationEquivalent[16] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15" };