#include <iostream>
#define N 10000

using namespace std;

int main(){
    bool num[N];
    for(int i=0; i<N; i++){
        num[i]=true;
    }

    for(int i=0; i<N; i++){
        if(!num[i]) continue;
        int j=i+1, ans=i+1;
        while(ans<=N){
            num[ans-1]=false;
            j=ans;
            while(j>0){
                ans+=j%10;
                j/=10;
            }
        }
        cout<<i+1<<endl;
    }
    return 0;
}
