#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 21


typedef struct {
    int r, c, dir, memory;
}bfschk;

int R, C;
char hyuksem[MAX][MAX];
bool visit[MAX][MAX][4][16];
int cur_r;
int cur_c;
int dir;
int memory;

int r_move[4] = {0, 1, 0, -1};
int c_move[4] = {1, 0, -1, 0};
void input();
bool can_exit();

queue<bfschk> forbfs;

int main(){
    input();

    if(can_exit()){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}

void input(){
    cin >> R >> C;

    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin >> hyuksem[i][j];
        }
    }
    bfschk a;
    a.r = 1;
    a.c = 1;
    a.dir = 0;
    a.memory = 0;

    memset(visit, false, sizeof(visit));
    visit[1][1][0][0] = true;
    forbfs.push(a);
}

bool can_exit(){

    while(!forbfs.empty()){
        cur_r = forbfs.front().r;
        cur_c = forbfs.front().c;
        dir = forbfs.front().dir;
        memory = forbfs.front().memory;

        forbfs.pop();

        if(hyuksem[cur_r][cur_c] == '>'){
            dir = 0;
        }
        else if(hyuksem[cur_r][cur_c] == '<'){
            dir = 2;
        }
        else if(hyuksem[cur_r][cur_c] == '^'){
            dir = 3;
        }
        else if(hyuksem[cur_r][cur_c] == 'v'){
            dir = 1;
        }
        else if(hyuksem[cur_r][cur_c] == '_'){
            if(memory==0){
                dir = 0;
            }
            else {
                dir = 2;
            }
        }
        else if(hyuksem[cur_r][cur_c] == '|'){
            if(memory==0){
                dir = 1;
            }
            else {
                dir = 3;
            }
        }
        else if(hyuksem[cur_r][cur_c] == '.'){
            continue;
        }
        else if(hyuksem[cur_r][cur_c] == '@'){
            return true;
        }
        else if(hyuksem[cur_r][cur_c] >= 48 && hyuksem[cur_r][cur_c] <= 57){
            memory = hyuksem[cur_r][cur_c] - 48;
        }
        else if(hyuksem[cur_r][cur_c] == '+'){
            if(memory < 15) memory++;
            else memory = 0;
        }
        else if(hyuksem[cur_r][cur_c] == '-'){
            if(memory > 0) memory--;
            else memory = 15;
        }
        else if(hyuksem[cur_r][cur_c] == '?'){
            for(int i=0;i<4;i++){
                dir = i;
                bfschk b;
                b.r = cur_r + r_move[dir];
                b.c = cur_c + c_move[dir];
                b.dir = dir;
                b.memory = memory;
                if(!visit[b.r][b.c][dir][memory]) {
                    forbfs.push(b);
                    visit[b.r][b.c][b.dir][b.memory] = true;
                }
                continue;
            }
        }
        bfschk b;
        b.r = cur_r + r_move[dir];
        b.c = cur_c + c_move[dir];
        b.dir = dir;
        b.memory = memory;

        if(!visit[b.r][b.c][dir][memory]) {
            forbfs.push(b);
            visit[b.r][b.c][b.dir][b.memory] = true;
        }
    }
    return false;
}