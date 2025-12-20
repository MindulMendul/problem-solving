for(int i=0; i<M; i++){
    int cmd; cin>>cmd;
    if(cmd==1){
      int i, v; cin>>i>>v; a[i-1]=v;
      setMin(0, N-1, 1, i-1, v);
    } else {
      int i, j; cin>>i>>j;
      cout<<getMin(0, N-1, 1, i-1, j-1)+1<<"\n";
    }
  }