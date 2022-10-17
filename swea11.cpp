#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define MAX 11

vector<int> town[MAX];
int town_people[MAX];

int N;
int connect_num;
bool checkforcomb[MAX];
bool visited[MAX];
int result;
bool no_connection_flag;
void input();
void seperate_town(int, int, int);
bool check_town_connected(vector<int>);
void cal_people_diff();

int main(){
    input();

    for(int i=1;i<N;i++){
        seperate_town(0, 0, i);
    }

    if(no_connection_flag) cout << result;
    else cout << "-1";
}

void input(){
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> town_people[i];
    }

    for(int i=0;i<N;i++){
        cin >> connect_num;
        for(int j=0;j<connect_num;j++){
            int temp;
            cin >> temp;
            town[i].push_back(temp-1);
        }
    }

    memset(checkforcomb, false, sizeof(checkforcomb));
    result = 987654321;
}

void seperate_town(int idx, int cnt, int n){
    if(cnt==n){
        vector<int> A;
        vector<int> B;

        for(int i=0;i<N;i++){
            if(checkforcomb[i]==true){
                A.push_back(i);
            }
            else B.push_back(i);
        }

        /*for(int i=0;i<A.size();i++){
            cout << A[i] << " ";
        }
        cout << endl;
        for(int i=0;i<B.size();i++){
            cout << B[i] << " ";
        }
        cout <<endl;
        */

        if(check_town_connected(A) && check_town_connected(B)){
            cal_people_diff();
            no_connection_flag = no_connection_flag || true;
        }
        else no_connection_flag = false;
        A.clear();
        B.clear();
    }

    else {
        for(int i=idx;i<N;i++){
            if(!checkforcomb[i]){
                checkforcomb[i] = true;
                seperate_town(i, cnt+1, n);
                checkforcomb[i] = false;
            }
        }
    }
}

bool check_town_connected(vector<int> A){
    queue<int> q;
    bool flag = true;
    for(int i=0;i<N;i++){
        visited[i] = true;
    }
    for(int i=0;i<A.size();i++){
        visited[A[i]] = false;
        q.push(A[i]);
    }

    while(!q.empty()){
        int temp = q.front();
        q.pop();

        for(int i=0;i<town[temp].size();i++){
            if(visited[town[temp][i]]==false){
                visited[town[temp][i]] = true;
                q.push(town[temp][i]);
            }
        }
    }

    for(int i=0;i<N;i++){
        flag = flag && visited[i];
    }

    memset(visited, false, sizeof(visited));

    if(flag){
        return true;
    }
    else return false;
}

void cal_people_diff(){
    int true_people=0;
    int false_people=0;

    for(int i=0;i<N;i++){
        if(checkforcomb[i] == true){
            true_people += town_people[i];
        }
        else false_people += town_people[i];
    }
    //cout << true_people << false_people << endl;
    result = min(result, abs(true_people - false_people));
}