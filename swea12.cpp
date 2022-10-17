#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define MAX 51
#define endl "\n"

typedef struct {
    int r, c, m, s, d;
}fireball;

int N, M, K;
int result;

int map[MAX][MAX];
vector<fireball> fb;

int r_move[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int c_move[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void input();
void move_fireball();

int main(){

    input();

    for(int i=0;i<K;i++){
        move_fireball();
    }

    if(fb.empty()){
        cout << 0 << endl;
        return 0;
    }

    for(int i=0;i<fb.size();i++){
        result += fb[i].m;
    }
    cout << result << endl;

    fb.clear();
    return 0;
}

void input(){
    cin >> N >> M >> K;

    memset(map, 0, sizeof(map));

    for(int i=0;i<M;i++){
        fireball fb_temp;
        cin >> fb_temp.r >> fb_temp.c >> fb_temp.m >> fb_temp.s >> fb_temp.d;
        fb.push_back(fb_temp);
        map[fb_temp.r][fb_temp.c]++;
    }
    result = 0;
}

void move_fireball(){
    if(fb.empty()) return;

    for(int i=0;i<fb.size();i++){
        map[fb[i].r][fb[i].c]--;
        fb[i].r += r_move[fb[i].d]*fb[i].s;
        fb[i].c += c_move[fb[i].d]*fb[i].s;
        if(fb[i].r > N ){
            fb[i].r %= N;
        }
        else if(fb[i].r < 1){
            fb[i].r %= N;
            fb[i].r += N;
        }

        if(fb[i].c > N){
            fb[i].c %= N;
        }
        else if(fb[i].c < 1){
            fb[i].c %= N;
            fb[i].c += N;
        }
        map[fb[i].r][fb[i].c]++;
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(map[i][j] >1){
                vector<fireball> temp;
                int weight = 0;
                int speed = 0;
                int dir = 0;

                for(vector<fireball>::iterator iter = fb.begin();iter != fb.end(); ){
                    if(iter->r == i && iter->c == j){
                        temp.push_back(*iter);
                        iter = fb.erase(iter);
                    }
                    else iter++;
                }
                //cout << temp.size() << endl;
                fireball f1, f2, f3, f4;
                f1.r = f2.r = f3.r = f4.r = i;
                f1.c = f2.c = f3.c = f4.c = j;
                for(int k=0;k<temp.size();k++){
                    weight += temp[k].m;
                    speed += temp[k].s;
                    if(temp[i].d % 2){
                        dir++;
                    }
                    else dir--;
                }
                f1.m = f2.m = f3.m = f4.m = weight/5;
                //cout << f1.m << " " << f2.m << " " << f3.m << " " << f4.m << endl;
                f1.s = f2.s = f3.s = f4.s = speed/temp.size();
                //cout << f1.s << " " << f2.s << " " << f3.s << " " << f4.s << endl;
                if(abs(dir) == (temp.size())){
                    f1.d = 0; f2.d = 2; f3.d = 4; f4.d = 6;
                }
                else {
                    f1.d = 1; f2.d = 3; f3.d = 5; f4.d = 7;
                }

                fb.push_back(f1);
                fb.push_back(f2);
                fb.push_back(f3);
                fb.push_back(f4);
                map[i][j]=4;
                temp.clear();
            }
        }
    }
    for(vector<fireball>::iterator iter = fb.begin(); iter != fb.end();){
        if(iter->m ==0){
            iter = fb.erase(iter);
        }
        else iter++;
    }
}