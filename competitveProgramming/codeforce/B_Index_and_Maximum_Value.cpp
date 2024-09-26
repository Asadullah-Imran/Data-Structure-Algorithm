#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        int max=INT_MIN;
        int op;
        cin>>op;
        int arr[n];
        for(int i =0 ; i< n; i++){
            cin>>arr[i];
            if(arr[i]>max){
                max=arr[i];
            }
        }   
        for (int i =0; i< op; i++){
            char ch;
            int low;
            int high;
            cin>>ch;
            cin>> low;
            cin>> high;
            if(max>=low && max<=high){
                if(ch=='+'){
                    max++;
                }else if(ch=='-'){
                    max--;
                }
            }
            cout<<max<<" ";
        }
        cout<<endl;
    }
}