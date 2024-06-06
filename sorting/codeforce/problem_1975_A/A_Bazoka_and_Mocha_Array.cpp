#include <iostream>

bool isIncreasing(int arr[],int n,int & index){
    for (int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            index=i;
            return false;
        }
    }
    return true;
}
bool isDeccreasing(int arr[],int n,int & index){
    for (int i=index;i<n-1;i++){
        if(arr[i]<arr[i+1]){
            index=i;
            return false;
        }
    }
    return true;
}

void splitAndConcat(int arr[],int n,int prevIndex, int index){
    int arr0[prevIndex];
    for(int i=0;i<n-prevIndex;i++){
        if(i<prevIndex){
        arr0[i]=arr[i];
        }
        arr[i]=arr[i+prevIndex];
    }

    for(int i=n-1;i>(n+1)-prevIndex;i--){
        arr[i]=arr0[n-i];
        std::cout<<"arr has "<<arr[i]<<" in index "<< i<<std::endl;   
    }


    

    index++;
    int size=index-prevIndex;
    std::cout<<"size is "<<size<<std::endl;
    int arr2[size];
    for(int i=0;i+size<n;i++){
        if(i<size){
            arr2[i]=arr[i];
        std::cout<<"arr2 has "<<arr2[i]<<" in index "<< i<<std::endl;

        }
        arr[i]=arr[i+size];
        std::cout<<"arr has "<<arr[i]<<" in index "<< i<<std::endl;   
    }
    for(int i=index;i<n;i++){
        arr[i]=arr2[i-index];
    }
}

bool isBazokaAndMocha(int arr[],int n){
    int index=0;
    int prevIndex;
    if(isIncreasing(arr,n,index)){
        //it is fully increasing array
        std::cout<<"already increasing array"<<std::endl;
        return true;
    }else{
        // it is not fully increasing array
        // in index it starts decresing
        // so i will split the array till index.
        std::cout<<"decreasing array index"<< index <<std::endl;
        prevIndex=index;
        //now check how much portion is decreasing
        if(isDeccreasing(arr,n,index)){
            //all are decreasing

        }else{
            std::cout<<"decreasing array ends index"<< index <<std::endl;
            // now split  and concat
            splitAndConcat(arr,n,prevIndex,index);
 std::cout<<"split and concat completed" <<std::endl;
            for(int i=0;i<n;i++){
                std::cout<<arr[i]<<" ";
            }
            if(isIncreasing(arr,n,index)){
                return true;
            }
        }

    }

    return false;
}


int main(){
    int n;
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    if(isBazokaAndMocha(arr,n)){
        std::cout<<"YES";
    }else{
        std::cout<<"NO";
    }
}