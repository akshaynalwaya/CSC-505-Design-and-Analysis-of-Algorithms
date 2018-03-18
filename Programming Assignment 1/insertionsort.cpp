#include <bits/stdc++.h>
using namespace std;

void insertionsort(int *input, int size, unsigned long long int &comparisons){
    for(int i = 1;i < size;i++){
        for(int j = i-1;j >= 0;j--){
            comparisons++;
            if(input[j] > input[j+1]){
                int temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;
            }else{
                break;
            }
        }
    }
}

int main(){
    int size;
    unsigned long long comparisons = 0;
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
    insertionsort(input, size, comparisons);
    t2 = clock();
    long long int runtime = ((long long int)t2 - (long long int)t1);
    for(int i = 0;i < size;i++){
        cout<<input[i]<<endl;
    }
    cerr<<"runtime,"<<runtime<<endl;
    cerr<<"comparisons,"<<comparisons<<endl;
    return 0;
}