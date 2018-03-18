#include <bits/stdc++.h>
using namespace std;

unsigned long long int comparisons = 0;

void heapify(int *input, int size, int index){
    int curr = index;
    int left = 2 * index + 1, right = 2 * index + 2;

    if(left < size){
        comparisons++;
        if(input[left] > input[curr]){
            curr = left;
        }
    }

    if(right < size){
        comparisons++;
        if(input[right] > input[curr]){
            curr = right;
        }
    }

    if(curr != index){
        int temp = input[index];
        input[index] = input[curr];
        input[curr] = temp;
        heapify(input, size, curr);
    }
}

void heapsort(int *input, int size){
    for(int i=size/2 - 1;i>=0;i--){
        heapify(input, size, i);
    }

    for(int i = size - 1;i>0;i--){
        int temp = input[i];
        input[i] = input[0];
        input[0] = temp;
        heapify(input, i, 0);
    }
}


int main(){
    int size;
    int *input;
    char c;
    cin>>c;
    cin>>size;
    input = new int[size];
    for(int i = 0;i < size;i++){
        cin>>input[i];
    }
    clock_t t1, t2;
    t1 = clock();
    heapsort(input, size);
    t2 = clock();
    long long int runtime = ((long long int)t2 - (long long int)t1);
    for(int i = 0;i < size;i++){
        cout<<input[i]<<endl;
    }
    cerr<<"runtime,"<<runtime<<endl;
    cerr<<"comparisons,"<<comparisons<<endl;
    return 0;
}