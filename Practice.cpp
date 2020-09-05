using namespace std;
#include <iostream>

int main(){
    char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char* ptr = &matrix[0][0];
        for(int i = 0; i<9; i++){
            //*(ptr+i) = static_cast<char>(i+1);
            //*(ptr+i) = (char)(i+1);
            *(ptr+i) = (char)i;
        }
        
}