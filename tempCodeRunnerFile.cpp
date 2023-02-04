#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_INPUT 10000
#define MAX_NUM 30000

void init();
void addUser(int uID, int income);
int getTop10(int result[10]);

static int input[MAX_INPUT];

static unsigned int seed = 13410;

static unsigned int pseudoRand() {
	seed = seed * 214013 + 2531011;
	return (unsigned int)(seed >> 11) % MAX_NUM;
}

static void makeInput(int inputLen) {
	for (int i = 0; i < inputLen; i++) {
		input[i] = pseudoRand();
	}
}

static int run() {
	int N, userNum, uID = 0;
	int score = 100, result[10], cnt;
	int sum, check;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &userNum);
		makeInput(userNum);
		for (int j = 0; j < userNum; j++) {
			addUser(uID++, input[j]);
		}
		cnt = getTop10(result);

		sum = 0;
		for (int j = 0; j < cnt; j++)
			sum += result[j];
		scanf("%d", &check);
		if (check != sum)
			score = 0;
	}
	return score;
}

int main(void) {
    
	setbuf(stdout, NULL);
	freopen("partial_sort_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		init();
		printf("#%d %d\n", tc, run());
	}
	return 0;
}



/////////

struct Node {
    int id;
    int income;
};

size_t size;
Node heap[11];

void swap(Node* a, Node* b) { Node tmp=*a; *a=*b; *b=tmp; }

bool compare(Node A, Node B) {
	if(A.income>B.income) return true;
    else if(A.income<B.income) return false;
    else return (A.id<B.id);
}

void init(){
    for(int i=0; i<11; i++){ heap[i]={-1,-1}; }
    size=0;
}

void pop(){
    if(size==0) return;
    swap(&heap[1], &heap[size--]);
    int parent=1, child=parent*2;
    if (child+1<=size) child=(compare(heap[child+1],heap[child]))?child:child+1;
    while (child<=size && compare(heap[parent],heap[child])) {
        swap(&heap[parent], &heap[child]);
        parent=child; child=child*2;
        if (child+1<=size) child=(compare(heap[child+1],heap[child]))?child:child+1;
    }
}

void push(Node newNode){
    if(size>9){
        if(compare(newNode, heap[1]) ) { pop(); }
        else return;
    }
    
    heap[++size]=newNode;
    int child=size, parent=child/2;
    
    while (child>1 && compare(heap[parent], heap[child])) {
		swap(&heap[parent], &heap[child]);
		child=parent; parent=child/2;
	}
}

void addUser(int uID, int income) 
{
    Node newNode={uID, income};
    push(newNode);
}

int getTop10(int result[10])
{
    int cnt=0;
    while(size>0) {
        result[size-1]=heap[1].id;
        pop(); cnt++;
    }
    return cnt;
}