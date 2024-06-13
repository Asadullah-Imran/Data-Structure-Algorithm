#include <iostream>

void insertionSort(int arr[], int n){
    int key ,j;
    for(int i=1;i<n;i++){
        key= arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j]=key;
    }
}

double gettingAnA(int arr[],int n,int total){
    insertionSort(arr,n);
    for(int i =0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
    double need= (double)(n*4.5)-total;
    if(need<0){
        return 0;
    }else{
    return need;
    }
}

int main(){
    //Taking input from users
    int n;
    std::cin>>n;
    int arr[n];
    int total=0;
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
        total+=arr[i];
    }

    //now getting the result
    double result=gettingAnA(arr,n,total);
    std::cout<<'\n'<<result<<std::endl;

}