#include <iostream>

using namespace std;

struct node
{
    int value;
    node *next;
};
node *createNewNode(int x)
{

    node *newNode = new node();
    newNode->value = x;
    newNode->next = NULL;
    return newNode;
}

class Graph
{
    int nVertices;
    node **adjList;
    bool directed;

public:
    Graph(int n, bool dir)
    {
        nVertices = n;
        directed = dir;

        adjList = new node *[n];

        for (int i = 0; i < n; i++)
        {
            adjList[i] = NULL;
        }
    }

    void addEdge(int u, int v)
    {
        if (u < 0 || v < 0 || u >= nVertices || v >= nVertices)
            return;
        node *newNode = createNewNode(v);
        if (adjList[u] == NULL)
        {
            adjList[u] = newNode;
        }
        else
        {
            newNode->next = adjList[u];
            adjList[u] = newNode;
        }

        if (!directed)
        {
            newNode = createNewNode(u);

            if (adjList[v] == NULL)
            {
                adjList[v] = newNode;
            }
            else
            {
                newNode->next = adjList[v];
                adjList[v] = newNode;
            }
        }
    }

    // display graph

    bool hasEdge(int u, int v)
    {
        if (u < 0 || v < 0 || u >= nVertices || v >= nVertices) return false;
        node *tempNode=adjList[u];
        while(tempNode!=NULL){
            if(tempNode->value==v){
                return true;
            }else {
                tempNode=tempNode->next;
            }

        }
        return false;

    }

    void displayGraph()
    {
        cout<<"Displaying graph"<<endl;
        for( int u=0; u<nVertices;u++){
            cout<<adjList[u]->value<<" -> ";
            node * current = adjList[u];
            while(current!=NULL){
                cout<< current->value<< " ";
                current=current->next;
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph g(5, false);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(4, 3);
    g.addEdge(2, 3);

    g.displayGraph();
}