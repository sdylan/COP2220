/*  This program takes a class's quiz grades and calculates statistics. 
 *  To do this it reads data from a separate file saved in the working 
 *  directory and stores the student ID and their respective scores in 
 *  various arrays. It then calculates the high, low and average score
 *  for each quiz and stores the statistical data in their respective
 *  arrays. Last the program prints the input data and statistics in a 
 *  user friendly format that is easy to read.
 *
 *     Written by: Samuel Schwartz
 *     Last Update: 11:04 AM June 23, 2017
 */

#include <stdio.h>

#define MAX_STUDENTS 40 //Maximum amount of students in the class
#define MAX_QUIZZES  5  //Maximum amount of quizzes taken

// Function declarations
void    getData(int  studentID[ ], 
                int  studentScores[ ][MAX_QUIZZES], 
                int* numStudents);

void    calculate(int    Scores[ ][MAX_QUIZZES], 
                  int    highScores[], 
                  int    lowScores[], 
                  double averageScores[], 
                  int    numStudent);

void    printResults(int    studentID[],
                     int    studentScores[][MAX_QUIZZES],
                     int    highScores[],
                     int    lowScores[],
                     double averageStudents[],
                     int    numStudents);

int     calcHiScore(int Scores[ ][MAX_QUIZZES], 
                    int quiz_count, 
                    int numStudents);

int     calcLoScore(int Scores[ ][MAX_QUIZZES], 
                    int quiz_count, 
                    int numStudents); 

double  calcAverage(int Scores[ ][MAX_QUIZZES], 
                    int quiz_count, 
                    int numStudents); 


int main (void)
{
    int studentID[MAX_STUDENTS];                   //list of student ID's
    int studentScores[MAX_STUDENTS][MAX_QUIZZES];  //list of student's quiz scores
    int highScores[MAX_QUIZZES];                   //list of high scores per quiz
    int lowScores[MAX_QUIZZES];                    //list of low scores per quiz
    double averageScores[MAX_QUIZZES];             //list of average scores per quiz
    int numStudents;                               //number of students in class
    
    getData(studentID, studentScores, &numStudents); //acquire id's, scores and # of 
                                                     //students from file
                                                     
    calculate(studentScores, highScores, lowScores,  //calculate the high, low and,  
              averageScores, numStudents);           //average scores per quiz

    printResults(studentID, studentScores, highScores,   //prints all id's scores and
                 lowScores, averageScores, numStudents); //statistics in readable table
           
    return 0;

}  //main

void getData(int stID[ ], int Scores[ ][MAX_QUIZZES], int* numStudents)
{
    int student_count = 0;   //counter to count the number of students
    int quiz_count;          //for-loop counter for the number of quizzes processed
    FILE* spIn;              //file pointer used to open and close read file

    spIn = fopen ("myfile.dat", "r");  //open file to read student id's and scores

    while (fscanf(spIn, "%d", &stID[student_count]) != EOF) //read id to studentID
    {                                                       //until end of file reached

        //read the individual quiz scores into their respective locations in array   
         for (quiz_count = 0; quiz_count < MAX_QUIZZES; quiz_count++)  
         {                           
              fscanf (spIn, "%d", &Scores[student_count][quiz_count]);
         }  //for
        
         student_count++; //count the amount of students processed
    }  //while
    
    fclose(spIn);         //close file for resource management

    *numStudents = student_count;   //store the amount of students in memory location
                                    //used in main
    return;

}  //getData
              
void calculate (int    Scores[][MAX_QUIZZES],
                int    highScores[],
                int    lowScores[],
                double averageScores[],
                int    numStudents)
{ 
    int quiz_count;      //for-loop counter for the number of quizzes processed

    for (quiz_count = 0; quiz_count < MAX_QUIZZES; quiz_count++)
    {
        //Set high score for specific quiz based on result of calcHiScore function
        //for that particular quiz
         highScores[quiz_count] = calcHiScore(Scores, 
                                              quiz_count, 
                                              numStudents);

        //Set low score for specific quiz based on result of calcLoScore function
        //for that particular quiz
         lowScores[quiz_count] = calcLoScore(Scores,
                                             quiz_count,
                                             numStudents);

        //Set average score for specific quiz based on result of calcAverage function
        //for that particular quiz
         averageScores[quiz_count] = calcAverage(Scores,
                                                 quiz_count,
                                                 numStudents);
    }  //for
 
    return;

}  //calculate

void printResults (int    studentID[],
                   int    studentScores[][MAX_QUIZZES],
                   int    highScores[],
                   int    lowScores[],
                   double averageScores[],
                   int    numStudents)
{   
    int quiz_count;     //for-loop counter for quizzes processed
    int student_count;  //for-loop counter for students processed
     
   //Print the header line for the following columns in table
    printf("Student         Quiz 1   Quiz 2   Quiz 3   Quiz 4   Quiz 5\n");

   //For each student prints the student id and specific quiz scores under their
   //respective columns then go to newline.
    for (student_count = 0; student_count < numStudents; student_count++)
    {
         printf("%7d           ", studentID[student_count]);
    
         for (quiz_count = 0; quiz_count < MAX_QUIZZES; quiz_count++)
         {
               printf("%-9d", studentScores[student_count][quiz_count]);
         }  //for
    
         printf("\n");
    }  //for
                    
    printf("High Score        ");   //print high score row header

   //print the high scores under the respective quiz column
    for (quiz_count = 0; quiz_count < MAX_QUIZZES; quiz_count++)
         printf("%-9d", highScores[quiz_count]);
    
    printf("\n Low Score        "); //On a newline prints low score row header

   //print the low scores under the respective quiz columns
    for (quiz_count = 0; quiz_count < MAX_QUIZZES; quiz_count++)
         printf("%-9d", lowScores[quiz_count]);
    
    printf("\n  Average       ");  //On a newline prints the average row header
         
   //print the average scores under the respective quiz columns
    for (quiz_count = 0; quiz_count < MAX_QUIZZES; quiz_count++)
         printf("%-9.1f", averageScores[quiz_count]);

    printf("\n"); //New line for spacing
    
    return;

}  //printResults

int calcHiScore (int Scores[][MAX_QUIZZES], 
                 int quiz_count, 
                 int numStudents)
{
    int highResult;      //used to store the high score for a specific quiz
    int student_count;   //for-loop counter for # of processed students

    highResult = Scores[0][quiz_count]; //set high score to first student's score

   //For each student compare their score to the current high score if it is larger
   //set that score as the high score.
    for (student_count = 1; student_count < numStudents; student_count++)
    {
        if (Scores[student_count][quiz_count] > highResult)
            highResult = Scores[student_count][quiz_count];
    }

    return highResult;  //Send the high score to calculate function

}  //calcHiScore

int calcLoScore (int Scores[][MAX_QUIZZES], 
                 int quiz_count, 
                 int numStudents)
{
    int lowResult;     //used to store the low score for a specific quiz
    int student_count; //for-loop counter for # of processed students

    lowResult = Scores[0][quiz_count]; //set low score to first student's score

   //For each student compare their score to the current high score if it is smaller
   //set that score as the low score.
    for (student_count = 1; student_count < numStudents; student_count++)
    {
        if (Scores[student_count][quiz_count] < lowResult)
            lowResult = Scores[student_count][quiz_count];
    }

    return lowResult; //Send the low score to the calculate function

}  //calcLoScore

double calcAverage (int Scores[][MAX_QUIZZES],
                    int quiz_count,
                    int numStudents)
{
    double averageResult; //used to store the average score for a specific quiz
    int student_count;    //for-loop counter for # of processed students
    int sum = 0;          //used to store the total sum of the quiz scores used in 
                          //the average calculation

   //Sum the students' quiz scores for a particular quiz that was sent by calculate 
   //function. 
    for (student_count = 0; student_count < numStudents; student_count++)
    {
        sum += Scores[student_count][quiz_count];
    }

    averageResult = (double) sum / numStudents; //calculates average quiz score

    return averageResult; //Send average score to calculate function

}  //calcAverage 
