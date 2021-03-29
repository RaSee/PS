#include <cstdio>
#include <set>

using namespace std;

int main(){
  
  int n,t;
  int left  = 0;
  int right = 0;
  
  int before_mid;
  multiset<int> s;
  
  scanf("%d",&n);
  scanf("%d",&t);
  printf("%d\n",t);
  
  s.insert(t);
  before_mid = t;
  auto it =  s.begin();
  
  for(int i=1;i<n;i++){
    scanf("%d",&t);
    s.insert(t);
    if(t < before_mid){
      left  += 1;
    }
    else{
      right += 1;
    }
    
    if(left - right >= 1){
      left -= 1;
      right += 1;
      --it;
    }
    else if(right -  left >= 2){
      left  +=  1;
      right -=  1;
      ++it;
    }
    
    printf("%d\n",*it);
    before_mid = (*it);
    
    //printf("left :  %d   right : %d  mid  : %d\n",left, right, before_mid);
  }
  
  
  
}