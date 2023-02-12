#include<bits/stdc++.h>
using namespace std;

class DisjointSets{
    public:
    DisjointSets(int N);

    int Find(int u);

    void Union(int u, int v);
};

class Edge{
    public:
        int source, destination;
        double weight;

        Edge(int u, int v, double w){
            this->source = u;
            this->destination = v;
            this->weight = w;
        }
};

bool comparator(const Edge& a, const Edge& b){
    return a.weight <= b.weight;
}

class Graph{
    int V, E;
    vector<Edge> edges;
    
    public:
    Graph(int V, int E){
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, double w){
        this->edges.push_back(Edge(u, v, w));
    }
    
    pair<vector<Edge>, double> Kruskal(){
        vector<Edge> result;
        double minWeight = 0.0;

        sort(this->edges.begin(), this->edges.end(), comparator);

        DisjointSets ds(this->V);

        for(auto itr = this->edges.begin(); itr != this->edges.end(); ++itr){
            int u = itr->source, v = itr->destination;

            int parentU = ds.Find(u);
            int parentV = ds.Find(v);

            if(parentU == parentV){
                // u and v are already connected
            }
            else{
                minWeight += itr->weight;
                result.push_back(*itr);
                ds.Union(u, v);
            }
        }
        return {result, minWeight};
    }
};

int main(){

}