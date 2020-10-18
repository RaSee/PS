#include <iostream>
#include <string>

using namespace std;

struct{
    string text;
    int time;
}typedef history;

history cmd_log[101];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;

    string cmd;
    int time;
    char input;
    int revert;
    cmd_log[0].time = 0;
    for(int i=1;i<=n;i++){
        cin >> cmd;
        if(cmd == "type"){
            cin >> input >> cmd_log[i].time;
            if(i == 0)
                cmd_log[i].text += input;
            else
                cmd_log[i].text = cmd_log[i-1].text + input;
        }
        else{
            cin >> revert >> time;
            int t = time-revert, j=i-1;
            for(j=i-1; j>=0 && cmd_log[j].time >= t; j--);
            if(j >= 0)
                cmd_log[i].text = cmd_log[j].text;
            cmd_log[i].time = time;
        }
    }
    std::cout << cmd_log[n].text;
}