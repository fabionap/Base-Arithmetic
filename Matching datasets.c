#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int simili(char* a, char* b) {
    int i, k=0;
    for(i=0; a[i]!='\0'; i++) {
        if(a[i]==b[i])
            k++;
    }
    if(k>=strlen(a)-1 && k<=strlen(a)+1 && strlen(a)>1)
        return 1;
    if(k==strlen(a))
        return 1;
    return 0;
}

char* dividi(char* a, int c, char d) {
    int i, j, k=0;
    char* b=(char*)malloc(sizeof(1000));
    for(i=0; k<c; i++) {
        if(a[i]==d)
            k++;
    }
    for(j=0; a[i+j]!='\0' && a[i+j]!=d; j++)
        b[j]=a[i+j];
    b[j]='\0';
    return b;
}

int uguali(char* a, char* b) {
    int i, c=1;
    int k=0;
    for(i=0; a[i]!='\0'; i++) {
        if(a[i]==',')
            c++;
    }
    for(i=0; i<c; i++) {
        if(simili(dividi(a,i,','), dividi(b,i,',')))
            k++;
    }
    if(k==c)
        return 1;
    return 0;
}

int abbina(char* a, char* b, int c, int d) {
    int i;
    for(i=0; i<d; i++) {
        if(uguali(dividi(a, c, ' '), dividi(b, i, ' ')))
            return i;
    }
    return i;
}

int main() {
    int a, i, k=0;
    char b[10000];
    char c[10000];
    scanf("%d", &a);
    for(i=0; i<a; i++) {
        scanf("%s", b+k);
        k=strlen(b)+1;
        b[k-1]=' ';
    }
    b[k-1]='\0';
    k=0;
    for(i=0; i<a; i++) {
        scanf("%s", c+k);
        k=strlen(c)+1;
        c[k-1]=' ';
    }
    c[k-1]='\0';
    for(i=0; i<a; i++) {
        printf("%d,%d\n", i, abbina(b,c,i,a));
    }
    return 0;
}
