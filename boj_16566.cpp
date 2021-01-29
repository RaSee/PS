#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

const int MAX = 4000001;

int arr[4000001];
int n, m, k, bucket_num; 
vector<int> buckets[2001];
vector<int> bucket_index;

void setup(){
  int index=0;
  for(int i=0;i<bucket_num;i++){
    bucket_index.push_back(i);
    for(int j=0;j<bucket_num; j++){
      buckets[i].push_back(arr[index++]);
      if(index >= m){
        return;
      }
    }
  }
}

int main(){
  scanf("%d%d%d",&n,&m,&k);

  int target;

  for(int i=0;i<m;i++) scanf("%d",arr + i);
  sort(arr, arr + m);
  bucket_num = sqrt(m); 
  if(bucket_num*bucket_num != m) bucket_num += 1;
  setup();
  
  vector<int> v;

  while(k--){
    scanf("%d",&target);
    auto it_buckets = bucket_index.begin();
    for(int i=0;i<bucket_index.size();i++){
      
      int now_index = bucket_index[i];
      if((*buckets[now_index].rbegin()) > target){
        auto answer = lower_bound(buckets[now_index].begin(), 
                                  buckets[now_index].end(), 
                                  target);  

        if(*answer == target) ++answer;

        printf("%d\n",*answer);
        buckets[now_index].erase(answer);
        if(buckets[now_index].empty()){
          bucket_index.erase(it_buckets);
        }
        break;
      }
      ++it_buckets;
    }
  }
  return 0;
  
}


/*
int arr[4000000];
int main(){
  set<int> card;
  int n, m, k; scanf("%d%d%d",&n,&m,&k);

  int a,target;
  for(int i=0;i<m;i++){
    scanf("%d",&a);
    card.insert(a);
  }
  for(int i=0;i<k;i++){
    scanf("%d",&target);
    auto it = card.lower_bound(target);
    if(*it == target) ++it;
    printf("%d\n",*it);
    card.erase(it);
  }

  return 0;
}
*/