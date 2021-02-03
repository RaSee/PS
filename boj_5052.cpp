#include <cstdio>

class node{
public:
    node* arr[10];
    bool end;
    void clear(){
        for(int i=0;i<10;i++){
            this->arr[i] = NULL;
        }
        end = false; 
    }
    node(){ this->clear();}
};
node aa[100001];
class trie{
public:
    int idx = 0;
    bool insert(char* a, int n){
        node* now = &(aa[0]);
        node* next;
        for(int i=0;;i++){

            if(a[i]){
                next = now->arr[a[i]-'0'];  
                if(next == 0) {
                    //printf("%d\n", idx);
                    ++idx;
                    now->arr[a[i]-'0'] = &(aa[idx]);
                    now->arr[a[i]-'0']->clear();
                }
                
                now = now->arr[a[i]-'0'];
            }
            else{
                now->end = true;
                for(int i=0;i<10;i++){
                    if(now->arr[i]) return true;
                }
                return false;
            }          
            if(now->end) {
                return true;
            }
        }
    }
    void clear(){
        aa[0].clear();
        idx = 0;
    }
};
trie t;

int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n; scanf("%d",&n);
        char str[11];
        bool flag = false;
        t.clear();

        for(int i=0;i<n;i++){
            scanf("%s",str);
            if(flag) continue;
            //else
            flag = t.insert(str, 0);
        }
        if(flag) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}