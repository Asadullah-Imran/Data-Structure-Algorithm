#include <iostream>
using namespace std;

int main(){
    int n;
    cin>> n;
    int arr[n];
    int evenCount=0;
    int evenIdx,oddIdx;
    int oddCount=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]%2==0){
            evenCount++;
            evenIdx=i+1;
        }else{
            oddCount++;
            oddIdx=i+1;
        }
    }

    if(evenCount==1){
        cout<<evenIdx;
    }else{
        cout<<oddIdx;
    }


}