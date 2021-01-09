#include <cstdio>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> v, num;
int n, m;

void print_vector(){
    for(int i=0;i<v.size();i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}

void dfs(int now){

    if(v.size() == m){
        print_vector();
        return;
    }
    if(now >= num.size()) 
        return; 

    v.push_back(num[now]);
    dfs(now);
    v.pop_back();
    dfs(now+1);
    return;
}


int main(){
    scanf("%d%d",&n,&m);
    num.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d",&(num[i]));
    }
    std::sort(num.begin(), num.end());
    num.erase(std::unique(num.begin(), num.end()), num.end());
    dfs(0);
    return 0;
}