/*  C Source Code Begins Here */
/*  This program prompts and receives as input the length and
    width of a room in feet; calculates the ares of the room;
    and outputs the length, width, and the area of the room.   */
/*     This program has been written by: Asai Asaithambi.
    This program was last modified on: May 13, 2017            */

#include <stdio.h> // Preprocessor directive

int main (void)
{
    float length;    // denotes length in feet
    float width;     // denotes width in feet
    float area;      // denotes area in sq. feet

/* Prompt for input and receive input */

    printf ("Enter length in feet: ");
    scanf ("%f", &length);
    printf ("Enter width in feet: ");
    scanf ("%f", &width);

/* Calculate area = length times width */

    area = length * width;

/* Print out results */

    printf ("Length: %10.2f Feet\n", length);
    printf ("Width : %10.2f Feet\n", width);
    printf ("Area :  %10.2f Sq. Feet\n", area);

    return 0;
} // main
/* C Source Code ends here */
