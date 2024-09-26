#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        int dist;
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; 
            if (i > 0) {        
                dist =  abs(arr[i] - arr[i - 1]);
            }
        }
        if(n>2){
            cout<<"NO"<<endl;
        }else 
        if (dist > 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
