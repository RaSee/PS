#include <cstdio>
#include <vector>
#include <cmath>


/*
long long 변수에 %d로 -값 대입하면 이상한 값 들어옴
원인 찾기
*/
using namespace std;

int main(){
  int n;
  vector<pair<int, int>> p;
  scanf("%d",&n);

  p.resize(n);
  for(int i=0;i<n;i++){
    scanf("%d%d",&p[i].first, &p[i].second);
  }
  double answer = 0;
  for(int i=1;i<n-1;i++){
    answer += 
    (p[0].first*p[i].second + p[i].first*p[i+1].second + p[i+1].first*p[0].second
    - p[0].second*p[i].first - p[i].second*p[i+1].first - p[i+1].second*p[0].first);
  }
  printf("%.1f\n", abs(answer/2));

  return 0;
}