#include<bits/stdc++.h>
using namespace std;

int minTime(vector<vector<int>> matrix){
    int countFresh = 0;
    int countRotten = 0;
    int result = 0;
    queue<pair<int, int>> getTheRottenPosition;
    int row = matrix.size();
    int col = matrix.size();
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(matrix[i][j] == 0){
                getTheRottenPosition.push({i,j});
            }
            else if(matrix[i][j] == 1){
                countFresh++;
            }
            else if(matrix[i][j] == 2){
                countRotten++;
            }
        }
    }

    if(countFresh == 0) return result;
    int x_axis[4] = {1, -1, 0, 0};
    int y_axis[4] = {0, 0, 1, -1};
    while(!getTheRottenPosition.empty()){
        if(countFresh == 0){
            break;
        }
        int currValue = getTheRottenPosition.size();
        result++;
        for(int i = 0; i < currValue; i++){
            pair<int, int> pos = getTheRottenPosition.front();
            getTheRottenPosition.pop();
        }
    }
}

int main(){

}