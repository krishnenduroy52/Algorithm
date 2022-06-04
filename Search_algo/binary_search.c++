#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &arr, int key){
    int end = arr.size()-1, start = 0;

    while(start <= end){
        int mid = (start+end)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            end = mid-1;
        }
        else{
            start = mid + 1;
        }
    }
    return -1;
}


int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin>>arr[i];
    }

    // Key 
    int key;
    cin>>key;
    
    int idx = binarySearch(arr, key);
    if(idx != -1){
        cout<<"Found at index "<<idx<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
}