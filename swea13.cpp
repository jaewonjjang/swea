#include <iostream>
#include <vector>

using namespace std;

#define MAX 51

typedef struct {
    int x, d, k;
}rotate_factor;

int N, M, T;
int circle[MAX][MAX];
int erase_check[MAX][MAX];

vector<rotate_factor> rf;

void input();
void rotate(rotate_factor);
void erase();

int main(){

}

void input(){
    cin >> N >> M >> T;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> circle[i][j];
        }
    }

}