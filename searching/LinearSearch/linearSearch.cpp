#include <iostream>


int linearSearch(int arr[], int n, int key){
    for(int i=0; i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}


int main(){

    int arr[10]={2,4,5,6,70,84,32,12,11,23};
    int size= sizeof(arr)/sizeof(arr)[0];
    std::cout<<"Type a number to search: ";
    int searchNum;
    std::cin>>searchNum;
    if(linearSearch(arr,size,searchNum)!=-1){
        std::cout<<"Matched"<<std::endl;
    }else{
        std::cout<<"not Matched"<<std::endl;
    }
}