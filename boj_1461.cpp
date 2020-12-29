#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n,m; scanf("%d%d",&n,&m);
    vector<int> book_point(n);

    for(int i=0;i<n;i++){
        scanf("%d",&book_point[i]);
    }
    sort(book_point.begin(), book_point.end());
    int answer = 0;


    int i,j;
    for(i= book_point.size()-1; i-m > 0 && book_point[i-m] >0;i-=m){
        answer += book_point[i]*2;
    }
    for(int j= 0; j+m < book_point.size()-1 && book_point[j+m] < 0;j +=m){
        answer += book_point[i]*(-2);
    }

    if(book_point[j] < 0 && book_point[i] > 0){
        answer += min(book_point[j],book_point[i])*2 + max(book_point[j],book_point[i]);
    }
    else if(book_point[j] < 0){
        answer += min(boo)
    }


}