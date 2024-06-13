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
        arr[j+1]=key;
    }
}

double gettingAnA(int arr[],int n,int total){
    int result=0;
    insertionSort(arr,n);
    //  std::cout << std::endl;
    // for(int i =0;i<n;i++){
    //     std::cout<<arr[i]<<" ";
    // }
    //  std::cout << std::endl;
    double need= (double)(n*4.5)-total;
    if(need<=0){
        return result;
    }else{

        for(int i=0;i<n;i++){
            // while(need>0){
            need-=(5-arr[i]);
            result++;
            // }
            if(need<=0){
                return result;
            }

        }


    // return need;
    }
    return result;
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
    // std::cout<<'\n'<<"Result "<<result<<std::endl;
    std::cout<<result<<std::endl;

}