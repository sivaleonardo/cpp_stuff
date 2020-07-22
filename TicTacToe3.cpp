//Co-authored by Jennifer Lloyd and Siva B. 

#include <iostream>
using namespace std;
char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char symbol;
bool playerDidWin = false;
char symbols[2];
char winner;
int counter = 0;


//function to draw the grid for tic-tac-toe
void drawMatrix();

//function that prompts a user for their turn to enter a number on the grid
void playerPrompt();

//checks for any horizontal line wins
bool checkHorizontals();

//checks for any vertical column wins
bool checkVerticals();

//checks diagonal wins
bool checkDiagonals();

//loops through the grid to see if any three-in-a-row pattern is present
bool checkForWin();

//function to renew the grid with new values as and when entered by user
void updateGrid(int num);

//function to change the symbol between user turns
void changeSymbol();

//function to print out the winner at the end of the game
void announceWinner();

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

//how to add Player specificity?


void updateGrid(int num){
    //printf("\033c"); //command to clear screen
    char* ptr = &matrix[0][0];
    num = num-1;
    if(*(ptr+num) == symbols[0] || *(ptr+num) == symbols[1]){
        //code for rewriting
        cout << "Cannot overwrite. Enter another number" << endl;
        //keep counter same. shouldn't increment.
        counter = counter - 1;
        //keep symbol same because it is the same turn
    }else{
        *(ptr +num) = symbol;
        system("clear");//clear the screen before re-drawing
        //cout << *(ptr+num) << endl;
        drawMatrix();
        playerDidWin = checkForWin();
        //add a check for win
        //to prevent a message for next user's turn if game has ended
        if((playerDidWin == false) && (counter <8)){
            changeSymbol();//only change symbol on a good turn

        }
        
        
    }
    
}

void changeSymbol(){//have to stop it from outputting another player's turn even after game has ended
    if(symbol == symbols[0]){
        symbol = symbols[1];
        cout << "It's player " << symbol<< "'s turn" << endl; 
    }else{
        symbol = symbols[0];
        cout << "It's player " << symbol<< "'s turn" << endl; 
    }
}

void announceWinner(){
    if(winner == symbols[0]){
        cout << "Player 1 wins!" << endl;
    }else if(winner == symbols[1]){
        cout << "Player 2 wins!" << endl;
    }else if (counter == 11){
        cout << "Exited game." << endl;

    }else{
        cout << "No winner. It's a tie!" << endl;
    }
}
/*
void mainScreen(){
    int choice;
    cout << "|||Welcome|||" << endl;
    cout << "Choose an option: " << endl;
    cout << "1. Two Player Game" << endl;
    cout << "2. One Player Game" << endl;
    cout << "3. Exit" << endl;
    cin >> choice;

    if(choice == 1){
        //execute two player game
    } else if(choice == 2){
        //execute one player game
    }else{
        //exit
    }

}
*/

int main(){
    char a;
    drawMatrix();
    cout << "Player 1, choose symbol: " << endl;
    cin >> symbols[0];
    cout << "Player 2, choose symbol: "<< endl;
    cin >> symbols[1];
    symbol = symbols[0];
    //int counter = 0;//maybe declare this outside so it can be accessed from 
    //other functions
    while(!(playerDidWin == true) && (counter < 9)){
        
        playerPrompt();//call the updateGrid, which calls changeSymbol
        //therefore changeSymbol outputs the message of next player's turn
        //changeSymbol();put this func call in updategrid
        playerDidWin = checkForWin();//prevents from exiting the game before
        counter++;
        //cout << counter << endl;
        
    }
    announceWinner();
    /*
    game = new Game();//save the last updated grid 
    player object: 
    
   */
   

    return 0;

}

/*

TODO:

Agenda for Today - 07/21/2020

1. 1-player game against computer- finish move function 
2. Classes for player profiles and game
3. Grail, Opengl
4.

*/
