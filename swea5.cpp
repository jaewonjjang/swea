#include <iostream>


#define MAX 10000000

using namespace std;
int chief, semi;
int room_no;
int room_student[MAX];
int result;
void input(){
    cin >> room_no;

    cin.ignore();
    for(int i=0;i<room_no;i++){
        cin >> room_student[i];
    }

    cin.ignore();

    cin >> chief >> semi;

    result = 0;
}

void solve(){
    int temp;
    for(int i=0;i<room_no;i++){
        if(room_student[i] <= chief){
            result++;
            continue;
        }
        else {
            if(!((room_student[i]-chief)%semi)){
                temp = (room_student[i]-chief) / semi;
            }
            else {
                temp = (room_student[i]-chief) / semi + 1;
            }
            result += temp +1;
        }
    }

    cout << result;
}
int main(){
    input();

    solve();

    return 0;
}
