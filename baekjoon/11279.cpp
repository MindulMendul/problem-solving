#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

typedef long long int lli;

using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<lli, vector<lli>, less<lli>> pq;
	int N; cin>>N;
	for(int i=0; i<N; i++){
		lli num; cin>>num;
		if(num==0){
			if(pq.empty()){
				cout<<0<<"\n";
			} else {
				cout<<pq.top()<<"\n";
				pq.pop();
			}
		} else {
			pq.push(num);
		}
	}
		
    return 0;
}
