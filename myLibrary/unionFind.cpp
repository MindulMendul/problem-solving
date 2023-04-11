//시간 복잡도가 상수시간
int Find(int x){
    if(x==parent[x]) return x;
    else return parent[x]=Find(parent[x]);
}

int union(int a, int b){
    int pa=Find(a);
    int pb=Find(b);

    if(pa>=pb){parent[pa]=pb;}
    else {parent[pb]=pa;}
}