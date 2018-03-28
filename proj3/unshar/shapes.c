/*  This program will print a particular shape of a particular size based
 *  on the user's input. The user will be able to choose between a square,
 *  right triangle and a diamond. After printing a shape the program will
 *  let the user print more shapes of different sizes until tasked to 
 *  stop.
 *
 *      Written by: Samuel Schwartz
 *      Last Update: 9:58 PM June 13, 2017
 */

#include <stdio.h>

// Function Declarations
void display_greeting_message (void);  
void print_square (void);
void print_triangle (void);
void print_diamond (void);
void print_stars (int);
void print_blanks (int);
void display_goodbye_message (void);

int main (void)
{
    int code; // Entry code to determine which shape to print

    display_greeting_message(); // Call to greeting
    scanf("%d", &code);         // Obtain code from keyboard  
  
    while (code != 0)    // Based on code entered by user this will 
    {                    // call the specfific shape function  
        switch (code)    // or display an error message for bad input.
        {
            case 1: print_square();
                    break;
            case 2: print_triangle();
                    break;
            case 3: print_diamond();
                    break;
            default: printf("Incorrect code. Enter 1, 2, 3, or 0.\n");
        } // switch

    display_greeting_message(); //After shape prints greeting is
    scanf("%d", &code);         //printed again allowing for new
                                //code entry and obtain code.             
    } // while
        
    display_goodbye_message();     //Prints goodbye as program exits.

    return 0;

} // main

  

void display_greeting_message (void) 
{
  //Print greeting message when function is called.
    printf("\n");
    printf("*****************************************************************\n");
    printf("**************** WELCOME TO THE PATTERN PRINTER! ****************\n");
    printf("*                                                               *\n");
    printf("*  Enter a code of 1 to print a square pattern of stars         *\n");
    printf("*  Enter a code of 2 to print a right triangle pattern of stars *\n");
    printf("*  Enter a code of 3 to print a diamond pattern of stars        *\n");
    printf("*  Enter a code of 0 to stop printing patterns                  *\n");
    printf("*                                                               *\n"); 
    printf("*****************************************************************\n");

    printf("You may now enter the code:  "); //Prompt for code entry.

    return;

}  // display_greeting_message

void print_square (void)
{
    int side;        // Length of square's side
    int i;           // Index used in for loop

    printf("Enter the size of the square (integer): "); //Prompt square size
    scanf("%d", &side);                                 //Obtain square size

    printf("\n\n");                   //Output Spacing

    for (i = 1; i <= side; i++)       //Prints a # of rows equal to  
    {                                 //the side length.
        print_stars(side);            //Function call to print an amount 
        printf("\n");                 //of stars equal to side length.
    } // for
    
    printf("\n\n");                   //Output Spacing        

    return;

}  // print_square

void print_triangle (void)
{
    int base;        //Base length of right triangle.
    int i;           //Index used in for loop.

    printf("Enter triangle's base (integer): "); //Prompt triangle base
    scanf("%d", &base);                        //Obtain base from keyboard

    printf("\n\n");              //Output Spacing

    for (i = 1; i <= base; i++)  //Prints a # of rows equal to base length
    {
        print_stars (i);         //Prints a # of stars that increments by 
        printf("\n");            //one with each new row. 
    } // for
   
    printf("\n\n");              //Output Spacing

    return;

}  // print_triangle

void print_diamond (void)
{
    int width;    //Width of the diamond
    int blanks;   //Amount of blanks to print to align diamond rows
    int i;        //index used in for loops

    printf("Enter the diamond's width (integer): "); //Prompt diamond width
    scanf("%d", &width);                        //Obtain width from keyboard 

    printf("\n\n");      //Output Spacing

    if (width % 2)       //If width is odd, do nothing 
        ;                
    else                 //If even add 1 to be able to print a symmetric
        width++;         //diamond.   

    blanks = width / 2;  //Set amount of blanks required for first row.

    for (i = 1; i <= (width / 2 + 1); i++) //Prints top part of diamond
    {                                      //and middle row.
        print_blanks(blanks--);   //Print blanks so stars are centered
        print_stars(i * 2 - 1);   //Print stars to fit diamond pattern
        printf("\n");            
    } // for
    
    blanks = 0;     //Reset blanks to 0 after last decrement made it -1.

    for (i = (width / 2); i > 0; i--)  //Prints bottom part of diamond
    {
        print_blanks(++blanks);      //Print blanks to center stars.
        print_stars(i * 2 - 1);      //Print stars to fit diamond pattern
        printf("\n");
    } // for

    printf("\n\n");               //Output Spacing

    return;

}  // print_diamond

void print_stars (int size)
{
    int i;   //Index used in for loop

    for (i = 1; i <= size; i++)  //Prints stars based on parameter sent by 
    {                            //calling function.
        printf("*");
    } // for

    return;

}  // print_stars

void print_blanks (int spaces)
{
    int i;   //Index used in for loop
    
    for (i = 1; i <= spaces; i++)  //Prints blanks based on parameter sent
    {                              //by calling function.
        printf(" ");
    } // for

    return;

}  // print_blanks

void display_goodbye_message (void)
{   
  //Print goodbye message when function is called.
    printf("\n");
    printf("*****************************************************************\n");
    printf("*                          GOOD BYE!!!                          *\n");
    printf("*****************************************************************\n");
    printf("\n");

    return;

}  // display_goodbye_message
