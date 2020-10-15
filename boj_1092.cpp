#include <cstdio>
#include <algorithm>

int main(){

    int len_crain, len_box; 
    int crain[50]= {0,}, box[10000] = {0,};
    int index[50] = {0,};
    bool removed[10000]={false,};
    
    scanf("%d",&len_crain);
    for(int i=0;i<len_crain;i++){
        scanf("%d",crain+i);
    }

    scanf("%d",&len_box);
    for(int i=0; i<len_box;i++){
        scanf("%d",box+i);
    }
    std::sort(crain, crain+len_crain);
    std::sort(box  , box+len_box);
    if(crain[len_crain-1]< box[len_box-1]){
        printf("-1\n");
        return 0;
    }
    

    for(int i=0;i<len_crain ;i++) index[i] = len_box-1;
    

    int answer = 1;
    while(1){
        for(int i=len_crain-1;i>=0;i--){
            while(index[i] >= 0 && (removed[index[i]] || crain[i] < box[index[i]])) 
                index[i]--;
            if (index[i] < 0) continue;
            removed[index[i]] = true;
            index[i]--;
        }
        while(index[len_crain-1]>=0 && removed[index[len_crain-1]]) 
            index[len_crain-1]--; 
        if(index[len_crain-1] < 0) break;
        answer++;
    }
    printf("%d\n",answer);
    
    return 0;
}