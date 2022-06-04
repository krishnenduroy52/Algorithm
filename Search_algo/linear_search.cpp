#include<iostream>
#include<vector>
using namespace std;

int linearSearch(vector<int> &arr, int key){
    for(int i = 0; i < arr.size(); ++i){
        if(arr[i] == key){
            return i;
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
    
    int idx = linearSearch(arr, key);
    if(idx != -1){
        cout<<"Found at index "<<idx<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
}