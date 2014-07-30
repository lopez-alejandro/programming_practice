#include <iostream>
#include <vector>
using namespace std;

void rearrange(vector<int>* A, int index);

int main(void){
    vector<int> A; 
    A.push_back(1);
    A.push_back(6);
    A.push_back(4);
    A.push_back(7);
    A.push_back(2);
    A.push_back(4);
    A.push_back(5);
    A.push_back(11);
    rearrange(&A, 2);
}

void rearrange(vector<int>* A, int index){
    int pivot = (*A)[index];   
    /*
     * keep three smaller subarrays.
     * bottom: [0, smaller-1]
     * middle: [smaller, equal -1]
     * top: [larger+1, size -1]
     */
    int smaller = 0, equal = 0, larger = A->size()-1;

    while(equal <= larger){
        if((*A)[equal] < pivot){
            swap((*A)[smaller++], (*A)[equal++]);
        } else if((*A)[equal] == pivot){
            ++equal;
        } else{
            swap((*A)[equal], (*A)[larger--]);
        }
    }

    for(vector<int>::iterator it = A->begin(); it!= A->end(); ++it){
        cout << *it << " ";
    }
    cout <<endl;
}
