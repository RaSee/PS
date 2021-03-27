#include <cstdio>


inline int my_min(const int a, const int b){
    return a < b ? a : b;
}


int MAX = 1000000001;

int n,m;
int origin_arr[100000];
int segment_tree[400001];

void make_segment_tree(int now, int start, int end){

    //printf("%d : %d ~ %d\n", now,start, end);
    if(start == end){
        //printf("assign : %d\n",origin_arr[start-1]);
        segment_tree[now]= origin_arr[start-1];
    }
    else{
        int mid = (start+end)/2;
        make_segment_tree(now*2, start, mid);
        make_segment_tree(now*2 + 1, mid+1, end);

        segment_tree[now] = my_min(segment_tree[now*2],
                                   segment_tree[now*2+1]);
    }
}


/*
start, end : segment_tree[now]가 대표하는 지역
head, tail : 주어지는 값
*/
int search(int now, int start, int end, int head, int tail){
    
    //printf("now %d , %d ~ %d, find : %d ~ %d\n",now, start, end, head, tail);
    if(head <= start && end <= tail){
        return segment_tree[now];
    }
    else if(tail < start || end < head )
        return MAX;
    else{
        int mid = (start+end)/2;
        int left = search(now*2, start, mid, head, tail);
        int right = search(now*2+1, mid+1, end, head, tail);
        return my_min(left, right);
    }
}

int main(){

    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++){
        scanf("%d", origin_arr+i);
    }

    int a, b;
    make_segment_tree(1,1,n);


    while(m--){
        scanf("%d%d",&a,&b);
        printf("%d\n",search(1,1,n, a,b));
    }

}