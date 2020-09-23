#include <cstdio>
#include <cstring>

int count = 0;
char dict[100000][12] = {0,};
int score[100000] = {0,};

int binary(int target, int start, int end){

    if(start >= end){
        return end;
    }

    int mid = (start+end)/2;
    if(target <= score[mid]){
        if(mid > 0  && score[mid-1] < target){
            return mid;
        }
        else if(mid == 0){
            return mid;
        }
        else{
            return binary(target, start, mid);
        }
    }
    else{
        return binary(target, mid+1, end);
    }
}

int main(){
    int n,m; scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++){
        int a;
        char t[12];
        scanf("%s",t);
        scanf("%d",&a);

        if( count >= 1 && 
            strcmp(t, dict[count]) == 0){
                continue;
        }
        strcpy(dict[count], t);
        score[count++] = a;
    }
    for(int i=0;i<m;i++){
        int a; scanf("%d",&a);
        printf("%s\n", dict[binary(a, 0, count-1)]);
    }

    return 0;
}