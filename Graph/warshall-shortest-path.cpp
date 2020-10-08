#include <iostream>
#define INFINITY 1000;
using namespace std;
void warshall(int [][4],int [][4]);
int main(){
    int shortestPaths[4][4];
    int adj[][4] = {{7,5,0,0},
                    {7,0,0,2},
                    {0,3,0,0},
                    {4,0,1,0}};
    warshall(adj,shortestPaths);
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++i){
            cout << shortestPaths[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
void warshall(int adj[][4],int w[][4]){
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(adj[i][j])
                w[i][j] = adj[i][j];
            else
                w[i][j] = INFINITY;
        }
    }
    for(int k=0;k<4;++k){
        for(int i=0;i<4;++i){
            for(int j=0;j<4;++i){
                w[i][j] = min(w[i][j],w[i][k] + w[k][j]);
            } 
        }
    }
}