#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using std::vector;

struct{
  int r,c,s,d,z,valid;
}typedef shark;


int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,1,-1};
int dd[4] = {1,0,3,2};
int arr[100][100];
vector<shark> sharks;

bool cmp(const shark a, const shark b){
  return a.z < b.z;
}

int main(){

  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int r, c, m; 
  memset(arr, -1, sizeof arr);

  std::cin >> r >> c >> m;
  int v,w,x,y,z;
  int answer = 0;
  for(int i=0;i<m;i++){
    std::cin >> v >> w >> x >> y >> z;
    if(y >= 3)
        sharks.push_back({v-1,w-1,x%(2*(c-1)),y-1,z,1});
    else
        sharks.push_back({v-1,w-1,x%(2*(r-1)),y-1,z,1});
  }
  sort(sharks.begin(), sharks.end(), cmp);

  for(int i=0;i<sharks.size(); i++){
    shark& s = sharks[i];
    arr[s.r][s.c] = i;
  }

  for(int T=0;T<c;T++){
    //catch shark

    for(int i=0;i<r;i++){
      if(arr[i][T]!=-1){
        sharks[arr[i][T]].valid = 0;
        answer += sharks[arr[i][T]].z;
        arr[i][T]=-1;
        break;
      }
    }
    //move sharks
    for(int si=0; si < sharks.size();si++){
      shark& s = sharks[si];
      if(s.valid == 0) continue;
      if(arr[s.r][s.c]== si)
        arr[s.r][s.c] = -1;
      for(int i=0;i<s.s;i++){

        if(s.r + dr[s.d] >= r || s.r + dr[s.d] < 0){
          s.d = dd[s.d];
        }
        if(s.c + dc[s.d] >= c|| s.c + dc[s.d] < 0){
          s.d = dd[s.d];
        }
        s.r += dr[s.d];
        s.c += dc[s.d];
      }
      if(arr[s.r][s.c] < si){
        sharks[arr[s.r][s.c]].valid = 0;
      }
      arr[s.r][s.c] = si;
    }
  }

  std::cout << answer ;

  return 0;
}