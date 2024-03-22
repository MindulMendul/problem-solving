#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long int lli;

static lli arr[100000];

int solve(int res) {
	
}

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli N, M;
		int i, j=0;
    
		cin>>N;
		for(i=0; i<N; i++){
			cin>>arr[i];
		}

		sort(arr, arr + N);

		cin>>M;

		for(i=0; i<M; i++){
			cin >> j;
			cout << solve(j) << "\n";
		}
		
    return 0;
}
