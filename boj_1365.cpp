#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n; scanf("%d",&n);
  vector<int> lis;
  for(int i=0;i<n;i++){
    int t;scanf("%d",&t);
    int idx = lower_bound(lis.begin(), lis.end(), t) - lis.begin();
    if(idx >= lis.size()) {
      lis.push_back(t);
    }
    if(lis[idx] > t) {
      lis[idx] = t;
    }
  }
  printf("%ld\n",n-lis.size());
}