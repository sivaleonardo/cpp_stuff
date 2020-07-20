#include <iostream>
#include <chrono>
#include <iomanip>
#include <math.h>

using namespace std;
using namespace::chrono;

#define min_n 4
#define step 2
#define max_n pow(2,10)
//int n = min_n;
//int A[n][n];

//The following function initializes a matrix of size nxn and initiates
//all elements to random numbers between 0 and n
//void initialize_random_matrix(int*A, int n);

//The following function returns product of two matrices the normal way
int** normal_matrix_multiply(int** A, int** B);

//The following function performs the matrix multiplication using 
//Strassen's method and divide and conquer 
//int strassen_matrix_multiply(int* A, int* B);

//The following function computes the runtime for performing matrix
//multiplication uding the two methods
void runtime(int* A, int* B, float t1, float t2);

void display_matrix(int** a, int n);

void initialize_rand_matrix(int** A, int n);

int** strassen_multiply(int** a, int** b, int n);




int main(){

    srand(time(NULL));
    float runtime_normal_mult[10], runtime_strassen[10];
    float normal_time_per_item = 0.0;
    float strassen_time_per_item = 0.0;
    unsigned int n = min_n;
    unsigned int loop = 0;

   
    //display_matrix(A,n);

    //cout << endl;

    

    //initialize_rand_matrix(B,n);
    //display_matrix(B,n);

    //cout << endl;

    /*

    int** test = new int*[n];
    for(int i = 0; i<n; i++){
        test[i] = new int[n];
    }
    test[0][0] = 1;
    test[0][1] = 2;
    test[0][2] = 3;
    test[0][3] = 4;
    test[1][0] = 5;
    test[1][1] = 6;
    test[1][2] = 7;
    test[1][3] = 8;
    test[2][0] = 9;
    test[2][1] = 10;
    test[2][2] = 11;
    test[2][3] = 12;
    test[3][0] = 13;
    test[3][1] = 14;
    test[3][2] = 15;
    test[3][3] = 16;
    

    display_matrix(test,n);
    */

    
    //int C[n][n] = normal_matrix_multiply(A,B);
    int** normal_product = new int* [n];
    for(int i=0; i<n; i++){
        normal_product[i] = new int[n];
    }
    normal_product = normal_matrix_multiply(A,B);

    display_matrix(normal_product, n);

    cout << endl;

    int** strassen_product = new int* [n];
    for(int i =0; i<n; i++){
        strassen_product[i] = new int[n];
    }

    strassen_product = strassen_multiply(A, B, n);
    display_matrix(strassen_product, n);

    while(size<= max_n){
        int** A = new int*[n];
        for(int i = 0; i<n; i++){
            A[i] = new int[n];
        }
        initialize_rand_matrix(A,n);

        int** B = new int*[n];
        for(int i = 0; i<n; i++){
            B[i] = new int[n];
        }
        initialize_rand_matrix(B,n);

        run_time(A,B,n,&runtime_normal_mult[loop], &runtime_strassen[loop]);

        n = n*step;
        loop++;

    }




/*
    //initialize random matrix A
   int A[n][n];
   for (int i = 0; i < n; i++){
       for (int j = 0; j < n; j++){
           A[i][j] = 1 + rand() % num;
       }
   }

    //initialize random matrix B
   int B[n][n];
   for (int i = 0; i< n; i++){
       for (int j = 0; j<n; j++){
           B[i][j] = 1 + rand( % num;
       }
   }
   
   //square matrix multiply
   int C[n][n];
   for (int i=0; i<n;i++){
       for (int j=0; j<n; j++){
           C[i][j] = 0;
           for (int k = 0; k<n; k++){
               C[i][j] = C[i][j] + A[i][k] + B[k][j];
           }
       } 
   }

   //Strassen's method
   int D[n][n];

*/   
   
    
    return 0;

}
/*
void initialize_random_matrix(int num){
    int A[num][num];
    for (int i = 0; i < num; i++){
        for(int j = 0; j<num; j++){
            A[i][j] = 1 + rand() % num;
        }
    }

}
*/

void initialize_rand_matrix(int** A, int n){
    //for(int i=0; i<n; i++){
    //    A[i] = new int[n];
    //}
    for (int i = 0; i<n;i++){
        for(int j= 0; j<n;j++){
            A[i][j] = 1 + rand() % n;
        }
    }
}


void display_matrix(int** a, int n){
    for(int i=0; i<n; i++){
        for(int j = 0; j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

}



int** normal_matrix_multiply(int** A, int** B){
    
    
    //int C[n][n];

    int** C = new int* [n];
    for(int i=0; i<n; i++){
        C[i] = new int[n];
    }


    for(int i=0; i<n; i++){
        for(int j = 0; j < n; j++){
            C[i][j] = 0;
            for(int k = 0; k < n; k++){
                C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
            }
        }

    }
    return C;

}

void runtime(int** A, int** B, int n, float* t1, float* t2){

    int** product_one = new int* [n];
    for(int i = 0; i<n; i++){
        product_one[i] = new int[n];
    }
    int** product_two = new int* [n];
    for(int i=0; i<n; i++){
        product_two[i] = new int[n];
    }
    auto start = high_resolution_clock::now();
    product_one = normal_matrix_multiply(A,B);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    *t1 = 1.0*duration.count();

    start = high_resolution_clock::now();
    product_two = strassen_multiply(A,B,n);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    *t2 = 1.0*duration.count();


    


}

int** strassen_multiply(int** a, int** b, int n){
    int** c = new int* [n];
    
    for(int i = 0; i<n; i++){
        c[i] = new int[n];
    }

    if(n == 1){
        c[0][0] = a[0][0] * b[0][0];

    }
    else{

        int newdim = n/2;

    int i,j;
    int** a11 = new int* [newdim];
    for(i = 0; i<newdim; i++){
        a11[i] = new int[newdim];
    }
    for(i=0; i<newdim; i++){
        for(j=0; j<newdim; j++){
            a11[i][j] = a[i][j];
        }
    }
    int** a12 =  new int* [newdim];
    for(i = 0; i< newdim; i++){
        a12[i] = new int[newdim];
    }
    for(i = 0; i<newdim; i++){
        for(j=0; j<newdim; j++){
            a12[i][j] = a[i][j + newdim];
        }
    }

    int** a21 = new int* [newdim];
    for(i = 0; i< newdim; i++){
        a21[i] = new int[newdim];
    }
    for(i=0; i<newdim; i++){
        for(j=0; j<newdim; j++){
            a21[i][j] = a[i + newdim][j];
        }
    }

    int** a22 = new int* [newdim];
    for(i = 0; i < newdim; i++){
        a22[i] = new int[newdim];
    }
    for(i=0; i<newdim; i++){
        for(j=0; j<newdim; j++){
            a22[i][j] = a[i+newdim][j+newdim];
        }
    }

    int** b11 = new int* [newdim];
    for(i = 0; i< newdim; i++){
        b11[i] = new int[newdim];
    }
    for(i=0; i< newdim; i++){
        for(j=0; j<newdim; j++){
            b11[i][j] = b[i][j];
        }
    }

    int** b12 = new int* [newdim];
    for(i=0; i< newdim; i++){
        b12[i] = new int[newdim];
    }
    for(i=0; i<newdim; i++){
        for(j=0; j<newdim; j++){
            b12[i][j] = b[i][j + newdim];
        }
    }

    int** b21 = new int* [newdim];
    for(i = 0; i< newdim; i++){
        b21[i] = new int[newdim];
    }
    for(i=0; i<newdim; i++){
        for(j=0; j<newdim; j++){
            b21[i][j] = b[i+newdim][j];
        }
    }

    int** b22 = new int* [newdim];
    for(i=0; i< newdim; i++){
        b22[i] = new int[newdim];
    }
    for(i=0; i<newdim; i++){
        for(j=0; j<newdim; j++){
            b22[i][j] = b[i+newdim][j+newdim];
        }
    }

    //10 matrices that are the sum or difference of the above
    int** s1 = new int* [newdim];
    for(i=0; i< newdim; i++){
        s1[i] = new int[newdim];
    }
    for(i=0; i<newdim; i++){
        for(j=0; j< newdim; j++){
            s1[i][j] = b12[i][j] - b22[i][j];
        }
    }

    int** s2 = new int* [newdim];
    for(i=0; i<newdim; i++){
        s2[i] = new int[newdim];
    }
    for(i=0; i<newdim; i++){
        for(j=0; j<newdim; j++){
            s2[i][j] = a11[i][j] + a12[i][j];
        }
    }

    int** s3 = new int* [newdim];
    for(i=0; i<newdim; i++){
        s3[i] = new int[newdim];
    }
    for(i=0; i<newdim; i++){
        for(j=0; j<newdim;j++){
            s3[i][j] = a21[i][j] + a22[i][j];
        }
    }

    int** s4 = new int* [newdim];
    for(i=0; i<newdim; i++){
        s4[i] = new int[newdim];
    }
    for(i=0; i<newdim; i++){
        for(j=0; j<newdim; j++){
            s4[i][j] = b21[i][j] - b11[i][j];
        }
    }

    int** s5 =  new int* [newdim];
    for(i=0; i<newdim; i++){
        s5[i] = new int[newdim];
    }
    for(i=0; i<newdim; i++){
        for(j=0; j<newdim; j++){
            s5[i][j] = a11[i][j] + a22[i][j];
        }
    }

    int** s6 = new int* [newdim];
    for(i=0; i<newdim; i++){
        s6[i] = new int[newdim];
    }
    for(i=0; i<newdim; i++){
        for(j=0; j<newdim; j++){
            s6[i][j] = b11[i][j] + b22[i][j];
        }
    }

    int** s7 = new int* [newdim];
    for(i=0; i<newdim; i++){
        s7[i] = new int[newdim];
    }
    for(i=0; i<newdim; i++){
        for(j=0; j<newdim; j++){
            s7[i][j] = a12[i][j] - a22[i][j];
        }
    }

    int** s8 = new int* [newdim];
    for(i=0; i<newdim; i++){
        s8[i] = new int[newdim];
    }
    for(i=0; i<newdim; i++){
        for(j=0; j<newdim; j++){
            s8[i][j] = b21[i][j] + b22[i][j];
        }
    }

    int** s9 = new int* [newdim];
    for(i=0; i<newdim; i++){
        s9[i] = new int[newdim];
    }
    for(i=0; i<newdim; i++){
        for(j=0; j< newdim; j++){
            s9[i][j] = a11[i][j] - a21[i][j];
        }
    }

    int** s10 = new int* [newdim];
    for(i=0; i<newdim; i++){
        s10[i] = new int[newdim];
    }
    for(i=0; i<newdim; i++){
        for(j=0; j<newdim; j++){
            s10[i][j] = b11[i][j] + b12[i][j];
        }
    }

    //seven products p1 to p7, these will be multiplied recursively
    int** p1 = new int* [newdim];
    int** p2 = new int* [newdim];
    int** p3 = new int* [newdim];
    int** p4 = new int* [newdim];
    int** p5 = new int* [newdim];
    int** p6 = new int* [newdim];
    int** p7 = new int* [newdim];
    for(i=0;i<newdim; i++){
        p1[i] = new int[newdim];
        p2[i] = new int[newdim];
        p3[i] = new int[newdim];
        p4[i] = new int[newdim];
        p5[i] = new int[newdim];
        p6[i] = new int[newdim];
        p7[i] = new int[newdim];
    }
    

    p1 = strassen_multiply(a11, s1, newdim);
    p2 = strassen_multiply(s2, b22, newdim);
    p3 = strassen_multiply(s3, b11, newdim);
    p4 = strassen_multiply(a22, s4, newdim);
    p5 = strassen_multiply(s5, s6, newdim);
    p6 = strassen_multiply(s7, s8, newdim);
    p7 = strassen_multiply(s9, s10, newdim);

    

    int** c11 = new int* [newdim];
    int** c12 = new int* [newdim];
    int** c21 = new int* [newdim];
    int** c22 = new int* [newdim];

    for(i = 0; i<newdim; i++){
        c11[i] = new int [newdim];
        c12[i] = new int [newdim];
        c21[i] = new int [newdim];
        c22[i] = new int [newdim];
    }

    for(i = 0; i<newdim; i++){
        for(j=0; j<newdim; j++){
            c11[i][j] = p5[i][j] + p4[i][j] - p2[i][j] + p6[i][j];
            c12[i][j] = p1[i][j] + p2[i][j];
            c21[i][j] = p3[i][j] + p4[i][j];
            c22[i][j] = p5[i][j] + p1[i][j] - p3[i][j] - p7[i][j];
        }
    }

    

    //form the C product matrix using the smaller submatrices
    for(i=0; i<newdim; i++){
        for(j=0; j<newdim; j++){
            c[i][j] = c11[i][j];
            c[i][j+newdim] = c12[i][j];
            c[i+newdim][j] = c21[i][j];
            c[i+newdim][j+newdim] = c22[i][j];
        }
    }

    /*
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    */
    


    }

    return c;
    
        
}


//int strassen_matrix_multiply(int*A[][], int* B[][]){

//}

