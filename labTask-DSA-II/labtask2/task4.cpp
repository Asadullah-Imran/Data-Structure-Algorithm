// Task 4: Captain America's Shield Integrity Check

// During an intense battle, Captain America's shield takes several hits. Each impact is measured and recorded in an array, where each number represents the strength of a hit. To assess the shield's integrity, Captain needs to find the weakest and strongest hits from the recorded data.
// Your mission is to write a program that uses recursion to determine the minimum and maximum values from the array of hits

#include <iostream>
#include <vector>
using namespace std;

void getMinMaxHelper(const vector<int>& v, int index, int& minVal, int& maxVal) {
    if (index == v.size()) {
        return;
    }
    if (v[index] < minVal) {
        minVal = v[index];
    }
    if (v[index] > maxVal) {
        maxVal = v[index];
    }
    getMinMaxHelper(v, index + 1, minVal, maxVal);
}
void getMinMax(const vector<int>& v) {
    if (v.empty()) {
        cout << "The array is empty." << endl;
        return;
    }
    int minVal = v[0]; 
    int maxVal = v[0]; 
    getMinMaxHelper(v, 1, minVal, maxVal); 
    cout << "Minimum Value: " << minVal << endl;
    cout << "Maximum Value: " << maxVal << endl;
}
int main(){
    vector <int> v1 ={1,4,3,-5,-4,8,6};
    getMinMax(v1);
}