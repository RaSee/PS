#include <cstdio>
#include <vector>

struct{
    int x;
    int y;
    int r;
}typedef circle;

inline int my_double(int n){
    return n*n;
}

bool is_in_circle(circle c, int x, int y){
    return my_double(c.x - x) + my_double(c.y-y) <= my_double(c.r);
}

int main(){
    int T; scanf("%d",&T);
    while(T--){
        int answer = 0;
        int x1, y1, x2, y2;
        scanf("%d%d%d%d",&x1, &y1, &x2, &y2);
        int n;
        scanf("%d",&n);
        circle c;
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&c.x, &c.y, &c.r);
            bool s = is_in_circle(c, x1, y1);
            bool e = is_in_circle(c, x2, y2);
            if(s != e){
                answer++;
            }
        }
        printf("%d\n",answer);
    }
    return 0;
}