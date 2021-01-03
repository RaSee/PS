#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int T; cin >> T;
    while(T--){
        
        vector<int> indegree, node;
        vector<vector<int>> v;
        vector<int> time;
        int n, k, index; cin >> n >> k;
        
        node.resize(n);
        time.resize(n);
        indegree.resize(n);
        v.resize(n);
        for(int i=0;i<n;i++){
            cin >> node[i];
        }
        int a,b;
        for(int i=0;i<k;i++){
            cin >> a >> b;
            v[a-1].push_back(b-1);
            indegree[b-1]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int now = q.front();
            q.pop();
            node[now] += time[now];

            //else
            for(int i=0;i<v[now].size(); i++){
                int next = v[now][i];

                if(time[next] < node[now]) time[next] = node[now] ;
                indegree[next]--;
                if(indegree[next] == 0){
                    q.push(next);
                }
            }
        }
        cin >> index;
        cout<<node[index-1]<<"\n";
    }
    return 0;
}