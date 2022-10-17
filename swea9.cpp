#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define MAX 20

int N, B;
int people_height[MAX];
bool check[MAX];
int res;

void input();
void select_people(int, int);
int add_height();

int main(){
    input();
    
    select_people(0, 0);

    cout << res << endl;

    return 0;
}

void input(){
    cin >> N >> B;

    for(int i=0;i<N;i++){
        cin >> people_height[i];
    }

    memset(check, false, sizeof(check));
    res = 100;
}

void select_people(int idx, int cnt){

    if(add_height() >= B){
        res = min(res, add_height()-B);
    }

    else {
        for(int i=idx;i<N;i++){
            if(check[i] ==false){
                check[i] = true;
                select_people(i, cnt+1);
                check[i] = false;
            }
        }
    }
}

int add_height(){

    int result=0;

    for(int i=0;i<N;i++){
        if(check[i] == true){
            result += people_height[i];
        }
    }

    return result;
}