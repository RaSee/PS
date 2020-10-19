#include <iostream>
#include <queue>

using namespace std;


int dr[4] = {0,0,1, -1};
int dc[4] = {1,-1,0,0};
double arr[4];

bool visited[31][31]={false,};

double DFS(int r, int c, double d, int depth, int n){

    if(visited[r][c])   return 0;
    if(depth == n)      return d;

    visited[r][c] = true;

    double total_d = 0;
    
    for(int j=0;j<4;j++){
        int nextr = r + dr[j];
        int nextc = c + dc[j];
        double nextd = d * arr[j];
        total_d += DFS(nextr, nextc, nextd, depth+1, n);
    }
    visited[r][c] = false;
    return total_d;

}

int main(){

    int n;
    double r = 0;

    std::cin >> n;
    for(int i=0;i<4;i++) {
        std::cin >> arr[i];
        arr[i] /= 100;
    }
    cout<<fixed;
    cout.precision(10);
    cout << DFS(15,15,1.0,0,n);
}