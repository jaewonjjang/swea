#include <iostream>
#include <string>

#define MAX 10

using namespace std;

int N, M;
bool check[MAX];
int perm_array[MAX];


void input();
void perm(int, int);
int main(){
    input();

    perm(0, 0);

    return 0;
}

void input(){
    cin >> N >> M;

    memset(check, 0, sizeof(check));
}

void perm(int idx, int cnt){
    if(cnt==M){
        for(int i=0;i<N+1;i++){
            if(check[i] == true){
                cout << i;
            }
        }
        cout << endl;
    }
    else{
        for(int i=idx;i<N+1;i++){
            if(!check[i]){
                check[i] = true;
                perm_array[cnt] = i;
                perm(i, cnt+1);
                check[i] = false;
            }
        }
    }
}