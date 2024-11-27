#include <iostream>
#include <vector>

using namespace std;

int v[1500][1500];
int top[1500];

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int a; cin>>a;
            v[j][i]=a;
        }
        top[i]=N-1;
    }

    for(int i=0; i<N-1; i++){
        int max_i=0;
        for(int j=0; j<N; j++){
            if(v[j][top[j]]>v[max_i][top[max_i]]) {
                max_i=j;
            }
        }
        top[max_i]--;
    }

    int ans=0;
    for(int i=0; i<N; i++){
        if(v[i][top[i]]>v[ans][top[ans]]) ans=i;
    }

    cout<<v[ans][top[ans]];
    return 0;
}
