#include <cstdio>

struct{
    int left;
    int right;
    int parent;
}typedef node;

bool visited[100001];
node graph[100001];

int main(){

    int n; scanf("%d", &n);
    for(int i=0;i<n;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        graph[a].left = b;
        graph[a].right = c;
        graph[b].parent = a;
        graph[c].parent = a;
    }
    
    int end_idx = 1;
    while(1){
        int t = graph[end_idx].right;
        if(t == -1) break;
        else end_idx = t;
    }

    int idx = 1;
    int answer = 0;
    while(1){
        node& now = graph[idx];
        printf("%d\n",idx);
        if(now.left != -1 && !visited[now.left]){
            idx = now.left;
            visited[now.left] = true;
            
            answer++;
        }
        else if(now.right != -1 && !visited[now.right]){
            idx = now.right;
            visited[now.right] = true;
            answer++;
        }
        else if(idx == end_idx){
            break;
        }
        else if(now.parent){
            idx = now.parent;
            answer++;
        }
        else{
            break;
        }
    }
    printf("%d\n",answer);

}