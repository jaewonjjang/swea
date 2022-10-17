#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define MAX 21

typedef struct {
    int x;
    int y;
    int dir;
}pos;

void input();
void wind();
void modi_temperature();
void temp_down();
void chocolate();
bool all_temp();

int choco;
int R, C, K, num_wall;
int room[MAX][MAX];
int mark_room[MAX][MAX];
vector<pos> wall;
vector<pos> heater;
vector<pos> temp_room;
deque<pos> heating_room;

//int x_move[4][25] = {{0, -1, 0, 1, -2, -1, 0, 1, 2, -3, -2, -1, 0, 1, 2, 3, -4, -3, -2, -1, 0, 1, 2, 3, 4}, // right
//                    {0, -1, 0, 1, -2, -1, 0, 1, 2, -3, -2, -1, 0, 1, 2, 3, -4, -3, -2, -1, 0, 1, 2, 3, 4}, // left
//                    {-1, -2, -2, -2, -3, -3, -3, -3, -3, -4, -4, -4, -4, -4, -4, -4, -5, -5, -5, -5, -5, -5, -5, -5, -5}, //up
//                    {1, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5}}; //down

//int y_move[4][25] = {{1, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5},
//                    {-1, -2, -2, -2, -3, -3, -3, -3, -3, -4, -4, -4, -4, -4, -4, -4, -5, -5, -5, -5, -5, -5, -5, -5, -5},
//                    {0, -1, 0, 1, -2, -1, 0, 1, 2, -3, -2, -1, 0, 1, 2, 3, -4, -3, -2, -1, 0, 1, 2, 3, 4},
//                    {0, -1, 0, 1, -2, -1, 0, 1, 2, -3, -2, -1, 0, 1, 2, 3, -4, -3, -2, -1, 0, 1, 2, 3, 4}};

//int temp_add[25] = {5, 4, 4, 4, 3, 3, 3, 3, 3, 2, 2, 2, 2, 
                    2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int x_move[4][3] = {{-1, 0, 1}, {-1, 0, 1}, {-1, -1, -1}, {1, 1, 1}};
int y_move[4][4] = {{1, 1, 1}, {-1, -1, -1}, {-1, 0, 1}, {-1, 0, 1}};


int x_dir[4][1] = {0, 0, -1, 1};
int y_dir[4][1] = {1, -1, 0, 0};

int main(){

    input();

    while(1){
        wind();

        modi_temperature();

        temp_down();

        chocolate();

        if(all_temp()){
            break;
        }
    }
    cout << choco << endl;

    return 0;
}

void input(){
    cin >> R >> C >> K;

    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin >> room[i][j];
            if(room[i][j]==5){
                pos t_r;
                t_r.x = i;
                t_r.y = j;
                t_r.dir = 0;
                temp_room.push_back(t_r);
                room[i][j]=0;
            }
            else if(room[i][j] <= 4 && room[i][j] >= 1){
                pos h_r;
                h_r.x = i;
                h_r.y = j;
                h_r.dir = room[i][j];
                heater.push_back(h_r);
                room[i][j]=0;
            }
        }
    }

    cin >> num_wall;

    pos w;
    for(int i=0;i<num_wall;i++){
        cin >> w.x >> w.y >> w.dir;
        wall.push_back(w);
    }


    choco=0;
}

void wind(){
    int i, j;

    for(i=0;i<heater.size();i++){
        pos first_room;
        first_room.x = heater[i].x + x_dir[heater[i].dir];
        first_room.y = heater[i].y + y_dir[heater[i].dir];
        first_room.dir = 0;

        heating_room.push_back(first_room);

        while(!heating_room.empty()){
            pos sp = heating_room.front();
            heating_room.pop_front();

            for(j=0;j<3;j++){
                if(can_go(sp, j, heater[i].dir)){

                }
            }
        }

    }

}

void modi_temperature(){

}

void temp_down(){
    int i, j;

    for(i=1;i<=R;i++){
        if(i==1){
            for(j=0;j<C;j++){
                if(room[i][j] >= 1) room[i][j]--;
            }
        }
        else if(i==R){
            for(j=0;j<C;j++){
                if(room[i][j] >= 1) room[i][j]--;
            }
        }
        else if(j==1 || j== C){
            if(room[i][j] >= 1) room[i][j]--;
        }
    }
}

void chocolate(){
    choco++;
}

bool all_temp(){
    int i, j;

    for(i=0;i<temp_room.size();i++){
        if(room[temp_room[i].x][temp_room[i].y] >= K){
            continue;
        }
        else return false;
    }
    return true;
}

bool can_go(pos sp, int i, int dir){
    bool flag = false;

    for(int j=0;j<3;j++){
        
    }
}