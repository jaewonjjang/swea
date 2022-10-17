#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


#define MAX 16

int N, M, D, max_enemy;

int map[MAX][MAX];

vector<pair<int, int> > arrow;
int arrow_temp[3];
bool check[MAX];

int distance(pair<int, int> a, pair<int, int> b){
    return abs(a.first-b.first) + abs(a.second-b.second);
}

void input(){
    cin >> N >> M >> D;

    cin.ignore();

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> map[i][j];
        }
    }
}

void enemy_move(){

}

bool all_kill(){

    return false;
}


void kill_enemy(){
    int kill_no=0;
    for(int i=0;i<3;i++){
        pair<int, int> arrow_t = make_pair(N+1, arrow_temp[i]);

        arrow.push_back(arrow_t);
    }
    

    
    while(1){

        enemy_move();

        if(all_kill()){
            max_enemy = max(max_enemy, kill_no);
            break;
        }
    }
}

void set_arrow_and_attack(int idx, int cnt){
    if(cnt == 3){
        kill_enemy();
    }
    else{
        for(int i=idx;i<M;i++){
            if(!check[i]){
                check[i] = true;
                arrow_temp[cnt] = i+1;
                set_arrow_and_attack(i, cnt+1);
                check[i] = false;
            }
        }
    }
}

int main(){


    input();

    set_arrow_and_attack(0, 0);

    cout << max_enemy;

    return 0;
}