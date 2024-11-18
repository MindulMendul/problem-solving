#include <iostream>
#include <queue>

using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int answer;
    cin >> answer;

    queue<int> q;
    q.push(answer);
    while(!q.empty()){
        //write my code
        q.pop();
    }
    
    cout << answer;
    return 0;
}
