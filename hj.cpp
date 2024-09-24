#include <iostream>
using namespace std;
void sortTwoPointer(int arr[],int n){
    int l=0,r=n-1,k=0;
    int tempArr[n];
    for (int i=0;i<n;i++){
        tempArr[i]=arr[i];
    }
    while(l<r){
        if(tempArr[l]<=tempArr[r]){
            arr[k]=tempArr[l];
            l++;
        }else{
            arr[k]=tempArr[r];
            r--;
        }
    }
}

int main(){
    int arr[]={3,6,1,2,9,2,3,0,5};
    int n=9;
    cout<<"before sort ->   ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sortTwoPointer(arr,n);
    cout<<"after sort ->  ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;


}