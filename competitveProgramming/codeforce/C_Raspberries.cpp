#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        // cout<<"step "<< 15-t<<" -->  ";
        int n,k;
        cin>>n>>k;
        int min=INT_MAX;
        int max=INT_MIN;
        int evenCount=0;
        bool addOne=false;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]%2==0){
                evenCount++;
            }
            
            int a=arr[i]%k;
            if(a<min){
                min=a;
            }
            if(a==3){
                addOne=true;
            }
            
            if(a>max){
                max=a;
            }
            
            
        }
        if(min==0){
                cout<<min<<endl; 
                continue;
            }
        if(k!=4){
            cout<<k-max<<endl;
            continue;
        }
        if(k==4){
            
            if(evenCount==0){
                if(addOne){
                    cout<<1<<endl;
                }else{

                cout<<2<<endl;
                }
                continue;
            }
            if(evenCount==1){
                cout<<1<<endl;
                continue;
            }
            if(evenCount>1){
                cout<<0<<endl;
                continue;
            }
        }
  
        
    }
}

