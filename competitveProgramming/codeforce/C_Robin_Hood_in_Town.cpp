#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin>>t;
    
    while (t-- > 0) {
        int n;
        cin >> n;
        long long arr[n], sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        if(n==1 ) {
            cout << -1 << endl;
            continue;
        } 
        if(n==2){
            
            cout << -1 << endl;
            continue;
            
        }
        sort(arr, arr + n);
        
        float avg = sum / (float)n;
        float halfAvg = avg / 2;
        int unhappyPeople = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] < halfAvg) {
                unhappyPeople++;
            } else {
                break;
            }
        }
        if (unhappyPeople > n / 2) {
            cout << 0 << endl;
        } else {
            long long minWealth = arr[n / 2];
            long long p = minWealth * 2LL * n;
            long long x = p - sum + 1;
            cout << x << endl;
        }
    }
}
