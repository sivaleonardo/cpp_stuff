#include <iostream>
using namespace std;

void print (char * str)
{
  cout << str << endl;
}

int main(){
    /*
    char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char* ptr = &matrix[0][0];


        for(int i = 0; i<9; i++){
            //*(ptr+i);
           // *(ptr+i) = (char)(i+1);
           // *(ptr+i) = (char)(i);
            cout << (ptr + i) << endl;
        }
    */
    string variable = "hello world";
    const char* ptr2 = "variable";
    //by default " " strings are const char arrays not strings - need const char* pointers to them not string*
    cout << *ptr2 << endl;
    cout << ptr2 << endl;

    int a[5];
    //a is a pointer
    
  char * c = "sample text";
  //print( const_cast<char *> (c) ); 
   print(c); 
   cout << endl;
   cout << c << endl;
   return 0;

}

