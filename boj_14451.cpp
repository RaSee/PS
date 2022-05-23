#include <cstdio>
#include <queue>
using namespace std;

//0:좌, 1:상, 2:우, 3:하
int dc[4]={-1,0,1,0};
int dr[4]={0,-1,0,1};
int n, answer;
char map[21][21];
bool v[20][20][20][20][20][20]; //상r,상c,상d, 우r,우c,우d
struct{ int r; int c; int d; }typedef info;
struct{ info up; info right; }typedef point;

bool check_end_info(const info& i){
    if(i.r == 0 && i.c == n-1) return true;
    else return false;
}

bool check_end(const point& p){
    if(p.up.r == 0 && p.up.c == n-1 &&
       p.right.r == 0 && p.right.c == n-1) 
        return true;
    return false;
}

bool check(int r, int c){
    if(r >= n || c >= n || r < 0 || c < 0) return false;
    if(map[r][c]=='H') return false;
    else return true;
}

void go_straight(info& s){
    if(check_end_info(s)) return;
    if(check(s.r+dr[s.d], s.c+dc[s.d])){
        s.r+=dr[s.d]; s.c+=dc[s.d];
    }
}

//-1 : 좌회전, 1 : 우회전
void turn(info& s, int d){ 
    //if(check_end_info(s)) return;
    s.d = (s.d+4+d)%4; 
}

void put_queue(queue<point>& q, const point& p){
    bool& t = v[p.up.r][p.up.c][p.up.d][p.right.r][p.right.c][p.right.d];
    if(!t){
        t = true;
        q.push({p});
    }
}

int main(){
    
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s",map[i]);
    
    queue<point> q;
    q.push({n-1,0,1,n-1,0,2});
    v[n-1][0][1][n-1][0][2] = true;
    
    while(q.size()){
        int qsize = q.size();
        //print("step : %d\n", answer+1);
        for(int I=0;I<qsize;I++){
            point o = q.front();
            q.pop();
            
            //printf("%d %d %d %d %d %d\n",o.up.r, o.up.c, o.up.d, o.right.r, o.right.c, o.right.d);
            
            if(check_end(o)) {
                printf("%d\n",answer);
                return 0;
            }
            
            //전진
            point p = o;
            go_straight(p.up); go_straight(p.right);
            put_queue(q, p);
            
            //좌
            p = o;
            turn(p.up, -1); turn(p.right, -1);
            put_queue(q,p);
            
            //우
            p = o;
            turn(p.up, 1); turn(p.right, 1);
            put_queue(q,p);
        }
        answer += 1;
    }
    
    printf("-1\n");
    return 0;
}