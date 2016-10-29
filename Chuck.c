#include <stdio.h>
#include <stdlib.h>

int cifre(int a) {
    int i, k=0;
    for(i=1; a/i!=0; i*=10) {
        k++;
    }
    return k;
}

int el(int a, int b) {
    if(b==0)
        return 1;
    int c;
    int k=a;
    for(c=1; c<b; c++)
        k*=a;
    return k;
}

char i_toa(int a) {
    char b= (char)a+48;
    return b;
}

int mul4(int a) {
    int i;
    if(a%4==0)
        return a;
    for(i=0; 1; i++) {
        if((10*a+i)%4==0)
            return (10*a+i);
    }
}

char* stringa(int a) {
    char* b=(char*)malloc(sizeof(1000000));
    int i, j, c, m, space=0;
    for(i=0; i<a; i++) {
        m=mul4(i+1);
        for(j=cifre(m)-1; j>=0; j--) {
            c=(m/el(10, j))%10;
            b[space]=i_toa(c);
            space++;
        }
    }
    b[space]='\0';
    return b;
}

int main() {
    int a;
    scanf("%d", &a);
    printf("%c", stringa(a)[a-1]);
    return 0;
}
