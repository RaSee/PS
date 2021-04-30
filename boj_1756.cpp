#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int n,m,t;
vector<int> oven;
int main(){

  scanf("%d%d",&n,&m);
  
  for(int i=0;i<n;i++){
    scanf("%d",&t);
    oven.push_back(t);
    if(i > 0){
      if(oven[i] > oven[i-1]){
        oven[i] = oven[i-1];
      }
    }
  }
  oven.push_back(0);
  reverse(oven.begin(), oven.end());
  
  
  
  auto min_it = oven.begin();
  for(int i=0;i<m;i++){
    scanf("%d",&t);
    
    auto a = lower_bound(min_it, oven.end(), t);
    
    if(min_it == oven.end()){
      printf("0\n");
      return 0;
    }
    printf("get : %d\n", a - oven.begin());
    min_it = (++a);
    
  }
  printf("%d\n", 1 + oven.size() - (min_it - oven.begin()));
  
  return 0;
}