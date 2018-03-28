/* This program takes the coefficients of a quadratic equation input by the user
 * and calculates the roots if they are real.  Then it prints the coefficients
 * and if the roots are real it prints them, otherwise it tells the user the
 * roots are complex.
 * 	Written by: Samuel Schwartz	
 *      Last update: 11:36 AM, June 7, 2017
 */ 

#include <stdio.h>
#include <math.h>

// Function Declarations
void getData (double*, double*, double*);
int calculateRoots (double, double, double, double*, double*);
void printResults (double, double, double, int, double, double);


int main (void)
{
  // Local Definitions
    double coeff_a;             //coefficient A from quadratic
    double coeff_b;             //coefficient B from quadratic
    double coeff_c;             //coefficient C from quadratic
    int    discriminantSign;    //sign of discriminant(negative or not)
    double root_1;              //first solution for quadratic set  = 0
    double root_2;              //second solution for quadratic set = 0

  // Statements / Function Calls

    getData(&coeff_a, &coeff_b, &coeff_c);
    
    discriminantSign = calculateRoots (coeff_a, coeff_b, coeff_c, 
                                                 &root_1, &root_2);

    printResults(coeff_a, coeff_b, coeff_c, discriminantSign, root_1, root_2);

    return 0;
} // main

void getData (double* numberA, double* numberB, double* numberC)
{
  // Prints a quick overview detailing the program constraints and process
    printf("**************************************************\n");
    printf("* This program will solve the quadratic equation *\n");
    printf("* ax^2+bx+c = 0 for real number coefficients: a, *\n");
    printf("* b, and c. The program will:                    *\n");
    printf("* 1. Determine if the roots of the equation, are *\n");
    printf("*    complex and print a message accordingly.    *\n");
    printf("* 2. If the two roots are real numbers, then the *\n");
    printf("*    program will calculate the two roots using  *\n");
    printf("*    the quadratic formula and print them.       *\n");
    printf("**************************************************\n\n");

  // Prompts user for coefficients and stores in calling function variables
    printf("Enter a :    ");
    scanf("%lf", numberA);
    printf("Enter b :    ");
    scanf("%lf", numberB);
    printf("Enter c :    ");
    scanf("%lf", numberC);
    return;
} // getData

int calculateRoots (double  numA, 
                    double  numB, 
                    double  numC, 
                    double* plusRoot, 
                    double* minusRoot)
{
  //Local Definitions
    double discriminant; 
  
  //Statements
    discriminant = numB * numB - 4 * numA * numC; //calculate discriminant
    
    if (discriminant < 0) 
        return -1;      // Tells calling function discriminant is negative

    else      // If discriminant is >= 0 this calculates the real roots
    {
        *plusRoot = (-numB + sqrt(discriminant)) / (2 * numA);
        *minusRoot = (-numB - sqrt(discriminant)) / (2 * numA);
        return 1;    // Tells calling function discriminant is non negative 
    }
     
} // calculateRoots

void printResults (double coefA, 
                   double coefB, 
                   double coefC, 
                   int    discr, 
                   double root1, 
                   double root2)
{
    printf("\na:         %10f\nb:         %10f\nc:         %10f\n", 
                                  coefA, coefB, coefC); // prints coefficients

    if (discr == -1)   // When discriminant is < 0 tells solutions are complex
       printf("\nThe roots are complex.\n\n"); 
   
    else         // When discriminant is non negative this prints the roots 
       printf("\nRoot 1:    %10f\nRoot 2:    %10f\n\n", root1, root2);
    
    return;
} // printResults
