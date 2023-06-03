// Akinwale Feranmi Philip
// Programming
// Semester Project
// Due Date : June 10
// Time Spent : 3 weeks
// I acknowlegde that this is my own work

//This program helps elementary students develop their maths skills in addition and subtraction.
//The Program allows students practice addition and subtraction and stores their scores.

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

bool calculation(int, double, double, double&, double&);    //Function Protype to generate random number and get user answer
void storeScore(int);                                       //Function to store the highest score

int main()
{
    //Declare the Variables
    const int ADDITION = 1;               //Variable to practice Addition
    const int SUBTRACTION = 2;            //Variable to practice Subtraction
    const int EXITPROGRAM = 3;            //Variable to Quit the practice
    double firstNumber = 0;               //Variable to get the first number 
    double secondNumber = 0;              //Variable to get the second number
    double getAnswer = 0;                 //Variable to get the answer from the user 
    double answer = 0;                    //Variable to calculate the correct answer
    int currentScore = 0;                 //Variable to add or subtract from the user score
    int highScore = 0;                    //Variable to store the score
    int existingScore = 0;                //Variable for the existing score in the file 
    int whichCalculator;                  //Variable to ask the user to select one of the practice above

    do
    {
        //Output the purpose of the program and Output the Menu for practices they wants to perform
        cout << "How To Practice Additions And Substraction \n";
        cout << ADDITION << " To Practice Addition: \nEnter 1 \n";
        cout << SUBTRACTION << " To Practice Substraction: \nEnter 2 \n";
        cout << EXITPROGRAM << " To Exit Calculation: \nEnter 3 \n\n";

        do
        {
            //Asks the user to select one of the option above.
            cout << "Enter The Practice You Want To Perform: \n";
            cin >> whichCalculator;     //User inputs the practice to perform

            //Program validation against inputting alphabets 
            if (cin.fail())
            {
                cin.clear();  // clears the error on the line
                cin.ignore(); // ignores the error and skip to a new line
                cout << "WARNING: ONLY INTEGERS ARE ACCEPTED!!! \n\n"; // Warning to the user to input only integers
                continue;
            }
            else
            {
                //Validation for when the user inputs an option that is not part of the menu
                if (whichCalculator < ADDITION || whichCalculator > EXITPROGRAM)
                {
                    cout << "Enter an option from the given ones above \n\n";
                    continue;
                }
                else break;
            }

        } while (!cin.fail());

        //Condition for program to quit when exit program is selected
        if (whichCalculator == EXITPROGRAM)
        {
            break;
        }

        //Function call to practice the math skills
        calculation(whichCalculator, firstNumber, secondNumber, answer, getAnswer);

        //Condition to check if the user answer is correct.
        if (getAnswer == answer)
        {
            cout << "Your Answer is correct, Good Job \n\n\n";
            currentScore++;     //If the user answer is correct the program adds +1 to the user score
        }
        else
        {
            cout << "Your Answer is wrong. Study better \n\n\n";
            currentScore--;     //If the user is wrong the program substracts -1 from the present score

            //Condition for if the user gets all the answer wrong he should have a score of zero(0)
            if (currentScore < 0)
            {
                currentScore = 0; 
            }
            continue;
        }


    } while (whichCalculator != 3);

    //Variable that stores the accumulation of the user score
    highScore = currentScore;
    cout << "Your score is: " << currentScore << endl;

    //Opening the file
    fstream score("score.txt", ios::out | ios::in | ios::app);
    if (!score)                     //Checking if the file is opened if not it outputs Error
    {
        cout << "Error: The file is not opened \n";
    }
    else
    {
        //Initialization of the file into an int variable to store the scores
        score >> existingScore;

        if (highScore > existingScore)    //Condition for storing the high score if it is greater than the existing score     
        {
            storeScore(highScore);        //Function call for storing the new high score in the file
            cout << "CONGRATULATIONS!!! You scored the highest score \n";  //User gets a congratulation message when he beats the high score
        }
    }
   score.close();          //Closing the file

    return 0;
}

//Bool Function for generating random number, getting the user answer, and calculating the correct answer
bool calculation(int whichCalculator, double firstNumber, double secondNumber, double& answer, double& getAnswer)
{
    //To help in generating the random numbers by seeding rand with a starting value
    srand((unsigned int)time(NULL));

    //To determine the practices to perform
    switch (whichCalculator)
    {
        //The Generating of random numbers and getting the user answer for practicing addition
    case 1:
        firstNumber = (rand() % 20 + 1);                        //Generates the first random number
        secondNumber = (rand() % 20 + 1);                       //Generates the second random number

        answer = firstNumber + secondNumber;                    //Formula to determine the correct answer

        cout << "Generating Random Numbers For Addition: \n";   //Output generating the random numbers to alert the user
        cout << firstNumber << " + " << secondNumber << endl;   //Output the Random numbers
        cout << "Input your answer: \n";                        //Asks user to input the answer
        cin >> getAnswer;                                       //Get the answer from user
        break;                                                  //Breaks the program to continue the practice

        //The Generating of random numbers and getting the user answer for practicing subtraction
    case 2:
        firstNumber = (rand() % 20 + 1);                         //Generates the first random number
        secondNumber = (rand() % 20 + 1);                        //Generates the second random number

        answer = firstNumber - secondNumber;                     //Formula to determine the correct answer

        cout << "Generating Random Numbers For Subtraction: \n"; //Output generating the random numbers to alert the user
        cout << firstNumber << " - " << secondNumber << endl;    //Output the random numbers
        cout << "Input your answer: \n";                         //Asks user to input the answer
        cin >> getAnswer;                                        //Get the answer from user

        break;                                                   //Breaks the program to continue the practice

    default:
        break;
    }

    return true;                                                //Returns true.
}

//Function for storing the new high score in the file
void storeScore(int highScore)
{
    fstream score("score.txt", ios::out | ios::trunc);        //Opening the file, ios::trunc is replace the current high score in the file with the new one

    score << highScore;                                       //Outputting the high score in the file

    score.close();                                            //Closing the file
}