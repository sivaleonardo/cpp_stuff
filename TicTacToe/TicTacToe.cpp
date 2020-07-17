#include <iostream>
#define underline "\033[4m"
using namespace std;
char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char symbol = 'X';
bool playerDidWin = false;

void drawMatrix();
void playerPrompt();
void updateGrid(int num);
void changeSymbol();
bool isFull();



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
    updateGrid(number);
    //didWin(number);
    
}
/*
bool didWin(int num){
    if(symbol == matrix[num-1][num-1] || symbol == matrix[num-1])
}*/
bool checkHorizontals(){
    //bool horizon_val = false;
    for(int i = 0; i < 3; i++){
        if((matrix[i][0] == matrix[i][1]) && (matrix[i][0] == matrix[i][2])){
            return true;
        }
        else{
            return false;
        }
    }
    //return horizon_val;
}

bool checkVerticals(){
    for(int j= 0; j < 3; j++){
        if((matrix[0][j] == matrix[1][j]) && (matrix[0][j] == matrix[2][j])){
            return true;
        }
        else{
            return false;
        }
    }
}

bool checkDiagonals(){
    if((matrix[0][0] == matrix[1][1]) && (matrix[0][0] == matrix[2][2])){
        return true;
    }else if((matrix[0][2] == matrix[1][1]) && (matrix[0][2] == matrix[2][0])){
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
    }
    else{
        return false;
    }
}

void updateGrid(int num){
    //printf("\033c"); //command to clear screen
    switch(num) {
        case 1: if (matrix[0][0] == 'X' || matrix[0][0] == 'O'){
            cout << "Can't overwrite a number, enter a new one" << endl;
            changeSymbol();
        }
        else if(symbol == matrix[0][1] && symbol == matrix[0][2]){
            cout << "player " << symbol << " won" << endl;
            playerDidWin = true;
        }
        else {
                matrix[0][0] = symbol;
        }
            break;
        case 2: if (matrix[0][1] == 'X' || matrix[0][1] == 'O'){
            cout << "Can't overwrite a number, enter a new one" << endl;
            changeSymbol();
        }
       else if(symbol == matrix[0][0] && symbol == matrix[0][2]){
            cout << "player " << symbol << " won" << endl;
            playerDidWin = true;
        }
        else{
            matrix[0][1] = symbol;
        }
            break;
        case 3: if (matrix[0][2] == 'X' || matrix[0][2] == 'O'){
            cout << "Can't overwrite a number, enter a new one" << endl;
            changeSymbol();
        }
        else if(symbol == matrix[0][1] && symbol == matrix[0][0]){
            cout << "player " << symbol << " won" << endl;
            playerDidWin = true;
        }
        else{
            matrix[0][2] = symbol;
            
        }
            break;
        case 4: if (matrix[1][0] == 'X' || matrix[1][0] == 'O'){
            cout << "Can't overwrite a number, enter a new one" << endl;
            changeSymbol();
        }
        else if(symbol == matrix[1][1] && symbol == matrix[1][2]){
            cout << "player " << symbol << " won" << endl;
            playerDidWin = true;
        }
        else{
            matrix[1][0] = symbol;
        }
            break;
        case 5: if (matrix[1][1] == 'X' || matrix[1][1] == 'O'){
            cout << "Can't overwrite a number, enter a new one" << endl;
            changeSymbol();
            }
            else if(symbol == matrix[1][0] && symbol == matrix[1][2]){
                cout << "player " << symbol << " won" << endl;
                playerDidWin = true;
            }
            else { matrix[1][1] = symbol;
            }
            break;
        case 6: if (matrix[1][2] == 'X' || matrix[1][2] == 'O'){
            cout << "Can't overwrite a number, enter a new one" << endl;
            changeSymbol(); 
            }
            else if(symbol == matrix[1][0] && symbol == matrix[1][1]){
                cout << "player " << symbol << " won" << endl;
                playerDidWin = true;
            }
            else {
                matrix[1][2] = symbol;
            }
            break;
        case 7: if (matrix[2][0] == 'X' || matrix[2][0] == 'O'){
            cout << "Can't overwrite a number, enter a new one" << endl;
            changeSymbol();
            }
            else if(symbol == matrix[2][1] && symbol == matrix[2][2]){
            cout << "player " << symbol << " won" << endl;
            playerDidWin = true;
        }
            else {
                matrix[2][0] = symbol;
            }
            break;
        case 8: if (matrix[2][1] == 'X' || matrix[2][1] == 'O'){
            cout << "Can't overwrite a number, enter a new one" << endl;
            changeSymbol();
            }
            else if(symbol == matrix[2][0] && symbol == matrix[2][2]){
            cout << "player " << symbol << " won" << endl;
            playerDidWin = true;
        }
            else {
                matrix[2][1] = symbol;
            }
            break;
        case 9: if (matrix[2][2] == 'X' || matrix[2][2] == 'O'){
            cout << "Can't overwrite a number, enter a new one" << endl;
            changeSymbol();
            }
            else if(symbol == matrix[2][1] && symbol == matrix[2][0]){
            cout << "player " << symbol << " won" << endl;
            playerDidWin = true;
        }
            else { 
                matrix[2][2] = symbol;
            }
            break;
        default: cout << "Ending game..." << endl;
            playerDidWin = true;
            break;
    }
    drawMatrix();

}

void changeSymbol(){
    //cout << "changing symbol " << endl;
    if(symbol == 'X'){
        symbol = 'O';
    }else{
        symbol = 'X';
    }

    //return sym;

}



int main(){
    drawMatrix();
    cout << "Player 1, choose symbol: X or O" << endl;
    cin >> symbol;
    int counter = 0;
    while(!(playerDidWin == true) && (counter < 9)){
        // printf("\033c"); //command to clear screen
        //cout << underline << "is this underlined?" << endl;
        playerPrompt();
        changeSymbol();
        counter++;
    }
    

    return 0;

}

/*
1 | 2 | 3
--|---|--
4 | 5 | 6
--|---|--
7 | 8 | 9


array of length 2;
array[0] = 'X'
array[1] = 'O'

Symbol = array[0];
Symbol = changeSymbol();

char changeSymbol(){
    return array[1-i]
}

TODO:
1. Write function to check for win by checking matrices- specific functions for checking in all directions
2. Possibly letting the user their character (if we wanna be extra)
3. Get clear function to work - not see old grids
*/

//matrix[0][0] - matrix[0][1] - matrix[0][2]
// matrix[i][j] == matrix[i][j+1] == 
// if (symbol == matrix[i][j+1])