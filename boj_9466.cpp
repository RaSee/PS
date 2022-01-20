#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int solve(vector<int>& v){

    vector<int> indgree(v.size());
    queue<int> q;

    for(int i=0;i<v.size();i++){
    	if(v[i] != i)
    		++indgree[v[i]]; 
    }

    for(int i=0;i<v.size();i++){
        if(!indgree[i] && v[i] != i) q.push(i);
    }

    while(q.size()){
        int now = q.front();
        q.pop();

        int next = v[now];
        if(!(--indgree[next]) && v[next] != next){
            q.push(next);
        }
    }
    
    int answer = 0;
    for(int i=0;i<v.size();i++){
        if(!indgree[i] && v[i] != i){answer += 1;}
    }
    return answer;
}

int main(){
    int T; scanf("%d",&T);
    while(T--){
    	vector<int> v;
        int n,t; scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&t);
            t -= 1;
            v.push_back(t);
        }
        printf("%d\n",solve(v));
    }


    return 0;
}