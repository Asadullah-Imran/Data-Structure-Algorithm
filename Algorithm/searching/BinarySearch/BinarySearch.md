# Binary Search
- for binanry serach we first need to  make the array sorted . 
- then we will search
- this search is similar like we are searchig a word in Dictionary




key smaller -> left => high
key larger -> right => low


arr= [5,8,9,13,16,18,21,32,43]

Step =1 :
low index= 0;
total element = n
so high index = n-1

so mid index = (l+h)/2 =4

so arr[mid]= 16
if(key==arr[mid]){
    then return i;
}

step =2
check => 
if(key>arr[mid]) //{ it will shift right .. we will ignore the left part}
 // so new low = mid +1

so new mid index= (l+h)/2 =6.5 => 6

so arr[mid]=21;
if(key==arr[mid]){
    then return i;
}

step =3 

check =>
if(key< arr[mid]) //{ it will shift left .. we will ignore the right part}
 // so new high = mid - 1

so new mid index= (l+h)/2=5

so arr[mid] =18
if(key==arr[mid]){
    then return i;
}

... now it mathced..!!!

arr= [5,8,9,13,16,18,21,32,43]

search key=12;

Step =1 :
low index= 0;
total element = n
so high index = n-1

so mid index = (l+h)/2 =4

so arr[mid]= 16
if(key==arr[mid]){
    then return i;
}

step =2
check => 
if(key< arr[mid]) //{ it will shift left .. we will ignore the right part}
 // so new high = mid -1

high =3;
arr= [5,8,9,13]

so new mid index= (l+h)/2 =1.5 => 1

so arr[mid]=8;
if(key==arr[mid]){
    then return i;
}

step =3 

check =>
if(key> arr[mid]) //{ it will shift right .. we will ignore the left part}
 // so new low = mid + 1

 high =2;
arr= [9,13]

so new mid index= (l+h)/2=2

so arr[mid] =18
if(key==arr[mid]){
    then return i;
}

====> 
now for not matched case....


```c++


```