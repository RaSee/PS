#include <cstdio>
#include <set>
#include <vector>
int n,m, cow[9];
bool is_not_prime[9001];
std::set<int> s;
std::vector<int> v;
/*
Solution
1. DFS
2. 에라토스테네스의 체
3. 중복 불가 container - set or sort
*/

void DFS(int start, int sum, int depth){

    if(start >= n){
        if(depth == m){
            if(!is_not_prime[sum]){
                s.insert(sum);
            }
        }
        return;
    }
    DFS(start+1, sum, depth);
    for(int i=start; i<n;i++){
        sum += cow[i];
        DFS(i+1, sum, depth+1);
        sum -= cow[i];
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d", cow+i);
    }
    for(int i=2;i<9001;i++){
        if(is_not_prime[i]) continue;
        for(int j=2; j*i<= 9000;j++){
            is_not_prime[j*i] = true;
        }
    }
    DFS(0,0,0);
    if(s.size() == 0){
        printf("-1");
    }
    else{
        for(auto it = s.begin(); it != s.end(); ++it){
            printf("%d ",*it);
        }
    }
    return 0;
}