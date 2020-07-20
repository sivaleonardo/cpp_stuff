//Sivankit Bhanot
//Assignment #1 CPE 593 Algorithms and Data Structures
//Spring 2020
//Instructor: Dr. Aftab Ahmad

//Code snippets have been taken from Dr. Ahmad's code that was shared in class
//In addition, I had tried to implement the code to output data into a .dat file
//Those parts have been commented out as I am working on that part also
//in my own time. 

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <chrono>
#include <fstream>

#include <math.h> // for the log function call in output_run_times function

using namespace std;
using namespace std::chrono;

int min_n = 10;
int step = 10;
int max_n = 200;


//Function to initialize an array to random values between 1 and 10 times 
//the size of the array
void initialize_array(int*A, int n);

//Insertion Sort - Function that implements the insertion sort algorithm
void insertion_sort(int* A, int n);

//Merge
void merge(int* A, int p, int q, int r);

//Merge Sort - Function to implement the merge sort algorithm
void merge_sort(int* B, int q, int r);

//Print_three - Function that takes three random indices for each array
// of size n and prints he index values and the value in that element 
// of the array. The values are chosen from each third of the array. 
void print_three(int* A, int n);

//Runtime - Function calculates the time taken by the computer to sort the 
// array using both the algorithms separately.
void runtime(int* A, int* B, int n1, int n2, float* tinsert, float* tmerge);

//Function takes the array of runtimes and returns the run time per item.
float time_per_item(float* time);

//Function to print all run times and runtime per item. 
void output_run_times(float* IS_item_t, float MS_item_t, float* IS_t, float* MS_t);


//ofstream myfile;
//myfile.open("BhanotS_1.dat");
//myfile << "n" << "\t\t" << "Runtime_Insertion_Sort" << "\t\t" << "Runtime_Merge_Sort" << endl;

//1. (a) - initialize an array of length n with random numbers in each cell
// between the value of 1 and 10n. 
void initialize_array(int* A, int n){
    srand(time(NULL));
    for(int j=0; j < n; j++){
        A[j] = 1 + (rand() % (10*n));
        //cout << A[j] << endl;
    }
}

//1. (b) (i) - Sort the array values using insertion sort algorithm. 
void insertion_sort(int* A, int n){
    int key;
    int i,j;
    for (j=1; j < n; j++){
        key = A[j];
        i = j-1;
        while((i>=0) && A[i]>key){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
        
}

// 1. (b) (ii) - Sort the array values using the merge sort algorithm. Please
// Note: Not entirely sure about the working of this algorithm and so the code
// here has been directly taken from class with Prof. Ahmad. 

void merge(int *A, int p, int q, int r){
    unsigned int n1 = q - p + 1;
    unsigned int n2 = r - q;
    int L[n1], R[n2];
    unsigned int i,j,k;

    for (i=0; i <n1; i++){
        L[i] = A[p+i];
    }
    for (j=0; j<n2; j++){
        R[j] = A[q+1+j];
    }
    i=j=0;
    k=p;

    while (i<n1 && j<n2){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        A[k] = R[j];
        j++;
        k++;
    }

}

void merge_sort(int *B, int p, int r){
    int q;
    if(p<r) {
        q = p + ((r-p)/2);
        merge_sort(B,p,q);
        merge_sort(B, q+1, r);
        merge(B,p,q,r);
    }

}

//1. (b) (iii) - Select three random values in the first third, second third
// and third third and display the corresponding values in these array cells
void print_three(int* A, int n){
    srand(time(NULL));
    int indexzero, indexone, indextwo;
    indexzero = rand()%(n/3);
    indexone = (rand()%(n/3)) + (n/3);
    indextwo = (rand()%(n/3)) + ((2*n)/3);

    //cout << indexzero << "\t" << A[indexzero];
    //cout << "\t" << indexone << "\t" << A[indexone];
    //cout << "\t"<< indextwo << "\t"<< A[indextwo] <<endl;

    //use setw() to set field width to 7 for better indendation and alignment
    cout << setw(7) << left << indexzero << setw(7) << left << A[indexzero];
    cout << setw(7) << left << indexone << setw(7) << left << A[indexone];
    cout << setw(7) << left << indextwo << setw(7) << left << A[indextwo] << endl;

    //myfile.open("BhanotS_1.dat");
    //myfile << "n" << "\t\t" << "Runtime_Insertion_Sort" << "\t\t" << "Runtime_Merge_Sort" << endl;

    //myfile << "Three sorted values chosen randomly" << endl;
    //myfile << indexzero << "\t" << A[indexone] << "\t" << A[indextwo] << endl;
}



//1. (c)
void runtime(int* A, int* B, int n1, int n2, float* tinsert, float* tmerge) {

    //float tinsert, tmerge;
    //ofstream myfile;
    //myfile.open("BhanotS_1.dat");
    //myfile << "n" << "/t/t" << "Runtime_Insertion_Sort" << "/t/t" << "Runtime_Merge_Sort" << endl;

    auto start = high_resolution_clock::now();
    insertion_sort(A,n2);
    print_three(A,n2);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    *tinsert = duration.count();
    
    start = high_resolution_clock::now();
    merge_sort(B, n1, n2);
    print_three(B,n2);
    cout << endl;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    *tmerge = duration.count();

    //myfile << i << "\t\t" << tinsert << "/t/t" << tmerge << endl;

}

//1. (d) ??? How to read for each value of n
float time_per_item(float *time){
    float averagetime = 0.0;
    for (int l = 0; l<20; l++){
        averagetime += time[l];
    }

    averagetime = averagetime / 2100;

    return averagetime;

}

void output_run_times(float IS_item_t, float MS_item_t, float* IS_t, float* MS_t){
    int n = 10;
    int i = 0;

    while(i <20){
        cout << n << "\t\t" << IS_t[i] << "\t\t" << IS_item_t*n*n;
        cout << "\t\t" << MS_t[i] << "\t\t" << MS_item_t*n*log(n);
        cout << endl;
        
        i++;
        n += 10;
    }

}

//copy the array into another one so that the other one can be sorted using
// merge-sort while one is sorted using insertion sort
void assign_array(int* A, int* B, int n){
    for (int i=0; i < n; i++){
        B[i] = A[i];
    }

}


int main(){
    
    srand(time(NULL));
    unsigned int size = min_n;
    unsigned int loop = 0;
    float IS_runtime[20], MS_runtime[20];
    float IS_time_per_item = 0.0;
    float MS_time_per_item = 0.0;
    

    cout << "Three randomly selected array elements in order\n";
    cout << "The first line corresponds to Insertion Sort and\n";
    cout << "the second to Merge Sort";
    cout << "\n\n";
    //cout << "i\tA[i]\tj\tA[j]\tk\tA[k]\n" << endl; 

    //use setw() to set field width to 7 for better indendation and alignment

    cout << setw(7) << left << "i" << setw(7) << left << "A[i";
    cout << setw(7) << left << "j" << setw(7) << left << "A[j]";
    cout << setw(7) << left << "k" << setw(7) << left << "A[k" << endl;

    while(size <= max_n){
        int* a = new int[size];
        int* b = new int[size];

        initialize_array(a, size);
        
        runtime(a,b,0,size, &IS_runtime[loop], &MS_runtime[loop]);
        //myfile << size << "\t\t" << IS_runtime[loop] << "\t\t" << MS_runtime[loop] << endl;

        size = size + step;
        loop++;
    }

    cout << endl;

    IS_time_per_item = time_per_item(IS_runtime);
    MS_time_per_item = time_per_item(MS_runtime);
    cout << "#n" << "\t\t" << "IS_t" << "\t\t" << "IS_O" << "\t\t" <<"MS_t" << "\t\t" << "MS_O" << "\n\n";
    output_run_times(IS_time_per_item, MS_time_per_item, IS_runtime, MS_runtime);

    
    /*for (int i=0; i<num; i++){
        array[i] = 1 + (rand()%(10*num));
    }*/
    //Insertion Sort Algo

    /*for (int i=1; i<num; i++){
        if (array[i-1] > array[i]){
            temp = array[i-1];
            array[i-1] = array[i];
            array[i] = temp;

        }
    }*/

    return 0;

}