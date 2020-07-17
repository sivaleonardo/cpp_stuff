#include <iostream>
#define underline "\033[4m"
using namespace std;
char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char symbol = 'X';

void drawMatrix();
void playerPrompt();
void updateGrid(int num);
void changeSymbol();
bool isFull();


bool isFull(){
    bool full = false;
    cout << "in bool isFull()" << endl;
    cout << full << endl;
    for(int i =0; i<3; i++){
        for(int j=0; j<3; j++){
            if (matrix[i][j] == 'X' || matrix[i][j] == 'O')
                full = true;
            else{
                full = false;
            }
            
        }
    }
    return full;

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
    cout << "Player 1 enter number on grid: " << endl;
    cin >> number;
    updateGrid(number);
    //changeSymbol(symbol);
    
    cout << "Player 2 enter number on grid: "<< endl;
    cin >> number;
    changeSymbol();
    updateGrid(number);
   
    
    
}
/*
bool alreadyTaken(int num){
    switch(num){
        case 1: if (matrix[0][0] == )
    }
}
*/
void updateGrid(int num){
    //printf("\033c"); //command to clear screen

    //check to see spot not already taken by previous move

    switch(num) {
        case 1: if(matrix[0][0] == 'X' || matrix[0][0] == 'O'){
            cout << "Sorry, choose another..\n";
            playerPrompt();
        }
        else{
            matrix[0][0] = symbol;
        }
            break;
        case 2: matrix[0][1] = symbol;
            break;
        case 3: matrix[0][2] = symbol;
            break;
        case 4: matrix[1][0] = symbol;
            break;
        case 5: matrix[1][1] = symbol;
            break;
        case 6: matrix[1][2] = symbol;
            break;
        case 7: matrix[2][0] = symbol;
            break;
        case 8: matrix[2][1] = symbol;
            break;
        case 9: matrix[2][2] = symbol;
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
    while(isFull() == false){
   // printf("\033c"); //command to clear screen
   //cout << underline << "is this underlined?" << endl;
   playerPrompt();
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
1. Stop a user from re-writing over a value that is already 'X' or 'O'. 
2. The rules of tic-tac-toe
3. Check for a win and kick out of the while loop
4. Possibly letting the user their character (if we wanna be extra)
5. Get clear function to work - not see old grids 
*/