#include<bits/stdc++.h>
using namespace std;

int meeting(vector<vector<int> > &vec){
    int cabin, minimum;

    sort(vec.begin(), vec.end());
    int i = 0;

    while(i < vec.size()){
        int j = i + 1;
        while(j < vec.size() && vec[i][1] > vec[j][0]){
            ++cabin;
            ++j;

            minimum = min(cabin, minimum);
        }
        i = j;
    }
    return minimum;
}

int main(){

}