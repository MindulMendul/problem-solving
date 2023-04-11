#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, i, m;
    int answer=0;
    cin>>N;
    int A[N];
    for(i=0; i<N; i++){
        cin>>A[i];
    }
    i=0;

    while(i<N){
        if(A[i]==0){i++;}
        else{
            if(i<N-2 && A[i+1]>0 && A[i+2]>0){
                if(A[i+1]<=A[i+2]){
                    m=min({A[i], A[i+1], A[i+2]});
                    A[i]-=m;
                    A[i+1]-=m;
                    A[i+2]-=m;
                    answer+=7*m;
                } else {
                    m=min(A[i], A[i+1]-A[i+2]);
                    A[i]-=m;
                    A[i+1]-=m;
                    answer+=5*m;
                }
            } else if(i<N-1 && A[i+1]>0){
                m=min(A[i], A[i+1]);
                A[i]-=m;
                A[i+1]-=m;
                answer+=5*m;
            } else {
                answer+=3*A[i];
                A[i]=0;
            }
        }
    }
    
    cout << answer;
    return 0;
}
