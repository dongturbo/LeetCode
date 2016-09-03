//判断两者只是是否有重叠比较麻烦
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int area1=abs(C-A)*abs(D-B);
    int area2=abs(G-E)*abs(H-F);
    int x1,x2,y1,y2;
    if(E>=C || F>=D ||A>=G ||B>=H){
        return area1+area2;
    }
    if(E>A){
        x1=E;
    }else{
        x1=A;
    }
    if(G>C)
        x2=C;
    else
        x2=G;
    if(F<B){
        y1=B;
    }else{
        y1=F;
    }
    if(H<D)
        y2=H;
    else
        y2=D;
    return area1+area2-abs(x1-x2)*abs(y1-y2);
}
