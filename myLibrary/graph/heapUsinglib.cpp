#include<iostream>
#include <queue>
#include <functional>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
    {
        printf("#%d ", test_case);
        int n, op; scanf("%d", &n);
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
        	scanf("%d", &op);
            if(op-1) {
                if(pq.empty()) {
                    printf("-1 ");
                } else {
                    printf("%d ", pq.top());
                	pq.pop();
                }
            } else {
                scanf("%d", &op);
                pq.push(op);
            }
        }
        printf("\n");
	}
	return 0;
}