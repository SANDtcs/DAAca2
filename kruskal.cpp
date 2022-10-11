#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;


class Graph
{
    private:
        int **edges;
        int **mst;
        int num_edges;
        int num_nodes;
        int *parent;
        int index;
        int count;
    public:
        Graph(int,int);
        void addEdge(int,int,int);
        int findset(int);
        void unionset(int,int);
        void kruskals_run();
        void print();
        void sort();
};



Graph::Graph(int n,int e)
{
    num_edges=e;
    num_nodes=n;
    edges=new int*[num_edges];
    mst=new int*[num_nodes-1];
    for(int i=0;i<num_edges;i++)
    {
        edges[i]=new int(3);
    }

    for(int i=0;i<num_nodes-1;i++)
    {
        mst[i]=new int(3);
    }
    parent=new int(num_nodes);
    for(int i=0;i<num_nodes;i++)
    {
        parent[i]=i;
    }
    index=count=0;
}
//Add edge between u and v with a cost of c
void Graph::addEdge(int u,int v,int c)
{
    edges[index][0]=u;
    edges[index][1]=v;
    edges[index][2]=c;
    index++;
}


int Graph::findset(int i)
{
    if(parent[i]==i)
    {
        return i;
    }
    return findset(parent[i]);
}

void Graph::unionset(int u,int v)
{
    parent[u]=parent[v];
}


void Graph::kruskals_run()
{
    int u,v,i,j;
    //sort(edges.begin(),edges.end());

    sort();

    for(int k=0;k<num_edges;k++)
    {
        u=edges[k][0];

        v=edges[k][1];

        i=findset(u);
        j=findset(v);

        if(i!=j)
        {
            mst[count][0]=edges[k][0];
            mst[count][1]=edges[k][1];
            mst[count][2]=edges[k][2];
            count++;
            unionset(i,j);
        }

    }

}

void Graph::sort()
{
    int *temp;
    for(int i=0;i<num_edges;i++)
    {
        for(int j=0;j<num_edges-1;j++)
        {
            if(edges[j][2]>edges[j+1][2])
            {
                temp=edges[j];
                edges[j]=edges[j+1];
                edges[j+1]=temp;
            }
        }
    }
    /*
    for(int i=0;i<num_edges;i++)
    {
        cout<<edges[i][0]<<"-"<<edges[i][1]<<" : "<<edges[i][2]<<"\n";

    }
    */
}

void Graph::print()
{
    cout<<"Edge"<<"\t"<<"Weight\n";
    for(int i=0;i<count;i++)
    {
        cout<<mst[i][0]<<"-"<<mst[i][1]<<":\t"<<mst[i][2]<<"\n";
    }
}


int main()
{
    Graph K(4,5);
    K.addEdge(0,1,10);
    K.addEdge(0,2,21);
    K.addEdge(1,2,18);
    K.addEdge(1,3,22);
    K.addEdge(2,3,13);
    K.kruskals_run();
    K.print();
    return 0;
}
