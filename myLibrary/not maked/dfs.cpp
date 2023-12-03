#include <iostream>

using namespace std;

int dfs(int input){
    if(input==10) return 10;
    
    int result=1;
    result+=dfs(input+1);
    return result;
}

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int answer;
    cin >> answer;
    answer=dfs(1);
    cout << answer;
    return 0;
}
