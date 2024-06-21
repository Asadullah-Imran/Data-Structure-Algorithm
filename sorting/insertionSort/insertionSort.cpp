#include <iostream>

// we want to inster 3;

void insertionSort(int arr[],int n){

  // [5,9,2,7,1,5,6,2,3,4]
  
  // let i = 9; because the element `3` is in the position of index 9 
  // `i = 9`  => is our target which are we gonna insert;

    for(int i=1;i<n;i++){
        //so we are sorting now 
        int key=arr[i]; // beacuse now our key is `3` => which index is 9

        int j=i-1;  // we set j = one less than the i . beacuse we are gonna check before the 3

        // [5,9,2,7,1,5,6,arr[j]=2,||arr[i]=3,4]

        // now  for increasing order we are gonna check is arr[i]<arr[j];    // for not loosing arr[i] we already save it in key.

        //so we are checking if(key less than arr[j]) then it go through the loop and shift  it go after the loop
        while(j>-1 && key<arr[j]){  // j could be -1 after decreasing so we also need to add condtion to prevent that
            
            //now we are going to shift right
            // [5,9,2,7,1,5,6,arr[j]=2,||arr[i]=3,4]
            // i= 9 || j=(i-1)=8
            arr[j+1]=arr[j]; //array is right shifted. for the element of arr[j] only

            j--;

        //if key greater than arr[j] then the loop will break 
        }

        // after the loop break .. 

        // now we insert the key position  in the right place
        arr[j+1]=key;

    }



}


int main(){

// suppose the array is 
int arr[]={5,9,2,7,1,5,6,2,3,4};
int arrLength= sizeof(arr)/sizeof(arr[0]); //this is how you can find the size fo an array
// std::cout<<"array size is "<<arrLength<<std::endl;

//now we are gonna sort the array 
insertionSort(arr,arrLength);

for (int i=0; i < arrLength;i++){
    std::cout<< arr[i]<< ", "; 
}

    std::cout<< std::endl; 
}