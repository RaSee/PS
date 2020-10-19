#include <iostream>

using namespace std;

int x_station, y_station;
int x_start, y_start, x_delta, y_delta;
int get_distance(int x1, int y1){
    return (x1-x_station)*(x1-x_station) + (y1-y_station)*(y1-y_station);
}

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main(){
    cin >> x_station >> y_station;
    cin >> x_start >> y_start >> x_delta >> y_delta;


    if(x_delta == 0 && y_delta == 0){
        cout<< x_start<<" "<<y_start <<"\n";
        return 0;
    }

    //이전엔 더 멍청하게 풀었음
    if(x_delta*y_delta){
        int g = gcd(abs(x_delta), abs(y_delta));
        x_delta /= g;
        y_delta /= g;
    }
    else{
        //여기 조건 놓쳐서 틀림
        if(x_delta!=0) x_delta = 1;
        else y_delta = 1;

    }

    int x_candidate = x_start, y_candidate = y_start;
    int d = get_distance(x_candidate, y_candidate);
    while(true){
        
        int x_next = x_candidate + x_delta;
        int y_next = y_candidate + y_delta;
        
        int td = get_distance(x_next, y_next);
        
        //cout << x_next << " "<<y_next <<" "<<td<<"\n";

        if(td < d){
            d = td;
            x_candidate = x_next;
            y_candidate = y_next;
        }
        else{
            break;
        }
    }
    cout << x_candidate<< " "<<y_candidate;

    return 0;
}