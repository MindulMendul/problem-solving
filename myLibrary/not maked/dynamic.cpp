#include <iostream>

using namespace std;

#define MAX 1000

static dp[MAX];

void init(){
    for(int i=0; i<MAX; i++){
        dp[i]=0;
    }
}

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    int answer;
    cin >> answer;
    cout << answer;
    return 0;
}
