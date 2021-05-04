#include <cstdio>


int tree[4010][4010];
int Lx, Ly, n;

inline int my_max(const int a, const int b){
  return  a > b ? a : b;
}





int lx, ly, lz, px, py;
int answer;
int main(){
  scanf("%d%d%d",&Lx,&Ly,&n);
  while(n--){re
    scanf("%d%d%d%d%d",&lx,&ly,&lz,&px,&py);
    px++, py++;
    int m = get_tree_max(py, ly, px, lx);
    update_tree(py, ly, px, lx, m + lz);
    if(m + lz > answer) answer = m + lz;
  }
  printf("%d\n",answer);
  
}

