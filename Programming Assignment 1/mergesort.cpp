#include <bits/stdc++.h>
using namespace std;

//int comparisons = 0;

unsigned long long int merge(int *input, int start, int mid, int end){
    int sub_size = (end - start + 1);
    int *temp = new int[sub_size];
    unsigned long long int comparisons = 0;

    int left = start;
    int right = mid;
    int index = 0;
    while(left < mid && right <= end){
        comparisons++;
        if(input[left] < input[right]){
            temp[index++] = input[left++];
        }
        else{
            temp[index++] = input[right++];
        }
    }

    while(left < mid){
        temp[index++] = input[left++];
    }

    while(right <= end){
        temp[index++] = input[right++];
    }

    for(int i = 0;i < sub_size;i++){
        input[start + i] = temp[i];
    }

    return comparisons;
}

unsigned long long int mergesort(int *input, int start, int end){
    if(start < end){
        int mid = (start + end)/2;
        if((start + end)%2 != 0){
        	mid++;
        }
        return (
            mergesort(input, start, mid - 1) +
                mergesort(input, mid, end) + 
                    merge(input, start, mid, end)
        );
    }
    return 0;
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
    int comparisons = mergesort(input, 0, size-1);
    t2 = clock();
    long long int runtime = ((long long int)t2 - (long long int)t1);
    for(int i = 0;i < size;i++){
        cout<<input[i]<<endl;
    }
    cerr<<"runtime,"<<runtime<<endl;
    cerr<<"comparisons,"<<comparisons<<endl;
    return 0;
}