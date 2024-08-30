// Standard libraries
#include <stdio.h>
#include <math.h>


//User libraries:
#include "BOARD.h"

#ifdef PIC32
    // Microchip libraries
    #include <xc.h>
#endif


double Add(double operand1, double operand2);

void CalculatorRun(void)
{
    printf("\n\nWelcome to my calculator program! Compiled at %s %s\n", __DATE__, __TIME__);

    char operator;
    double operand1, operand2, result;

    while (1) {
        printf("Please choose a mathematical operation:\n");
        printf("'+' - Addition\n'-' - Subtraction\n'*' - Multiplication\n'/' - Division\n");
        printf("'q' - Exit the calculator\n");

        scanf(" %c", &operator);
        }
    }

    BOARD_End();
}

double Add(double operand1, double operand2)
{
    return operand1 + operand2;
}

double Subtract(double operand1, double operand2)
{
    return operand1 - operand2;
}
