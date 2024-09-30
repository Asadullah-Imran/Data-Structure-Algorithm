# include <iostream>

using namespace std;

class Graph{
    int nVertices;
    int **matrix;
    bool directed ;

    public:

    Graph(int n, bool dir){
        nVertices = n;
        directed = dir;

        matrix = new int * [n];
        for(int i= 0;i<n;i++){
            matrix[i]=new int [n];
        }

        for (int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=0;
            }
        }
    }

        void addEdge(int u, int v){
            if(u<0||v<0|| u>=nVertices ||v>= nVertices ) return ;
            matrix [u][v]=1;
            if(!directed){
                matrix[v][u]=1;
            }
        }

        //display graph

        bool hasEdge(int u, int v){
            if(u<0||v<0|| u>=nVertices ||v>= nVertices ) return false;
             if(matrix[u][v]==1)return true;
             return false;
        }        
        void displayGraph(){
            cout<<"Displaying Graph"<<endl;
            for(int i=0;i<nVertices;i++){
                cout<<i<<" -> ";
                for(int j=0;j<nVertices;j++){
                    if(hasEdge(i,j)){
                        cout<<j<<" ";
                    }
                }
                cout<<endl;
            }
        }
};
int main(){
        Graph g(5,false);
        g.addEdge(0,1);
        g.addEdge(0,2);
        g.addEdge(0,3);
        g.addEdge(1,3);
        g.addEdge(1,4);
        g.addEdge(4,3);
        g.addEdge(2,3);

        g.displayGraph();
    }