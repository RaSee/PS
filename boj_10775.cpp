#include <vector>
#include <cstdio>
#include <algorithm>


const int INF = -1;
int segment_tree[400000];

/*
int make_tree(int now, int start, int end){

  if(start == end){
    return segment_tree[now] = start;
  }

  int mid = (start+end)/2;
  return segment_tree[now] = std::max(make_tree(now*2, start, mid), 
                                      make_tree(now*2+1, mid+1, end));
}
*/

int update_tree(int now, int start, int end, int index, int target){

  if(target < start || target > end) return INF;
  if(start == end){
    return segment_tree[now] += target;
  }
  //else
  int mid = (start+end)/2;
  return segment_tree[now] = update_tree(now*2, start, mid, index, target) 
                            + update_tree(now*2+1, mid+1, end, index, target);
}

int search(int now, int start, int end, int head, int tail){

  if(head <= start && end <= tail) return segment_tree[now];
  else if(tail < start || end < head) return 0;
  else{
    int mid = (start+end)/2;
    return search(now*2, start, mid, head, tail) 
            + search(now*2+1, mid+1, end, head, tail);
  }
}


int main(){
  
  int g,p,t; scanf("%d%d",&g,&p);
  //std::vector<int> v(g);
  //for(int i=0;i<g;i++) v[i]=i+1;

  //make_tree(1, 1, g);

  for(int i=0;i<p;i++){
    scanf("%d",&t);

    int result = search(1, 1, g, 1, t);
    printf("result : %d\n",result);
    if(result == t){
      printf("%d\n",i);
      return 0;
    }
    else{
      update_tree(1, 1, g, t, 1);
    }
  }
  
  printf("%d\n", p);

}