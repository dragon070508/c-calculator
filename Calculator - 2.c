// Standard libraries
#include <stdio.h>
#include <math.h>


//User libraries:
#include "BOARD.h"

#ifdef PIC32
    // Microchip libraries
    #include <xc.h>
#endif


// **** Declare function prototypes ****
double Add(double operand1, double operand2);
double Subtract(double operand1, double operand2);
double Divide(double operand1, double operand2);
double Multiply(double operand1, double operand2);
//add more prototypes here

void CalculatorRun(void)
{
    printf("\n\nWelcome to my calculator program! Compiled at %s %s\n", __DATE__, __TIME__);

    // Your code here

    char operator;
    double operand1, operand2, result;

    while (1) {
        printf("Please choose a mathematical operation:\n");
        printf("'+' - Addition\n'-' - Subtraction\n'*' - Multiplication\n'/' - Division\n");
        printf("'q' - Exit the calculator\n");

        scanf(" %c", &operator);

        if (operator == 'q') {
            printf("Exiting calculator program.\n");
            return;
        }

        printf("Enter the operand: ");
        scanf("%lf", &operand1);

        printf("Enter the second operand: ");
        scanf("%lf", &operand2);

        // Switch statement which will allow us to switch between different cases depending on user input
        switch (operator) {
        case '+':
            result = Add(operand1, operand2);
            printf("Result of (%.2lf + %.2lf): %.6lf\n", operand1, operand2, result);
            break;
        case '-':
            result = Subtract(operand1, operand2);
            printf("Result of (%.2lf - %.2lf): %.6lf\n", operand1, operand2, result);
            break;
        case '*':
            result = Multiply(operand1, operand2);
            printf("Result of (%.2lf * %.2lf): %.6lf\n", operand1, operand2, result);
            break;
        case '/':
            result = Divide(operand1, operand2);
            if (result == HUGE_VAL)
                printf("Cannot divide by zero.\n");
            else
                printf("Result of (%.2lf / %.2lf): %.6lf\n", operand1, operand2, result);
            break;
        default:
            printf("Invalid operator! Please choose a valid operation.\n");
        }
    }

    BOARD_End();
}