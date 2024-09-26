#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t-->0){
        int n,k,target,gold,result;
        cin >>n;
        cin >>k;
        gold=0;
        result=0;
        for(int i=0;i<n;i++){
            
            cin>>target;
            if(target>=k){
                gold+=target;
            }else if(target==0 && gold>0){
                result++;
                gold--;
            }
        }
        cout<<result<<endl;
    }
}