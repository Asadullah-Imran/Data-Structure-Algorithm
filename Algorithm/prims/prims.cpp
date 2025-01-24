#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define V 5


int minKey(vector<int> &key, vector<bool> &msSet){
    int min =INT_MAX;
    int min_index;
    for (int v=0;V<v;v++){
        if(msSet[v]=false && key[v]<min){
            min=key[v];
            min_index=v;
        }
    }
}


void primMST(vector<vector<int>> &graph){
    vector <int> parent(V);
    vector <int> key(V);
    vector<bool>msSet(V);
    for (int i=0;i<V;i++){
        key[i]=INT_MAX;
        msSet[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    for(int count =0; count<V-1;count++){
        int u = minKey(key,msSet);
        msSet[u]=true;
        for(int v=0;v<V;v++){
            if(graph[u][v]<key[v] && graph[u][v] && msSet[v]==false){
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }

}

int main(){
    vector<vector<int>>  graph={{0,2,0,6,0},
    {2,0,3,8,5},
    {0,3,0,0,7},
    {6,8,0,0,9},
    {0,5,7,9,0}};
}