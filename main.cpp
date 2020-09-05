#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> highScores;

class Game{

    private:
    int numOfPlayers;
    int playerOneScore;
    int playerTwoScore;

    string playerOneName;
    string playerTwoName;

    public:
    Game(){
        numOfPlayers = 1;
        playerOneScore = 0;
        
    }


    void setNumberOfPlayers(int n){
        numOfPlayers = n;

    }
    void setPlayerOneName(string name){
        playerOneName = name;
    }
    void setPlayerTwoName(string name){
        playerTwoName = name;
    }
    
    
};


class TicTacToe: public Game
{
    //TicTacToe sub class of game - it also can't access private variables in Game
    private:
    int numOfPlayers;

    //make these public? or make getter methods?
    int playerOneScore;
    int playerTwoScore;

    string playerOneName;
    string playerTwoName;

    

    public:
    //variables from TicTacToe3.cpp
    char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char symbol;
    bool playerDidWin;
    char symbols[2];
    char winner;
    int counter = 0;
    int numOfGames;


    //constructor
    TicTacToe() : Game(){
        numOfPlayers = 2;
        playerOneScore = 0;
        playerTwoScore = 0;

    }
    //inherited methods
    //void setNumberOfPlayers(int num);
    

   /* //methods to add
    void introMenu();
    void setPlayerNames();
    void displayScores();
    void drawMatrix();
    void incrementOneScore();
    void incrementTwoScore();
    void updateGrid(int num);
    */

    void introMenu(){
        cout << "You have chosen 2-player game!" << endl;
        cout << "How many games?" << endl;
        cin >> numOfGames;
        setPlayerNames();

    }
    
    void setPlayerNames(){
        cout << "Player 1, please enter your screen name: " << endl;
        cin >> playerOneName;
        cout << "Player 2, please enter your screen name: " << endl;
        cin >> playerTwoName;

    }

    // int* getPlayerScores(){
    //     int scores[2];
    //     scores[0] = playerOneScore;
    //     scores[1] = playerTwoScore;

    //     return scores;
        
    // }

    void getPlayerScores(int *oneScore, int *twoScore){
        *oneScore = playerOneScore;
        *twoScore = playerTwoScore;
    }

    


    void drawMatrix(){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cout << matrix[i][j] << " ";
                if(j<2){
                    cout << "| ";
                }

            }
            cout << endl;
            if(i<2){
                cout << "--|---|--" << endl;
            }
        }
    }

    void playerPrompt(){
        int number;
        cout << "Enter number on grid" << endl;
        cin >> number;
        updateGrid(number);
    }

    bool checkHorizontals(){
        //check the three rows
        for(int i=0; i<3; i++){
            if((matrix[i][0] == matrix[i][1]) && (matrix[i][0] == matrix[i][2])){
                winner = matrix[i][0];
                return true;
            }
        }

        return false;
    }

    bool checkVerticals(){
        //check the three columns
        for(int j = 0; j<3; j++){
            if((matrix[0][j] == matrix[1][j]) && (matrix[0][j] == matrix[2][j])){
                winner = matrix[0][j];
                return true;
            }
            
        }

        return false;
    }

    bool checkDiagonals(){
        //check first diagonal
        if((matrix[0][0] == matrix[1][1]) && (matrix[0][0] == matrix[2][2])){
            winner  = matrix[0][0];
            return true;
        }//check second diagonal
        else if((matrix[0][2] == matrix[1][1]) && (matrix[0][2] == matrix[2][0])){
            winner = matrix[0][2];
            return true;
        }else{
            return false;
        }
    }

    bool checkForWin(){
        bool horizontalCheck = checkHorizontals();
        bool verticalCheck = checkVerticals();
        bool diagCheck = checkDiagonals();

        if(horizontalCheck == true){
            return true;
        }else if(verticalCheck == true){
            return true;
        }else if(diagCheck == true){
            return true;
        }else{
            return false;
        }
    }

    void updateGrid(int num){
        char* ptr = &matrix[0][0];
        num = num-1;
        if(*(ptr+num) == symbols[0] || *(ptr+num) == symbols[1]){
            cout << "Cannot overwrite. Enter another number" << endl;
            //keep the counter same. Shouldn't increment
            counter = counter - 1;
            //keep symbol same because it is the same turn

        }else{
            *(ptr+num) = symbol;
            system("clear");//clear the screen before re-drawing
            drawMatrix();
            //add a check for win to prevent a message for next user's
            //turn if game has ended
            playerDidWin = checkForWin();
            if((playerDidWin == false) && (counter < 8)){
                changeSymbol();
            }
            
        }
    }

    void changeSymbol(){
        if(symbol == symbols[0]){
            symbol = symbols[1];
            cout << "It's player " << symbol << "'s turn" << endl;
        }else{
            symbol = symbols[1];
            cout << "It's player " << symbol << "'s turn" << endl;
        }
    }

    void announceWinner(){
        if(winner == symbols[0]){
            cout << playerOneName << +"wins!" << endl;
            playerOneScore++;
        }else if(winner == symbols[1]){
            cout << playerTwoName << +"wins!" << endl;
            playerTwoScore++;
        }else if(counter == 11){
            cout << "Exited game." << endl;
        }else{
            cout << "No winner. It's a tie!" << endl;
        }
    }
    
    void displayScores(){

        cout << "After " << numOfGames << ", here are the scores: " << endl;
        cout << playerOneName << ": " << playerOneScore << endl;
        cout << playerTwoName << ": " << playerTwoScore << endl; 
        
    }
    void ResetBoard(){
       char* ptr = &matrix[0][0];
        for(int i = 0; i<9; i++){
            //*(ptr+i) = static_cast<char>(i+1);
            //*(ptr+i) = (char)(i+1);
            *(ptr+i) = (char)(i);
        }
        
    }
    void executeGame(){
        for(int i = 0; i<numOfGames; i++){
            ResetBoard();
            cout << matrix[0][1] << endl;
            drawMatrix();//drawing the char matrix variable
            //need to update the variable char matrix with 1,2,3,...
            

            cout << playerOneName << ", choose symbol: " << endl;
            cin >> symbols[0];
            cout << playerTwoName << ", choose symbol: " << endl;
            cin  >> symbols[1];
            symbol = symbols[0];

            while(!(playerDidWin == true) && (counter < 9)){
                playerPrompt();

                playerDidWin = checkForWin();
                counter++;

            }
            announceWinner();
        }

        displayScores();


    }

    



};

void printMenu(){
    cout << "Welcome!" << endl;
    cout << "Please choose one of the options below:" << endl;
    cout << "1. One Player Game" << endl;
    cout << "2. Two Player Game" << endl;
    cout << "3. See High Scores" << endl;
}

void printHighScores(){
    
}

int main(){
    int option;
    //create mutable data structure for high scores : vector??

    printMenu();
    cin >> option;

    TicTacToe game1;

    switch(option)
    {
        case 1: game1.setNumberOfPlayers(1);

            break;
        case 2: game1.introMenu();

            break;
        case 3: 
        default: game1.introMenu();
            
            break;
        
    }

    game1.executeGame();
    //std::max(game1.playerOneScore, game1.playerTwoScore);

    int firstPlayerScore, secondPlayerScore;
    game1.getPlayerScores(&firstPlayerScore, &secondPlayerScore);
    int higherScore = std::max(firstPlayerScore, secondPlayerScore);
    highScores.push_back(higherScore);





    

    
    return 0;
}
