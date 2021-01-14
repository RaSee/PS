#include <cstdio>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> v(100000);
bool visited[100000];
int dp[100000];
int get_diameter(int now){
    //printf("%d\n", now);
    int first = 0, second = 0;
    visited[now] = true;
    for(pair<int, int> next_info : v[now]){
        int next = next_info.first;
        if(visited[next])
            continue;
        int cost = get_diameter(next) + next_info.second;
        if(cost > first){
            second = first;
            first = cost;
        }
        else if(cost > second){
            second = cost;
        }
    }
    dp[now] = first + second;
    //printf("%d : %d\n", now, dp[now]);
    return first;
}

int main(){

    int n; scanf("%d", &n);
    int c;
    for(int i=0;i<n;i++){
        scanf("%d",&c);
        while(true){
            int a, b; scanf("%d",&a);
            if (a == -1){
                break;
            }
            scanf("%d",&b);
            v[c-1].push_back({a-1,b});
        }       
    }
    get_diameter(c-1);
    int answer = 0;
    for(int candidate : dp){
        if(candidate > answer) answer = candidate;
    }
    printf("%d\n",answer);
    
    return 0;
}