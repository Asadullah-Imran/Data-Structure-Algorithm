

#include <iostream>
using namespace std;
int doOperation(int arr[], int size,int max,char ch, int low, int high){
    if (low>max) {
        return max;}
    int tempMax=INT_MIN;
    for(int i=0; i<size;i++){
        if(low<=arr[i] && arr[i]<=high){
            if(ch=='+'){
                arr[i]++;
            }else if(ch=='-'){
                arr[i]--;
            }
        }
        if(arr[i]>tempMax){
            tempMax=arr[i];
        }
    }
     return tempMax;
}
int main(){
    int t;
    cin >> t;
 
    while(t-->0){
 
        int n;
        cin>>n;
 
        int max=INT_MAX;
        int op;
        cin>>op;
        int arr[n];
        int arrOp[op];
        for(int i =0 ; i< n; i++){
            cin>>arr[i];
        }
          char ch;
        int low;
        int high;
        
        cin>>ch;
        cin>> low;
        cin>> high;
        max=doOperation(arr,n,max,ch,low,high);
        arrOp[0]=max;
        for(int i=1;i<op;i++){
            cin>>ch;
            cin>> low;
            cin>> high;

            if(max<low){
                // arrOp[i]=max;
            }else if(max>=low && max<=high){
                if(ch=='+'){
                    max++;
                }else if(ch=='-'){
                    max--;
                }
            }else{
                max=doOperation(arr,n,max,ch,low,high);
            }
            arrOp[i]=max;
            
        }
        for(int i=0;i<op;i++){
            cout<<arrOp[i]<<" ";
        }
        cout<<endl;
    }
}