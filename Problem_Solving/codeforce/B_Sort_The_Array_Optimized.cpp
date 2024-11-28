#include <iostream>

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


bool checkSort(int arr[],int n, int &first,int &last){

    first= -1; //we set first '-1' because we will use first for a ascending order sorting check
    last=1; //we set the initial value as 1


    for(int i=0;i<n-1;i++){ //this array suppose to be ascending
        if(arr[i]>arr[i+1]){//=> decending order detected!!!!
            //then problem detected 
            // so now we got the starting problem index num
            first=i+1; // so we set first so that we will reverse from this

            break; // if it got problem then it will break .. no need further loop
        }
    }
    if(first==-1){ // it means we do not face any problem 
    // as the number value of index could not be -1 and we also set before start the loop 
    // so in this stage it means the code is already sorted in ascending order.
        first=1;
        return true;
    }
    //if the code access this line that means it is not sorted .  we need to find the last value to reverse only from first to last segment
    // and the unsorted part start from (first-1) index.

    // now we want to get the last number . 
    for (int i=n-1;i>0;i--){ // we are back tracing as decending order
        if(arr[i-1]>arr[i]){  //==> in here we our backtracing face ascending order 

            //that means in here is expected our last number to reverse
            last=i+1;
            break;
        }
    }

    
    // now as we get the first and last .. so now we are reversed
    //for index value we deduct 1 from each index;
    reverseArray(arr,first-1,last-1); // array is reversed

     for(int i=0;i<n-1;i++){ //now we are again checking ascending order
        if(arr[i]>arr[i+1]){ //==> in here it face descending order . 
            //then problem detected 
            // so we can not sort this array. so it remains false
            return false;
        }
    }

    //if code reach this line that means our reverse code is completely ascending order.
    // so we can sort this array. so it remains true;
    return true;

}


int main(){
    int n;
    int first,last;
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    if(checkSort(arr,n,first,last)){
        std::cout<<"yes"<<std::endl;
        std::cout<<first<<std::endl;
        std::cout<<last<<std::endl;
    }else{
        std::cout<<"no"<<std::endl;
    }
}