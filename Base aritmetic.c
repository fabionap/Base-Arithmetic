#include <stdio.h>
#include <string.h>

//ritorna la minima base
int base(char* a) {
    int i;
    int k=0;
    int j= strlen(a);
    for(i=0; i<j; i++) {
        if((int)a[i]>64 && (int)a[i]<71 && (int)a[i]-55>k)
            k=(int)a[i]-55;
        if((int)a[i]>47 && (int)a[i]<58 && (int)a[i]-48>k)
            k=(int)a[i]-48;
    }
    return k+1;
}

/*int last(int a, int b) {
    int c=a;
    printf("%i\n", c);
    if(b>1)
        c = a/el(10, b-1);
    int d = c%10;
    return d;
}*/

//eleva a potenza
int el(int a, int b) {
    if(b==0)
        return 1;
    int c;
    int k=a;
    for(c=1; c<b; c++)
        k*=a;
    return k;
}

/*int cifre(int a) {
    int b;
    for(b=1; a/el(10, b)>0; b++);
    return b;
}*/

/*int mAx(int a) {
    int b=cifre(a);
    int k=last(a, 1);
    int c;
    for(c=2; c<=b; c++) {
        if(last(a, c)>k)
            k=last(a, c);
        printf("%i\n", k);
    }
    return k+1;
}*/

//ritorna la b-esima cifra
int coef(char* a, int b) {
    int k;
    if((int)a[b]>64 && (int)a[b]<71)
        k=(int)a[b]-55;
    if((int)a[b]>47 && (int)a[b]<58)
        k=(int)a[b]-48;
    return k;
}

//converte il numero in base 10
int conv(char* a) {
    int b=base(a);
    int c=strlen(a);
    int k=0;
    int i;
    for(i=c-1; i>=0; i--) {
        k+=coef(a, i)*el(b, c-i-1);
    }
    return k;
}

int sum(int a, int b){
    return a+b;
}


int main() {
    printf("%i", sum(conv("B95"), conv("101101")));
    return 0;
}
