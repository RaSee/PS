#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct{
  int parent;
  double x;
  double y;
  double total_cost;
  int total_node;
}typedef Node;

vector<pair<double, pair<int, int>>> vertex;
Node nodes[100];
int n;

int find(int a){
  if(nodes[a].parent==a)
    return a;
  else
    return nodes[a].parent = find(nodes[a].parent);
}

bool merge(int a, int b){
  int a_p = find(a);
  int b_p = find(b);
  Node& a_n = nodes[a_p];
  Node& b_n = nodes[b_p];
  
  if(a_p != b_p){
    a_n.total_cost += b_n.total_cost;
    a_n.total_cost += sqrt(pow(nodes[a].x-nodes[b].x, 2) + pow(nodes[a].y-nodes[b].y, 2));
    a_n.total_node += b_n.total_node;
    b_n.parent = a_p;
    printf("total_node : %d\n",a_n.total_node);
    return true;
  }
  else
    return false;
}

int main(){

  double answer = 0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%lf%lf",&(nodes[i].x), &(nodes[i].y));
    nodes[i].parent = i;
    nodes[i].total_node = 1;
  }


  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      double cost = sqrt(pow(nodes[i].x-nodes[j].x, 2) + pow(nodes[i].y-nodes[j].y, 2));
      vertex.push_back({cost,{i,j}});
    }
  }

  sort(vertex.begin(), vertex.end());

  for(auto it : vertex){
    int f = it.second.first;
    int s = it.second.second;
    double c =it.first;

    bool result = merge(f, s);
    //printf("%d %d %.2f : %d\n", f, s, c , result);
    //printf("%d\n",nodes[find(f)].total_node);
    
    if(nodes[find(f)].total_node == n){
      answer = nodes[find(f)].total_cost;
      break;
    }
  }

  printf("%.2f\n", answer);

  return 0;
}