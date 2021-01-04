#include <iostream>
#include <cmath>

using namespace std;

int n;
int arr[128][128] = {0,};
int answer[2] = {0,};

int check(int a, int b, int c, int d){
    
    int num = arr[a][b];
    bool flag = false;
    for(int i=a; i<=c;i++){
        for(int j=b;j<=d;j++){
            if(num != arr[i][j]){
                return 0;
            }
        }
    }
    return 1;
}

void dnq(int a, int b, int c, int d){

    if(a == c && b == d){
        answer[arr[a][b]]++;
        return;
    }

    int count = check(a,b,c,d);
    if(count > 0){
        answer[arr[a][b]]++;
        return;
    }
    else{
        int e = (int)((a+c)/2);
        int f = (int)((b+d)/2);
        dnq(a,b,e,f);
        dnq(a,f+1, e,d);
        dnq(e+1,b,c,f);
        dnq(e+1,f+1, c,d);
    }
}

int main(){
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    dnq(0,0,n-1,n-1);
    cout<<answer[0]<<"\n"<<answer[1]<<"\n";


    return 0;
}