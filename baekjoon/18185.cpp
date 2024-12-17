#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, cur, m;
    int answer=0;
    cin>>N;
    int ramen[N];
    for(int i=0; i<N; i++){
        cin>>ramen[i];
    }
    cur=0;

    while(cur<N){
        if(ramen[cur]==0){cur++;}
        else{
            if(cur<N-2 && ramen[cur+1]>0 && ramen[cur+2]>0){
                if(ramen[cur+1]<=ramen[cur+2]){
                    m=min({ramen[cur], ramen[cur+1], ramen[cur+2]});
                    ramen[cur]-=m;
                    ramen[cur+1]-=m;
                    ramen[cur+2]-=m;
                    answer+=7*m;
                } else {
                    m=min(ramen[cur], ramen[cur+1]-ramen[cur+2]);
                    ramen[cur]-=m;
                    ramen[cur+1]-=m;
                    answer+=5*m;
                }
            } else if(cur<N-1 && ramen[cur+1]>0){
                m=min(ramen[cur], ramen[cur+1]);
                ramen[cur]-=m;
                ramen[cur+1]-=m;
                answer+=5*m;
            } else {
                answer+=3*ramen[cur];
                ramen[cur]=0;
            }
        }
    }
    
    cout << answer;
    return 0;
}
