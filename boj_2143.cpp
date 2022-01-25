#include <cstdio>
#include <hash_map>
using namespace std;

int A[1000], B[1000], la,lb; 
int SA[1001], SB[1001];

int main(){
    int target; scanf("%d",&target);
    scanf("%d",&la);
    for(int i=0;i<la;i++) scanf("%d",A+i);
    scanf("%d",&lb);
    for(int i=0;i<lb;i++) scanf("%d",B+i);

    for(int i=0;i<la;i++) SA[i+1] = SA[i] + A[i];
    for(int i=0;i<lb;i++) SB[i+1] = SB[i] + A[i];


    return 0;
}