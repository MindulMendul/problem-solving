// https://yabmoons.tistory.com/438

#include <iostream>
#include <vector>

using namespace std;

#define MAX 100005 

long long fenwick[MAX]; // 누적 합 저장 (long long 추천)
int arr[MAX];           // 입력 값 저장 (필요 없으면 생략 가능)
int N, M;               // N: 데이터 개수, M: 쿼리 개수 등

// 갱신
void update(int i, int diff) {
    while (i <= MAX) {
        fenwick[i] += diff;
        i += (i & -i);
    }
}

// 조회
long long get(int i) {
    long long sum = 0;
    while (i > 0) {
        sum += fenwick[i];
        i -= (i & -i);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    N = 5; 
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        arr[i] = num;       
        update(i, num);
    }

    // 사용 예시
    // 1. 구간 합 (1~3)
    cout << get(3) << "\n";

    // 2. 값 변경 (3번째 값을 5에서 2로 변경)
    // 중요: update에는 '변경된 값'이 아니라 '차이(diff)'를 넣어야 함!
    int newVal = 2;
    int diff = newVal - arr[3];
    arr[3] = newVal;    // 원본 갱신
    update(3, diff);    // 트리 갱신

    cout << get(3) << "\n";

    return 0;
}