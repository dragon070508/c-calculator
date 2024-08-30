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

double Average(double operand1, double operand2);

double Multiply(double operand1, double operand2);

double AbsoluteValue(double operand);

double FahrenheitToCelsius(double operand);

double CelsiusToFahrenheit(double operand);

double Tangent(double operand);

double Round(double operand);

void CalculatorRun(void)
{
    printf("\n\nWelcome to my calculator program! Compiled at %s %s\n", __DATE__, __TIME__);

    // Your code here

    char operator;
    double operand1, operand2, result;

    while (1) {
        printf("Please choose a mathematical operation:\n");
        printf("'+' - Addition\n'-' - Subtraction\n'*' - Multiplication\n'/' - Division\n");
        printf("'m' - Average\n'a' - Absolute Value\n'c' - Fahrenheit to Celsius\n");
        printf("'f' - Celsius to Fahrenheit\n't' - Tangent\n'r' - Round\n");
        printf("'q' - Exit the calculator\n");

        scanf(" %c", &operator);

        if (operator == 'q') {
            printf("Exiting calculator program.\n");
            return;
        }

        printf("Enter the operand: ");
        scanf("%lf", &operand1);

        if (operator != 'a' && operator != 'c' && operator != 'f' && operator != 't' && operator != 'r') {
            printf("Enter the second operand: ");
            scanf("%lf", &operand2);
        }

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
        case 'm':
            result = Average(operand1, operand2);
            printf("Result of Average(%.2lf, %.2lf): %.6lf\n", operand1, operand2, result);
            break;
        case 'a':
            result = AbsoluteValue(operand1);
            printf("Result of |%.2lf|: %.2lf\n", operand1, result);
            break;
        case 'c':
            result = FahrenheitToCelsius(operand1);
            printf("Result of (%.2lf degF -> degC): %.6lf\n", operand1, result);
            break;
        case 'f':
            result = CelsiusToFahrenheit(operand1);
            printf("Result of (%.2lf degC -> degF): %.6lf\n", operand1, result);
            break;
        case 't':
            result = Tangent(operand1);
            printf("Tangent of %.2lf degrees: %.6lf\n", operand1, result);
            break;
        case 'r':
            result = Round(operand1);
            printf("Result of %.2lf rounded to the nearest place: %.6lf\n", operand1, result);
            break;
        default:
            printf("Invalid operator! Please choose a valid operation.\n");
        }
    }

    BOARD_End();
}


// Defining all of our functions here 
double Add(double operand1, double operand2)
{
    return operand1 + operand2;
}
double Subtract(double operand1, double operand2)
{
    return operand1 - operand2;
}
double Multiply(double operand1, double operand2)
{
    return operand1 * operand2;
}
double Divide(double operand1, double operand2)
{
    return operand1 / operand2;
}
double AbsoluteValue(double operand)
{
    if (operand < 0)
        return -operand;
    else
        return operand;
}
double FahrenheitToCelsius(double fahrenheit)
{
    return (fahrenheit - 32) * 5.0 / 9.0;
}
double Average(double operand1, double operand2)
{
    return (operand1 + operand2) / 2;
}
double CelsiusToFahrenheit(double celsius)
{
    return (celsius * 9.0 / 5.0) + 32;
}
double Tangent(double x)
{
    return tan(x);
}
double Round(double operand)
{
    return round(operand);
}
