#include <iostream>
#include <chrono>
#include <iomanip>
#include <math.h>

using namespace std;
using namespace::chrono;

#define min_n 2
#define step 2
#define max_n pow(2,9)


//The following function initializes a matrix of size nxn and initiates
//all elements to random numbers between 0 and n
//void initialize_random_matrix(int*A, int n);

//The following function returns product of two matrices the normal way
int** normal_matrix_multiply(int** A, int** B, int n);

//The following function computes the runtime for performing matrix
//multiplication uding the two methods
void runtime(int** A, int** B, int n, float* t1, float* t2);

//The following function displays all the elements of a nxn matrix
void display_matrix(int** a, int n);

//the following function generates a nxn matrix with elements having
//random value between 1 and n
void initialize_rand_matrix(int** A, int n);

//The following function uses the Strassen algorithm to multiply two 
// nxn matrices A and B
int** strassen_multiply(int** a, int** b, int n);

//The following function outputs the five columns to the console. 
//These include n, runtimes, and theoretical bounds
void output_runtimes(float average_normal, float average_strassen, float*t1, float* t2);



int main(){

    srand(time(NULL));
    float runtime_normal_mult[10], runtime_strassen[10];
    float normal_time_per_item[10];
    float strassen_time_per_item[10];
    float average_item_runtime_normal = 0;
    float average_item_runtime_strassen = 0;
    unsigned int n = min_n;
    unsigned int loop = 0;

    while(n<= max_n){
        int** A = new int*[n];
        for(int i = 0; i<n; i++){
            A[i] = new int[n];
        }
        initialize_rand_matrix(A,n);
        //display_matrix(A,n);

        int** B = new int*[n];
        for(int i = 0; i<n; i++){
            B[i] = new int[n];
        }
        initialize_rand_matrix(B,n);

        runtime(A,B,n,&runtime_normal_mult[loop], &runtime_strassen[loop]);
        normal_time_per_item[loop] = runtime_normal_mult[loop] / (n*n);
        strassen_time_per_item[loop] = runtime_strassen[loop] / (n*n);
    
        n = n*step;
        loop++;

    }
    
    

    for (int i = 0; i<9; i++){
        average_item_runtime_normal += normal_time_per_item[i];
        average_item_runtime_strassen += strassen_time_per_item[i];
    }
    average_item_runtime_normal = average_item_runtime_normal / 9;
    average_item_runtime_strassen = average_item_runtime_strassen / 9;
    

    //cout << "n\t\tRuntime_SQUARE_Matrix\t\tBound_SQUARE_Matrix";
    //cout << "\t\tRuntime_STRASSEN'S_METHOD\t\tBound_STRASSEN'S_METHOD";
    cout << setw(10) << left << "n" << setw(10) << left << "Runtime_SQUARE_MATRIX";
    cout << setw(10) << left << "Bound_SQUARE_MATRIX";
    cout << setw(10) << left << "Runtime_STRASSEN'S_METHOD";
    cout << setw(10) << left << "Bound_STRASSEN'S_METHOD";
    cout << endl;
    
    output_runtimes(average_item_runtime_normal, average_item_runtime_strassen, runtime_normal_mult, runtime_strassen);

    n = 4;
    int** A = new int*[n];
    for(int i = 0; i<n; i++){
        A[i] = new int[n];
    }
    cout << "For n = 4, we have matrix A:" << endl;
    initialize_rand_matrix(A,n);
    display_matrix(A,n);

    int** B = new int*[n];
    for(int i = 0; i<n; i++){
        B[i] = new int[n];
    }
    cout << "And matrix B:" << endl;
    initialize_rand_matrix(B,n);
    display_matrix(B,n);

    int** square_mult_product = new int*[n];
    for(int i = 0; i < n; i++){
        square_mult_product[i] = new int[n];
    }
    square_mult_product = normal_matrix_multiply(A,B,n);
    cout << "The product using square matrix multiplication is:" << endl;
    display_matrix(square_mult_product, n);

    int** strassen_product = new int* [n];
    for(int i = 0; i<n; i++){
        strassen_product[i] = new int[n];
    }
    strassen_product = strassen_multiply(A,B,n);
    cout << "The product using Strassen's Method:" << endl;
    display_matrix(strassen_product,n);


    return 0;

}

void initialize_rand_matrix(int** A, int n){
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

int** normal_matrix_multiply(int** A, int** B, int n){
    
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
    product_one = normal_matrix_multiply(A,B,n);
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

    //base case; need this, otherwise there is error: segmentation fault 11
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

    }

    return c;    
}

//This function has the average time per item as done by Professor in last
//assignment
float time_per_item(float* t1){
    float t2 = 0.0;
    for(int k = 0; k< 9; k++){
        t2 += t1[k];
    }
    t2 = t2/349524.0;
    return t2;
}

void output_runtimes(float average_normal, float average_strassen, float* t1, float* t2){
    int n=2;
    int i = 0;
    while(i<9){
        //cout << n << "\t\t" << t1[i] << "\t\t" << average_normal*n;
        //cout << "\t\t" << t2[i] << "\t\t" << average_strassen*n;
        //cout << endl;
        cout << setw(20) << left << n << setw(20) << left << t1[i];
        cout << setw(20) << left << average_normal * n * n * n  << setw(20) << left << t2[i];
        cout << setw(20) << left << average_strassen * pow(n, 2.81);
        cout << endl;
        i++;
        n = n*2;
    }
}

