#include <iostream>

using namespace std;

static int queenLoc[15];
static int N, answer;

bool track(int x){
    for(int i=0; i<x; i++){
        if(queenLoc[i]==queenLoc[x]) return false;
        else if(queenLoc[i]-queenLoc[x]==i-x) return false;
        else if(queenLoc[i]-queenLoc[x]==x-i) return false;
    }
    return true;
}

void NQueen(int x){
    if(x==N) {
        answer++;
    } else {
        for(int i=0; i<N; i++){
            queenLoc[x]=i;
            if(track(x)) NQueen(x+1);
        }
    }
}

int main(){
    freopen("input.txt", "rt", stdin);
    cin >> N;
    answer=0;

    NQueen(0);

    cout << answer;
    return 0;
}
