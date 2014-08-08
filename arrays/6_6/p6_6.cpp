#include <iostream>
#include <vector>

using namespace std;

void removeDuplicates(vector<int> *A);

int main(void){
    vector<int> A; 
    A.push_back(2);
    A.push_back(3);
    A.push_back(5);
    A.push_back(5);
    A.push_back(7);
    A.push_back(11);
    A.push_back(11);
    A.push_back(11);
    A.push_back(13);
    removeDuplicates(&A);
    return 1;
}

void removeDuplicates(vector<int>*A){
    if(A->size() <= 1){
        cout<<"array has no duplicates"<<endl;
        return;
    }

    int replace = 1;    // index where we will move new numbers to
    int index = 1;      // index used to traverse array
    int currNumber = (*A)[0];     // the last new number we found
    int validNumbers = 1;   // valid numbers in array
    
    while(index < (int)A->size()){
        if((*A)[index] == currNumber){
            (*A)[index] = 0;
        }else if((*A)[index] != currNumber){    // found new number
            validNumbers++;                     // new num, increase num of valid
            currNumber = (*A)[index];           // new number becomes current number
            (*A)[replace] = (*A)[index];        // swap the new number to the back of the sub array of valid integers
            if(index != replace)
                (*A)[index] = 0;
            replace++;
        }
        index++;
    }

    cout << "hello" <<endl;
    for(vector<int>::iterator it = A->begin(); it != A->end(); ++it){
        cout << *it << " ";
    }
    cout <<endl << "number of valid entries: " << validNumbers <<endl;
}
