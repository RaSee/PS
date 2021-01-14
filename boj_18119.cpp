#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline int get_known_words(vector<int>& dict, int mask){

    int forgotten_workds = 0;
    for(int alpah : dict){
        if(alpah & mask) forgotten_workds += 1;
    }

    return dict.size() - forgotten_workds;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    vector<int> alpha;
    int mask = 0;
    cin >> n >> m;
    alpha.resize(n); 

    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(char c : s){
            alpha[i] |= (1<<(c-'a'));
        }
    }


    for(int i=0;i<m;i++){
        int op;
        char target;
        cin >> op >> target;
        mask ^= (1<<(target - 'a'));

        cout<< get_known_words(alpha, mask)<<"\n";
    }

    

    return 0;
}