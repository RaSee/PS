#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> graph;

const int INF = 0x10000000;
int item[100];
int max_item[100];
int n, m, r; 


int bfs(int node){
	
	int range[100];
	int answer = item[node];
  
	queue<int> q;
	

  for(int i=0;i<100;i++)
    range[i] = INF;
	
  q.push(node);
  range[node] = 0;

	while(q.size()){
		int now = q.front();
		int now_range = range[now];
		q.pop();
		
    
		for(pair<int, int> next_info : graph[now]){
      int cost = now_range + next_info.second;
			if(cost < range[next_info.first] && cost <= m){
				if(range[next_info.first] == INF){
					answer += item[next_info.first];
				}
        range[next_info.first] = cost;
				q.push(next_info.first);
			}
		}
    
	}
	return answer;
}

int main(){
	
	int answer = 0;
	scanf("%d%d%d",&n,&m,&r);
	
	for(int i=0;i<n;i++)
		scanf("%d",item+i);
	
	graph.resize(n);
	for(int i=0;i<r;i++){
		int a,b,c;
		scanf("%d%d%d", &a,&b,&c);
		graph[a-1].push_back({b-1,c});
		graph[b-1].push_back({a-1,c});
	}
	
	for(int i=0;i<n;i++){
		bool visited[100] = {false,};
		max_item[i] = bfs(i);
		if(answer < max_item[i])
			answer = max_item[i];
	}
	
	printf("%d\n",answer);
	
	
	return 0;
}