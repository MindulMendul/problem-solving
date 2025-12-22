#include <iostream>

using namespace std;

typedef long long int lli;

int T, N, M;
int pos[100'001];
int fenwick[200'001];
int pivot;

void update(int ind, int diff){
    while(ind<=N+M){
        fenwick[ind]+=diff;
        ind+=(ind&-ind);
    }
}

long long int sum(int ind){
    long long int res=0;
    while(ind>0){
        res+=fenwick[ind];
        ind-=(ind&-ind);
    }

    return res;
}

void print(){
    cout<<"\npos: ";
    for(int i=1; i<=N; i++){
        cout<<pos[i]<<" ";
    }cout<<endl;
    cout<<"fenwick: ";
    for(int i=1; i<=N+M; i++){
        cout<<fenwick[i]<<" ";
    }cout<<endl;
}

int main() {
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cin>>T;
    for(int tc=1; tc<=T; tc++){
        cin>>N>>M; pivot=M;

        // init
        for(int i=1; i<=N; i++) pos[i]=M+i;
        for(int i=1; i<=M+N; i++) fenwick[i]=0;
        for(int i=M+1; i<=M+N; i++) update(i, 1);
        
        //cout<<"query"<<tc<<" start\n";
        //print(); 
        // query
        int q;
        for(int i=0; i<M; i++){
            cin>>q;
            cout<<sum(pos[q]-1)<<" ";
            update(pos[q],-1);
            update(pivot,1);
            pos[q]=pivot--;
            //print();
        }

        cout<<"\n";
    }

    return 0;
}