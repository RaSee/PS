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

void dfs(int now, int depth){

    if(depth == m){
        print_vector();
        return;
    }
    else if(depth > m){
        return;
    }
    //else

    if(now > n) 
        return;
    v.push_back(now);
    dfs(now+1, depth+1);
    v.pop_back();
    dfs(now+1, depth);
    
    return;
}


int main(){
    scanf("%d%d",&n,&m);
    dfs(1, 0);
    return 0;
}