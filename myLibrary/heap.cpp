//https://twpower.github.io/137-heap-implementation-in-cpp => 최대 힙
// 아래 코드는 최소힙을 기준으로 만듦

struct Node {
    int id;
    int income;
};

int size;
Node heap[11];

void swap(Node* a, Node* b) { Node tmp=*a; *a=*b; *b=tmp; }

bool compare(Node A, Node B) {
	if(A.income<B.income) return true;
    else if(A.income>B.income) return false;
    else return (A.id>B.id);
}

void pop(){
    if(size==0) return;
    swap(&heap[1], &heap[size--]);
    int parent=1, child=parent*2;
    if (child+1<=size)
        child=(compare(heap[child], heap[child+1]))?child:child+1;
    while (child<=size && compare(heap[child], heap[parent])) {
        swap(&heap[parent], &heap[child]);
        parent=child; child=child*2;
        if (child+1<=size)
            child=(compare(heap[child], heap[child+1]))?child:child+1;
    }
}

void push(Node newNode){
    if(size>9) {
        if(compare(heap[1], newNode)) { pop(); }
        else return;
    }
    
    heap[++size]=newNode;
    int child=size, parent=child/2;
    
    while (child>1 && compare(heap[child], heap[parent])) {
		swap(&heap[parent], &heap[child]);
		child=parent; parent=child/2;
	}
}
