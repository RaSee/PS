#include <cstdio>
#include <vector>

using std::vector;

/*
Solution : 최적화
경우의 수 조합 시간복잡도를 낮춘다

Naive
    각 자리마다 가능한 숫자들을 뽑은 후 이를 완전탐색으로 조합 : ( O(n^n) ) 
최적화
    각 숫자가 쓰이는 횟수를 통해 수식으로 합을 바로 도출 : O(n^2)
*/

int n;
char light[5][36];

char number[5][10][3] = {
    '#','#','#','.','.','#','#','#','#','#','#','#','#','.','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
    '#','.','#','.','.','#','.','.','#','.','.','#','#','.','#','#','.','.','#','.','.','.','.','#','#','.','#','#','.','#',
    '#','.','#','.','.','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.','.','#','#','#','#','#','#','#',
    '#','.','#','.','.','#','#','.','.','.','.','#','.','.','#','.','.','#','#','.','#','.','.','#','#','.','#','.','.','#',
    '#','#','#','.','.','#','#','#','#','#','#','#','.','.','#','#','#','#','#','#','#','.','.','#','#','#','#','#','#','#',
};

bool is_candidate(int index, int target){

    int start_index = 4*index;
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            if(light[i][start_index+j] == '#' &&
                number[i][target][j] == '.'){
                    return false;
            }
        }
    }
    return true;
}

vector<int> candidate(int index){

    vector<int> ret;
    for(int k=0;k<10;k++){       
        if(is_candidate(index, k)){
            ret.push_back(k);
        }
    }
    return ret;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<5;i++){
        scanf("%s", light[i]);
    }
    vector<vector<int>> v;

    for(int i=0;i<n;i++){
        v.push_back(candidate(i));
        if(v[i].size() == 0){
           printf("-1\n");
           return 0;
        }

    }
    unsigned long long sum = 0;
    unsigned long long c = 1;
    unsigned long long len = 1;

    for(int i=0;i<n;i++){
        c *= (unsigned long long)v[i].size();
    }
    for(int i=n-1;i>=0;i--){
        unsigned long long t = 0;
        unsigned long long tc = c / (unsigned long long)v[i].size();
        for(int j=0;j<v[i].size();j++){
            t += (unsigned long long)v[i][j];
        }
        sum += tc*t*len;
        len *= 10;
    }

    printf("%.5f\n",(double)sum/(double)c);

}
