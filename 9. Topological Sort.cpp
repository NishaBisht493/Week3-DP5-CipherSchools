#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;

    public:

    void topologicalSort(int source, bool *visited, vector<int> result) {
        visited[source] = true;
        for(auto itr = adj[source].begin(); itr != adj[source].end(); ++itr){
            if(!visited[*itr]){
                topologicalSort(*itr, visited, result);
            }
        }
        result.push_back(source);
    }

    vector<int> topologicalSort(){
        vector<int> result;

        bool * visited = new bool[this->V];
        for(int i = 0; i < this->V; ++i){
            visited[i] = false;
        }

        for(int i = 0; i < this->V; ++i){
            if(!visited[i]){
                topologicalSort(i, visited, result);
            }
        }

        reverse(result.begin(), result.end());
    }
};

int main(){

}