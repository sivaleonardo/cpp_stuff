//Co Authored by Siva B and Jenn Lloyd
//Game play against computer
#include <iostream>
#include <stdlib.h> 
using namespace std;
char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char symbol;
bool playerDidWin = false;
char symbols[2];
char winner;
int counter = 0;
int comp =0;
int comp_row, comp_col;



//function to draw the grid for tic-tac-toe
void drawMatrix();

//function that prompts a user for their turn to enter a number on the grid

//need updating -only prompt player 1, copmuter automatically goes after
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
//need updating 
//function to change the symbol between user turns

void changeSymbol();

//function to print out the winner at the end of the game
void announceWinner();


void announceWinner(){
    if(winner == symbols[0]){
        cout << "Player 1 wins!" << endl;
    }else if(winner == symbols[1]){
        cout << "Computer wins!" << endl;
    }else if (counter == 11){
        cout << "Exited game." << endl;

    }else{
        cout << "No winner. It's a tie!" << endl;
    }
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
    cout << "Enter number on grid: " << endl;
    cin >> number;
    if(number > 9){
        counter = 10;
    }
    updateGrid(number);
    //didWin(number);
}


bool checkHorizontals(){
    //check the three rows;
    for(int i = 0; i < 3; i++){
        if((matrix[i][0] == matrix[i][1]) && (matrix[i][0] == matrix[i][2])){
            winner = matrix[i][0];
            return true;
            
        }
        
    }
    
    return false;
}

bool checkVerticals(){
    //check the three columns
    for(int j= 0; j < 3; j++){
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
        winner = matrix[0][0];
        return true;
        //check second diagonal
    }else if((matrix[0][2] == matrix[1][1]) && (matrix[0][2] == matrix[2][0])){
        winner = matrix[0][2];
        return true;
    }else{
        return false;
    }
}

bool checkCompleteGrid(){
    int taken = 0;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if((matrix[i][j] == symbols[0]) || (matrix[i][j] == symbols[1])){
                taken += 1;
            }
        }
    }
    if(taken == 9){
        return true;
    }else{
        return false;
    }
}

//room for improvement in terms of more efficient code
bool checkForWin(){
    bool horizontalCheck = checkHorizontals();
    bool verticalCheck = checkVerticals();
    bool diagCheck = checkDiagonals();
    bool checkFinish = checkCompleteGrid();

    if(horizontalCheck == true){
        return true;
    }else if(verticalCheck == true){
        return true;
    }else if(diagCheck == true){
        return true;
    }else if(checkFinish == true){
        return true;
    }else{
        return false;
    }
}

bool isEmpty(char value){
    if((value == symbols[0]) || (value == symbols[1])){
        return false;
    }else{
        return true;
    }
}


bool twoInARow(int i){
    
    
    if((matrix[i][0] == matrix[i][1]) || (matrix[i][0] == matrix[i][2]) || (matrix[i][1] == matrix[i][2])){
        
        return true;
    }
    
    return false;

}

bool twoInAColumn(int j){
    
    if((matrix[0][j] == matrix[1][j]) || (matrix[0][j] == matrix[2][j])){
            return true;
    }
    return false;
}

bool twoInADiagonal(){
    if((matrix[0][0] == matrix[1][1]) || (matrix[0][0] == matrix[2][2]) || (matrix[1][1] == matrix[2][2])){
        return true;
    }else if((matrix[0][2] == matrix[1][1]) || (matrix[0][2] == matrix[2][0]) || (matrix[1][1] == matrix[2][0])){
        return true;
    }else{
        return false;
    }
}

bool isPotentialPattern(){
    bool rowCheck;
    bool colCheck;
    bool diagCheck = twoInADiagonal();
    int row, col;

    //go through rows of grid to see if any instances of two-in-a-row
    for(int i=0; i<3; i++){
        rowCheck = twoInARow(i);
        if(rowCheck == true){
            row = i;
            break;
        }
    }
    //go through the single row to see if third spot is empty
    //return true if empty so computer can move there
    for(int j = 0; j<3; j++){
        if(isEmpty(matrix[row][j] == true)){
            return true;
        }
    }


    //go through columns of grid to see if any instances of two-in-a-column
    for(int j = 0; j<3; j++){
        colCheck = twoInAColumn(j);
        if(colCheck == true){
            col = j;
            break;
        }
    }

    for(int i = 0; i<3; i++){
        if(isEmpty(matrix[i][col] == true)){
            return true;
        }
    }

    return false;

/*
    if((rowCheck == true) || (colCheck == true) || (diagCheck == true)){
        return true;

    }else{
        return false;
    }
*/    

}



void computerMoveRandom(){
    //called for first random move it makes 
    char* ptr = &matrix[0][0];
    bool isTaken = true;
    srand(time(NULL));
    
    while(isTaken){
        //first add a check to see if grid is already complete
        playerDidWin = checkForWin();
        if(playerDidWin == true){
            break;
        }
        //keep generating random number until a place not taken comes up
        comp = rand() % 9;
        cout << comp << endl;
        if(*(ptr+comp) == symbols[0] || *(ptr+comp) == symbols[1]){
            isTaken = true;
        }else{
            isTaken = false;
        }
    }
    *(ptr + comp) = symbols[1];
    
    
}

void computerMoveStrat(){
    
    bool potential = isPotentialPattern();
    char *ptr = &matrix[0][0];
    bool isTaken = true;

    if(potential){
        matrix[comp_row][comp_col] = symbols[1];
    }else{
        while(isTaken){
            playerDidWin = checkForWin();
            if(playerDidWin == true){
                break;
            }
            comp = rand() %9;
            
            if((*(ptr+comp) == symbols[0]) || (*(ptr+comp) == symbols[1])){
                isTaken = true;
            }else{
                isTaken = false;
            }
        }

        *(ptr + comp) = symbols[1];


    }
    

}

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
        *(ptr +num) = symbols[0]; //player 1 turn gets updated 
        //change the symbol
        //computer's move against the player
        playerDidWin = checkForWin();
        computerMoveRandom();
        system("clear");//clear the screen before re-drawing
        //cout << *(ptr+num) << endl;
        drawMatrix();
        playerDidWin = checkForWin();
        //add a check for win
        //to prevent a message for next user's turn if game has ended 
    }
    
}


int main(){
    char a;
    drawMatrix();
    cout << "Player 1, choose symbol: " << endl;
    cin >> symbols[0];
    cout << "Input the Computer's symbol "<< endl;
    cin >> symbols[1];
    
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
    
   

    return 0;

}


