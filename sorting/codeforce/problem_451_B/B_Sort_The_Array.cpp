#include <iostream>



void reverseArrayExtraArray(int arr[], int size)
{
    int reversedArr[size];
    for (int i = 0; i < size; i++) {
        reversedArr[i] = arr[size - i - 1];
    }

    // Print reversed array
    std::cout << "Reversed Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << reversedArr[i] << " ";
    }
}


void reverseArray(int arr[], int start, int end)
{
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}



bool checkSort( int arr[],int n,int & first,int & last){
    int state=0;
    first =1;
    last=1;
    for (int i=0; i<n-1;i++){
        if(arr[i+1]>arr[i]){
            std::cout<<"ok"<<std::endl;
        }else{
            std::cout<<"not okay"<<std::endl;
            first=i+1;
            
            if(state==0){

                while(arr[i]>arr[i+1]){
                    std::cout<<"check while decending"<<std::endl;
                //go loop
                i++;
            }
            last=i+1;
            }else{
                return false;
            }
            
            state++;
        }
    }

    //now doing reverse 


    reverseArray(arr,first-1,last-1);

        for(int i=0;i<n;i++){
        std::cout<<arr[i]<<std::endl;
    }
    
    
// int tempArr[last-first+1];
//     for(int i=first-1,j=0;i<last-1;i++){
//         tempArr[j]=arr[i];
//         j++;
//     }
//     for(int i= last-1,j=0;i>first-1;i--){
//         arr[i]=tempArr[j];
//         j++;
//     }

    if(state==0||state ==1){
        int subState=0;
        for (int i=0; i<n-1;i++){
            if(arr[i+1]>arr[i]){
                std::cout<<"ok"<<std::endl;
                
            }else{

               subState++;
            }

        }
        if(subState==0){
            return true;
        }else{
            return false;
        }
    }
    else{
    return false;
    }

}



int main(){
    int n;
    int first,last;
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    // for(int i=0;i<n;i++){
    //     std::cout<<arr[i]<<std::endl;
    // }
 std::cout<<"  "<<std::endl;
        std::cout<< ""<<std::endl;
        std::cout<<""<<std::endl;



    if(checkSort(arr,n,first,last)){
        std::cout<<"yes"<<std::endl;
        std::cout<<first<<std::endl;
        std::cout<<last<<std::endl;
    }else{
        std::cout<<"no"<<std::endl;
    }

    // for (int i=0; i<n;i++){
    //     std::cout<<arr[i]<<std::endl;
    // }

    // reverseArray(arr,2,5);
    //     for(int i=0;i<n;i++){
    //     std::cout<<arr[i]<<std::endl;
    // }
}