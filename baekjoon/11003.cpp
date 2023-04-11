#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int temp, answer, N, L;
	deque <pair<int, int>> num;

	cin>>N>>L;
	for (int i=0; i<N; i++)
	{
		cin>>temp;
		while (num.size() && num.back().first > temp) num.pop_back();
		num.push_back(make_pair(temp, i));
		if (num.front().second<=i-L) num.pop_front();
		cout<<num[0].first<<' ';
	}

	return 0;
}