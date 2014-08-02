/*
 * Goal:
 * create a function that takes an input an Array A of
 * digits encoding a decimal numer D and updates A to 
 * represent the number D + 1
 */
#include <iostream>
#include <deque>

using namespace std;

void incrementInteger(deque<int> *A);

int main(void){
    deque<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(9);
    incrementInteger(&A);
    return 0;
}

// increments the interger represented by the Array A by one.
// for example if integer was (1,2,9) result is (1,3,0)
// note this implementation does not account for when incrementing the
// number results in a number with digits n+1 such as (9,9,9). result will be zero!
void incrementInteger(deque<int> *A){
    // iterate through the entire array backwards and stop when rit is not 9  
    deque<int>::reverse_iterator rit = A->rbegin();

    while(rit != A->rend()){
        int num = *rit;
        if(num == 9){
            *rit = 0;
            ++rit;
        }else{
            *rit += 1;
            // end the loop
            rit = A->rend();
        }
    }
    
    // increase size of deque by 
    if(A->front() == 10){
        A->front() = 0;
        A->push_front(1);
    }

    
    // print out the results
    for(deque<int>::iterator it = A->begin(); it !=  A->end(); ++it){
        cout << *it << ",";
    }
    cout <<endl;
}
