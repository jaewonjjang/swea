// 나선형으로 배열 탐색하는 문제 //

#include <iostream>
#include <stdlib.h>


using namespace std;


#define a_percent(a) (a-0.1*a-0.1*a-0.07*a-0.07*a - 0.05*a - 0.02*a - 0.02*a - 0.01*a - 0.01*a)
int N;
int **square;
int sand_out;
int x_move[4][10] = {{-1, -1, -1, 0, 0, -2, 0, 0, 1, 1}, 
                    {0, -1, 1, -1, 1, 0, -2, 2, -1, 1}, 
                    {1, 1, 1, 0, 0, 2, 0, 0, -1, -1}, 
                    {0, 1, -1, 1, -1, 0, 2, -2, 1, -1}} ;
int y_move[4][10] = {{0, -1, 1, -1, 1, 0, -2, 2, -1, 1}, 
                    {1, 1, 1, 0, 0, 2, 0, 0, -1, -1},
                    {0, 1, -1, -1, 1, 0, 2, -2, 1, -1},
                    {-1, -1, -1, 0, 0, -2, 0, 0, 1, 1}};

float percent[10] = {0, 0.1, 0.1, 0.07, 0.07, 0.05, 0.02, 0.02, 0.01, 0.01};
void eval_sand(int , int, int);
int main(){
    int i, j, k;
    int dir;
    sand_out=0;
    cin >> N;
    cin.ignore();

    //cout << N;
    square = (int**)malloc(sizeof(int*)*N);
    for(i=0;i<N;i++){
        square[i] = (int*)malloc(sizeof(int)*N);
    }


    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            cin >> square[i][j];
        }
    }

    int start_x = N /2;
    int start_y = N /2;

    int dx = -1;
    int dy = 1;
    dir = 0;


    //printf("%d", square[start_y][start_x]);

    for(i=1;i<N;i++){
        for(j=0;j<i;j++){
            start_x += dx;
            eval_sand(start_y, start_x, dir%4);
        }
        dx *= -1;
        dir++;
        for(j=0;j<i;j++){
            start_y += dy;
            eval_sand(start_y, start_x, dir%4);
        }
        dy *= -1;
        dir++;
    }

    cout << sand_out << endl;
    return 0;
}

// 토네이도가 도착한 지점을 인자로 받는다 !!!
void eval_sand(int y, int x, int dir) {
    int y_pos, x_pos;
    for(int i=0;i<10;i++){
        y_pos = y+ y_move[dir][i];
        x_pos = x+ x_move[dir][i];
        if(y_pos >= 0 && y_pos <= N-1 && x_pos >=0 && x_pos <= N-1){
            if(i==0){
                square[y_pos][x_pos] += a_percent(square[y][x]);
            }
            else
            square[y_pos][x_pos] += percent[i]*square[y][x];
        }
        else {
            if(i==0){
                sand_out += a_percent(square[y][x]);
            }
            else 
            sand_out += percent[i]*square[y][x];
        }
    }
}