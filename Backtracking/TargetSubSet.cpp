#include<bits/stdc++.h>
using namespace std;

void subSet(vector<int> &arr, int idx, string ans, int sum, int target){
    if(sum > target) return;
    if(idx >= arr.size() && sum != target) return;

    if(sum == target && idx == arr.size()){
        cout<<ans<<"End"<<endl;
        return;
    }
    string a = to_string(arr[idx]);

    //include idx th element
    subSet(arr, idx+1, ans+a+"->", sum+arr[idx], target);

    //not-include idx th element
    subSet(arr, idx+1, ans, sum, target);
}

int main(){
    int n, target;
    cout<<"Enter no of Element: "<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array Elements: "<<endl;
    for(int i= 0; i <n; i++) cin>>arr[i];

    cout<<"Enter the target: "<<endl;
    cin>>target;
    subSet(arr, 0, "", 0, target);
}