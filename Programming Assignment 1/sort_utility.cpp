#include <bits/stdc++.h>
using namespace std;

unsigned long long int comparisons = 0;

bool compare(int first, int second){
    comparisons++;
    return first < second;
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
    sort(input, input + size, compare);
    t2 = clock();
    unsigned long long int runtime = ((unsigned long long int)t2 - (unsigned long long int)t1);
    for(int i = 0;i < size;i++){
        cout<<input[i]<<endl;
    }
    cerr<<"runtime,"<<runtime<<endl;
    cerr<<"comparisons,"<<comparisons<<endl;
    return 0;
}