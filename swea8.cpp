#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int small[9];
bool check[9];
vector<int> selec_small;

void input();
bool sum_input();
void select_small(int, int);
void print_height();

int main(){
    input();

    select_small(0, 0);

    return 0;
}

void input(){
    for(int i=0;i<9;i++){
        cin >> small[i];
    }
}

void select_small(int idx, int cnt){
    if(cnt==7){
        if(sum_input()){
            print_height();
            return;
        }
    }

    else{
        for(int i=idx;i<9;i++){
            if(check[i]==false){
                check[i] = true;
                select_small(i, cnt+1);
                check[i] = false;
            }
        }
    }
}

bool sum_input(){
    int res=0;
    for(int i=0;i<9;i++){
        if(check[i]==true){
            res += small[i];
        }
    }

    if(res == 100){
        return true;
    }
    else return false;
}

void print_height(){
    for(int i=0;i<9;i++){
        if(check[i]==true){
            selec_small.push_back(small[i]);
        }
    }

    sort(selec_small.begin(), selec_small.end());

    for(int i=0;i<selec_small.size();i++){
        cout << selec_small[i] << endl;
    }
}