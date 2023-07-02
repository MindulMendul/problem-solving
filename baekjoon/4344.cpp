#include <iostream>

using namespace std;

int main(){
    //freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N;
		for(int i=0; i<N; i++){
			cin >> M;
			int sum=0, cnt=0;
			
			int tmp[M];
			for(int j=0; j<M; j++){
				cin>>tmp[j];
				sum+=tmp[j];
			}

			float avg=(float)sum/(float)M;

			for(int j=0; j<M; j++){
				if(avg<(float)tmp[j]) cnt++;
			}
			printf("%0.3f%\n",((float)cnt*100/(float)M));
		}
    return 0;
}
