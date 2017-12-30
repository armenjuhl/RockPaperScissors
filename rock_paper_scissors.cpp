//CS 161   Armen Juhl   Project 4: Rock Paper Scissors

#include <iostream>
#include <string>
using namespace std;

int getUserResult(int &userChoice);
void outputResult(int &userChoice, int &comp, string &userName, int &wins, int &losses, int &ties);
int generateCompMove(int &compMoveResult);
//BEGIN MAIN
int wins = 0;
int losses = 0;
int ties = 0;
bool keepPlaying;

int main()
{
    int userChoice;
    int compMoveResult;
    string userName;
    string continueProgram;
    
    //BEGIN PROGRAM
    cout << "Rock, Paper, Scissors!!! \n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nYou will be playing our microchip Fry Brain. What is your name? ";
    cin >> userName;
    
    keepPlaying = true;
    do {
        
        generateCompMove(compMoveResult);
        // Function for computer's random move: Rock, Paper or Scissors
        
        getUserResult(userChoice);
        cout << "You selected: " << userChoice << endl;
        
        outputResult(userChoice, compMoveResult, userName, wins, losses, ties);
        
        cout << "Do you want to keep playing? Enter y / n" << endl;
        cin >> continueProgram;
        if (continueProgram == "n") {
            cout << userName << "'s Statistics------------------------------\n" << wins << "wins " << losses <<  "losses " << ties << "ties ";
            keepPlaying = false;
        }
    } while (keepPlaying);
    
    system("pause");
    return 0;
}
//End of Main() // BEGINNING OF FUNCTIONS //
int generateCompMove(int &compMoveResult)
{
    compMoveResult = rand() % 3 + 1;
    return compMoveResult;
}

int getUserResult(int &userChoice)
{
    cout << "1: Rock " << endl;
    cout << "2: Paper " << endl;
    cout << "3: Scissors " << endl;
    cout << "0: Exit " << endl;
    cout << "Whats your move?" << endl;
    cin >> userChoice;
    while ((userChoice < 0) || (userChoice > 3))
    {
        cout << "Invalid character. Try again! ";
        cin >> userChoice;
    }
    return userChoice;
}
/*if (userChoice == 0)
        {
            keepPlaying = false;
        }
    return userChoice;*/


void outputResult(int &userChoice, int &compMoveResult, string &userName, int &wins, int &losses, int &ties)
{
    if ((userChoice == 1 && compMoveResult == 3) || (userChoice == 2 && compMoveResult == 1) || (userChoice == 3 && compMoveResult == 2))
    {
        cout << userName << " won!" << endl;
        wins++;
    }
    else if ((userChoice == 1 && compMoveResult == 2) || (userChoice == 2 && compMoveResult == 3) || (userChoice == 3 && compMoveResult == 1))
    {
        cout << userName << " lost!" << endl;
        losses++;
				}
    else if ((userChoice == 1 && compMoveResult == 1) || (userChoice == 2 && compMoveResult == 2) || (userChoice == 3 && compMoveResult == 3))
    {
        cout << "A tie!" << endl;
        ties++;
    }	
}


/*print menu
read input
comp choice
calculate winner
print results
*/
