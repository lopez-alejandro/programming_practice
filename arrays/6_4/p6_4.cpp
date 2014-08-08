/*
 * Goal: 
 * Write a function which takes an array of n intergers, where A[i]
 * denotes the maximum you can advance from index i, and returns 
 * whether it is possible to advance to the last index starting
 * from the beginning of the array
 */
#include <iostream>

using namespace std;

bool isPossible(int A[], int n);

int main(void){
    int A[7] = {3,3,1,0,2,0,1};
    
    cout << isPossible(A, 7)<< endl;
}

bool isPossible(int A[], int n){
    int i = A[0];
    int prev = i;
    while(i < n - 1 && i > 0){
        if(A[i] != 0){
            prev = i;
            i += A[i]; 
        }else if(i > 1){
            i--;
        }else{
            i = prev;
        }
    }
    if(i == n -1)
        return true;
    else
        return false;
}
