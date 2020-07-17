#include <iostream>
using namespace std;
char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char symbol;
bool playerDidWin = false;
char symbols[2];
char winner;

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
void playerPrompt(){
    int number;
    cout << "Enter number on grid: " << endl;
    cin >> number;
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

//room for improvement in terms of more efficient code
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
    }//add another condition for exiting game?
    else{
        return false;
    }
}

void updateGrid(int num){
    //printf("\033c"); //command to clear screen
    switch(num) {
        case 1: if (matrix[0][0] == symbols[0] || matrix[0][0] == symbols[1]){
            cout << "Can't overwrite a number, enter a new one" << endl;
            changeSymbol();
        }
        else{
                matrix[0][0] = symbol;
        }
            break;
        case 2: if (matrix[0][1] == symbols[0] || matrix[0][1] == symbols[1]){
            cout << "Can't overwrite a number, enter a new one" << endl;
            changeSymbol();
        }else{
            matrix[0][1] = symbol;
        }
            break;
        case 3: if (matrix[0][2] == symbols[0] || matrix[0][2] == symbols[1]){
            cout << "Can't overwrite a number, enter a new one" << endl;
            changeSymbol();
        }else{
            matrix[0][2] = symbol;
            
        }
            break;
        case 4: if (matrix[1][0] == symbols[0] || matrix[1][0] == symbols[1]){
            cout << "Can't overwrite a number, enter a new one" << endl;
            changeSymbol();
        }else{
            matrix[1][0] = symbol;
        }
            break;
        case 5: if (matrix[1][1] == symbols[0] || matrix[1][1] == symbols[1]){
            cout << "Can't overwrite a number, enter a new one" << endl;
            changeSymbol();
        }else{ 
            matrix[1][1] = symbol;
            }
            break;
        case 6: if (matrix[1][2] == symbols[0] || matrix[1][2] == symbols[1]){
            cout << "Can't overwrite a number, enter a new one" << endl;
            changeSymbol(); 
            }else{
                matrix[1][2] = symbol;
            }
            break;
        case 7: if (matrix[2][0] == symbols[0] || matrix[2][0] == symbols[1]){
            cout << "Can't overwrite a number, enter a new one" << endl;
            changeSymbol();
            }else{
                matrix[2][0] = symbol;
            }
            break;
        case 8: if (matrix[2][1] == symbols[0] || matrix[2][1] == symbols[1]){
            cout << "Can't overwrite a number, enter a new one" << endl;
            changeSymbol();
            }else {
                matrix[2][1] = symbol;
            }
            break;
        case 9: if (matrix[2][2] == symbols[0] || matrix[2][2] == symbols[1]){
            cout << "Can't overwrite a number, enter a new one" << endl;
            changeSymbol();
            }else{
                matrix[2][2] = symbol;
            }
            break;
        default: cout << "Ending game..." << endl;
            playerDidWin = true;
            break;
    }
    system("clear");//clear the screen before re-drawing
    drawMatrix();

}

void changeSymbol(){
    if(symbol == symbols[0]){
        symbol = symbols[1];
    }else{
        symbol = symbols[0];
    }
}

void announceWinner(){
    if(winner == symbols[0]){
        cout << "Player 1 wins!" << endl;
    }else if(winner == symbols[1]){
        cout << "Player 2 wins!" << endl;
    }else{
        cout << "No winner. It's a tie!" << endl;
    }
}

int main(){
    drawMatrix();
    cout << "Player 1, choose symbol: " << endl;
    cin >> symbols[0];
    cout << "Player 2, choose symbol: "<< endl;
    cin >> symbols[1];
    symbol = symbols[0];
    int counter = 0;
    while(!(playerDidWin == true) && (counter < 9)){
        // printf("\033c"); //command to clear screen
        playerPrompt();
        changeSymbol();
        playerDidWin = checkForWin();//prevents from exiting the game before
        counter++;
        
    }
    announceWinner();
    

    return 0;

}

/*

TODO:

1. Add specifics (Player 1 and Player 2) to each number prompt
2. Need to update exit code. Not working with checkForWin function
3. Back button for history of grid?
4. opengl?
5. Overwriting message not showing because screen keeps clearing after showing message
6. counter can increase to more than 9 in cases where player has
//entered numerous turns trying to overwrite an existing symbol

*/