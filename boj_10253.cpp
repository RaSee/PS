#include <cstdio>


int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main(){

    int T; scanf("%d",&T);
    while(T--){
        int a, b, c; scanf("%d%d",&a,&b);
        while(a != 1){
            c = b/a;
            if(b%a) ++c;

            int ta = a*c-b;
            int tb = b*c;
            int g = gcd(ta, tb);
            a = ta/g;
            b = tb/g;
            //printf("    %d  (%d / %d, %d)  \n",c, ta, tb, g);
        }
        printf("%d\n",b);

    }

}