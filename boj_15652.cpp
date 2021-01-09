#include <cstdio>
#include <vector>

using std::vector;

vector<int> v;
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
    if(now > n) 
        return; 

    v.push_back(now);
    dfs(now);
    v.pop_back();
    dfs(now+1);
    return;
}


int main(){
    scanf("%d%d",&n,&m);
    dfs(1);
    return 0;
}