#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
int parent[1000001];

void get_answer(int n){
  queue<int> q;

  q.push(n);
  while(q.size()){

    int qsize = q.size();
    while(qsize--){
      int now = q.front();
      q.pop();
      if(now == 1)
        return;
      
      //find next node
      if(now % 2 == 0 && parent[now/2] == 0){
        parent[now/2] = now;
        q.push(now/2);        
      }
      if(now % 3 == 0 && parent[now/3] == 0){
        parent[now/3] = now;
        q.push(now/3);
      }
      if(now -1 >= 1 && parent[now-1] == 0){
        parent[now-1] = now;
        q.push(now-1);
      }
    }
  }
}

int main()
{
  int n; scanf("%d",&n);
  get_answer(n);

  vector<int> path;
  for(int index = 1; index != n; index = parent[index]){
    path.push_back(index);
  }
  path.push_back(n);
  printf("%d\n",path.size()-1);
  for(auto it = path.rbegin(); it != path.rend(); ++it){
    printf("%d ",*it);
  }

  return 0;
}