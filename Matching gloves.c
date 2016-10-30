#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//non passa i judge test per segmentation fault

int pali(char* a){
    int i, la=strlen(a);
    for(i=0; i<(la/2); i++) {
        if(a[i]!=a[la-i-1])
            return 0;
    }
    if(la==1)
        return 0;
    return 1;
}

char* dividi(char* a, int c) {
    int i, j, k=0;
    char* b=(char*)malloc(sizeof(500000));
    for(i=0; k<c; i++) {
        if(a[i]==' ')
            k++;
    }
    for(j=0; a[i+j]!='\0' && a[i+j]!=' '; j++)
        b[j]=a[i+j];
    b[j]='\0';
    return b;
}

int uguali(char* a, char* b) {
    int la=strlen(a);
    int lb=strlen(b);
    if(la!=lb)
        return 0;
    int i, k=0;
    for(i=0; i<la; i++) {
        if(a[i]==b[i])
            k++;
    }
    if(k==i)
        return 1;
    return 0;
}

int contrari(char* a, char* b) {
    int la=strlen(a);
    int lb=strlen(b);
    if(la!=lb)
        return 0;
    int i, k=0;
    for(i=0; i<la; i++) {
        if(a[i]==b[la-i-1])
            k++;
    }
    if(k==i)
        return 1;
    return 0;
}

int doppio(char* a, char* b) {
    int i, c=0;
    for(i=0; a[i]!='\0'; i++) {
        if(a[i]==' ')
            c++;
    }
    if(c==0)
        return 0;
    for(i=0; i<c; i++) {
        if(uguali(dividi(a, i), b))
            return 1;
        if(contrari(dividi(a, i), b))
            return 1;
    }
    return 0;
}

int conta(char* a, char* b) {
    int i, j, ugua, cont, tot=0, pb=1, pa=1;
    for(i=0; b[i]!='\0'; i++) {
        if(b[i]==' ')
            pb++;
    }
    for(i=0; a[i]!='\0'; i++) {
        if(a[i]==' ')
            pa++;
    }
    for(i=0; i<pb; i++) {
        ugua=0;
        cont=0;
        if(strlen(dividi(b, i))>1) {
            for(j=0; j<pa; j++) {
                if(uguali(dividi(a, j), dividi(b, i)))
                    ugua++;
                if(contrari(dividi(a, j), dividi(b, i)))
                    cont++;
            }
            if(ugua!=cont)
                return -1;
            tot+=ugua;
        } else {
            for(j=0; j<pa; j++) {
                if(uguali(dividi(a, j), dividi(b, i)))
                    ugua++;
            }
            if(ugua%2==1)
                return -1;
            tot+=ugua/2;
        }
    }
    return tot;
}

int main() {
    int a, i, j, k, space=0;
    int sp=0;
    char b[50000];
    char* c=(char*)malloc(sizeof(50000000));
    char* d=(char*)malloc(sizeof(50000000));
    c[0]='\0';
    d[0]='\0';
    scanf("%d", &a);
    for(i=0; i<a; i++) {
        scanf("%s", b);
        k=strlen(b);
        b[k]='\0';
        if(!(pali(b))) {
            for(j=0; j<k; j++) {
                c[j+space]=b[j];
            }
            space+=k+1;
            c[space-1]=' ';
            c[space]='\0';
            if(!(doppio(d, b))) {
                for(j=0; j<k; j++) {
                    d[j+sp]=b[j];
                }
                sp+=k+1;
                d[sp-1]=' ';
            }
        }
    }
    if(c[0]=='\0') {
        printf("%d", 0);
        return 0;
    }
    c[space-1]='\0';
    d[sp-1]='\0';
    printf("%d", conta(c, d));
    return 0;
}
