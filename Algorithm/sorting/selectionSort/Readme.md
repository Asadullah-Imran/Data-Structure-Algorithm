# Selection Sort

initially [5,6,1,3,2,4]
1. firstly go to the index and get perticular value


```c++
for(int i-0; i<n;i++){
  min= arr[i];
  min_index=i;
  for (int j=i+1;j<n;j++){
    if(arr[j]<min){
      min=a[j];
      min_index=j;
    }
    swap(arr[i],arr[min_index])
  }
}

void swap(int *a,int *b){
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}
```

step =1
initially [5,6,1,3,2,4]
i=0 =>[5] then we will search from the next [6] [i+1]
