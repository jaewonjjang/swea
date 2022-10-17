#include <iostream>
#include <deque>

using namespace std;

#define MAX 21

int R, C, K;
int map[MAX][MAX];

void input();
void dice_roll();
void cal_score();
void modi_dir();

int main(){
    int i,j;
    input();

    for(i=0;i<K;i++){
        dice_roll();

        cal_score();

        modi_dir();
    }
}

void input(){
    cin >> R >> C >> K;

    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin >> map[i][j];
        }
    }
}

void dice_roll(){
    
}