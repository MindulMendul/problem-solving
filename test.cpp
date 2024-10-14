#include <iostream>
#include <string>

using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	bool Set[20]={false, false, false, false, false,  false, false, false, false, false,  false, false, false, false, false,  false, false, false, false, false};
	for(i=0; i<N; i++){
		cin>>arr[i];
	}

	cin>>M;

	for(i=0; i<M; i++){
		string cmd; int j;
		cin >> cmd;
		switch(cmd){
			case "add":
				cin>>j;
				Set[j-1]=true;
				break;

			case "remove":
				cin>>j;
				Set[j-1]=false;
				break;

			case "check":
				cin>>j;
				j=(Set[j-1])?1:0;
				cout<<j<<endl;
				break;

			case "toggle":
				cin>>j;
				Set[j-1]=!Set[j-1];
				break;

			case "all": 
				for(j=0 j<20; j++){
					Set[j]=true;
				}
				break;
			case "empty": 
				for(j=0 j<20; j++){
					Set[j]=true;
				}
				break;
		}
	}
		
    return 0;
}
