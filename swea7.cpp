#include <iostream>
#include <vector>
#include <cmath>
#include <string>


using namespace std;

#define MAX 15
#define MAX_HOUSE 50

typedef struct {
    int r, c, distance;
}house;
 
int N, M, result;
bool check[MAX];

house h[MAX_HOUSE*2];
pair<int, int> c[MAX];

vector<pair<int, int> > selected_chick_house;
int town[MAX_HOUSE][MAX_HOUSE];
int house_idx;
int chick_idx;


void input();
void select_chicken(int, int);
int cal_chicken_distance();
int distance(house, pair<int, int>);

int main(){

    input();

    select_chicken(0, 0);

    cout << result;

    return 0;
}

void input(){

    house_idx = 0;
    chick_idx = 0;
    result = MAX_HOUSE * MAX;

    cin >> N >> M;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> town[i][j];
            // house
            if(town[i][j] == 1){
                h[house_idx].r = i;
                h[house_idx].c = j;
                h[house_idx++].distance = 100;
            }
            else if(town[i][j] ==2 ){
                c[chick_idx].first = i;
                c[chick_idx++].second = j;
            }
        }
    }
    //cout << house_idx << chick_idx << endl;
    memset(check, false, sizeof(check));
}

void select_chicken(int idx, int cnt){

    if(cnt == M){
        int res = cal_chicken_distance();
        result = min(res, result);
        //return;
    }

    else {
        for(int i=idx;i<chick_idx;i++){
            if(!check[i]){
                check[i] = true;
                select_chicken(i, cnt+1);
                check[i] = false;
            }
        }
    }
}

int cal_chicken_distance(){

    int res=0;
    int dis = 100;
    for(int i=0;i<chick_idx;i++){
        if(check[i] == true){
            selected_chick_house.push_back(c[i]);
        }
    }
    //cout << selected_chick_house.size() << endl;
    for(int i=0;i<house_idx;i++){
        for(int j=0;j<selected_chick_house.size();j++){
            dis = min(dis, distance(h[i], selected_chick_house[j]));
        }
        res += dis;
        dis = 100;
    }
    //cout << res << endl;
    selected_chick_house.clear();
    return res;
}

int distance(house h, pair<int, int> c){

    return abs(h.r-c.first) + abs(h.c - c.second);
}

