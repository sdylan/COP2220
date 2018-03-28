/* This program will calculate the cost of installing carpet in one room.
   The user will enter the room's dimensions, a discount rate to be 
   applied, and the price per square foot of carpet. The program then 
   calculates and displays the individual costs, discount value, subtotal, 
   tax and total in a bill form. 
      Written by: Samuel Schwartz
      Last Update: 5/22/2017, 11:24 AM
*/

#include <stdio.h>
#define LABOR_UNIT_PRICE 0.35 
#define TAX_RATE 0.085

int main (void)
{
   //Local Declarations
    int length;             //length of room
    int width;              //width of room
    int area;               //area of room
    int discountRate;       //percentage of discount
    float carpetUnitPrice;  //price per sq. ft. of carpet
    float carpetPrice;      //price of carpet for calculated area
    float laborPrice;       //price of labor for calculated area
    float installedPrice;   //price of labor and carpet together 
    float discountValue;    //monetary discount amount
    float subtotal;         //subtotal after the discount is applied
    float tax;              //monetary tax amount
    float total;            //total price after tax and discount
  
  //Statements

   //Prompt user for length, width, discount rate, and carpet cost/sq ft
    printf("Enter Length (feet, integer):               ");
    scanf("%d", &length);
    printf("Enter Width (feet, integer):                ");
    scanf("%d", &width);
    printf("Enter Customer Discount (Percent, integer): ");
    scanf("%d", &discountRate);
    printf("Enter Carpet Cost per square foot (xxx.xx): ");
    scanf("%f", &carpetUnitPrice);

   //Calculate the variables to be displayed in CHARGES
    area = length * width;
    carpetPrice = carpetUnitPrice * area;
    laborPrice = LABOR_UNIT_PRICE * area;
    installedPrice = carpetPrice + laborPrice;
    discountValue = discountRate * 0.01 * installedPrice;
    subtotal = installedPrice  - discountValue;
    tax = subtotal * TAX_RATE;
    total = subtotal + tax;

   //Print the information in an organized bill-like format.
    printf("\n\n\t\t\tMEASUREMENTS\n\n");
    printf("Length\t\t   %3d ft.\n", length);
    printf("Width\t\t   %3d ft.\n", width);
    printf("Area\t\t   %3d sq. ft.\n", area);
    printf("\n\n\n\t\t\tCHARGES\n\nDESCRIPTION\tCOST/SQ.FT.\t\t  CHARGE\n");
    printf("-----------\t-----------\t\t----------\n");
    printf("Carpet\t\t%5.2f\t\t\t$%8.2f\n", carpetUnitPrice, carpetPrice);
    printf("Labor\t\t %04.2f\t\t\t$%8.2f\n\t\t\t\t\t----------\n", LABOR_UNIT_PRICE, 
                                                                   laborPrice);
    printf("INSTALLED PRICE\t\t\t\t$%8.2f\n", installedPrice);
    printf("Discount\t%5d%%\t\t\t$%8.2f\n\t\t\t\t\t----------\n", discountRate, 
                                                                  discountValue);
    printf("SUBTOTAL\t\t\t\t$%8.2f\n", subtotal);
    printf("Tax\t\t\t\t\t$%8.2f\n", tax);
    printf("TOTAL\t\t\t\t\t$%8.2f\n\t\t\t\t\t----------\n", total);  
    
    return 0;
}  //End Main
