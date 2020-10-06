#include <cstdio>

/*
Solution : 증명

f(n,m) = x 라고 할 때,
f(n/a, m/a)*a = x   ..... 1
gcd (n,m) = 1 인경우, 잘라진 부분을 다시 자르는 경우는 없으므로
자르는 횟수는 m-1번

따라서 f(n, m) = m - 1 (when gcd (n,m ) = 1) ..... 2

1, 2에 의해서 a != 1인 경우는 (즉, gcd(n,m) = a 인경우)
f(n,m) = f(n/a, m/a) * a = (m/a-1)*a = m - a = m - gcd(n,m)

*/


int gcd(int n, int m){
    if(m == 0){
        return n;
    }
    else{
        return gcd(m, n%m);
    }
}

int main(){
    int n,m; scanf("%d%d",&n,&m);
    printf("%d\n", m - gcd(n,m));

    return 0;
}