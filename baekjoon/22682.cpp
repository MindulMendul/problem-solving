#include <iostream>

using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
  	ios::sync_with_stdio(false);
  	cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    cin>>N>>K;
    int arr[N];
    for(int i=0; i<N; i++){cin>>arr[i];}

    int s=0, e=0, cnt=0;
    long long int ans=0, tmp_ans=0;
    while(e<=N){
        if(s==e){e++;}
        else {
            // 추가할 게 홀수면
            if(arr[e-1]%2==1){
                if(cnt<K) {cnt++; e++;} // 만약 넉넉하면 과감하게 더해주자.
                else { // 한계점 도달했으면 뒤에서 잘라보자.
                    if(arr[s]%2==1) {cnt--; s++;}
                    else {tmp_ans--; s++;}
                }
            } else { // 추가할 게 짝수면
                tmp_ans++; e++; // 그냥 더해주면 됨.
            }
            if(tmp_ans>ans) ans=tmp_ans;
        }
    }

    cout<<ans;

    return 0;
}