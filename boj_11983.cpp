#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,fx,fy,bx,by;
vector<pair<int, int>> f, b;
int dp[1000][1000];
void make_vector(vector<pair<int, int>>& v, int x, int y){
    char p[1001];
    scanf("%s",p);
    v.push_back({x, y});
    for(int i=0; p[i];i++){
        switch(p[i]){
        case 'E': x += 1; break;
        case 'W': x -= 1; break;
        case 'N': y += 1; break;
        case 'S': y -= 1; break;
        default: break;
        }
        v.push_back({x, y});
    }
}
int get_distance(const pair<int, int>& a, const pair<int, int>& b){
    return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}
int main(){
    scanf("%d%d%d%d%d%d",&n,&m,&fx,&fy,&bx,&by);
    make_vector(f,fx,fy);
    make_vector(b,bx,by);
    //for(int i=0;i<1000;i++) for(int j=0;j<1000;j++) dp[i][j] = 0xfffffffe;
    dp[0][0] = 0;dp[0][i] = dp[0][i-1]
    for(int i=1;i<f.size();i++) dp[i][0] = dp[i-1][0] + get_distance(b[0], f[i]);
    for(int i=1;i<b.size();i++) dp[0][i] = dp[0][i-1] + get_distance(b[i], f[0]);

    for(int i=1;i<f.size();i++){
        for(int j=1;j<b.size();j++){
            int dist = get_distance(f[i], b[j]);
            dp[i][j] = min(dp[i-1][j] + dist, dp[i][j-1]);
        }
    }
    
    for(int i=0;i<f.size();i++){
    	for(int j=0;j<b.size();j++){
    		printf("%d ",dp[i][j]);
    	}
    	printf("\n");
    }

    printf("%d\n",dp[f.size()-1][b.size()-1]);
    return 0;
}