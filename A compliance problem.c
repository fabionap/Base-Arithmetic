#include <stdio.h>
#include <string.h>

int pari(char* a) {
    if(strlen(a)%2==0)
        return 1;
    return 0;
}

int conta(char* a, int b) {
    int i, k=0;
    for(i=0; a[i]!='\0'; i++) {
        if(a[b]==a[i])
            k++;
    }
    return k;
}

char dispari(char* a) {
    int i;
    for(i=0; a[i]!='\0'; i++) {
        if(conta(a, i)%2==1)
            return a[i];
    }
}

int pali(char *a){
    if(pari(a)) {
        int i;
        for(i=0; a[i]!='\0'; i++) {
            if(conta(a, i)%2==1)
                return 0;
        }
        return 1;
    }
    int i;
    for(i=0; a[i]!='\0'; i++) {
        if(conta(a, i)%2==1 && a[i]!=dispari(a))
            return 0;
    }
    return 1;
}

char* risp(char* a) {
    if(pali(a))
        return "yes";
    return "no";
}

int main() {
    char a[502];
    scanf("%s", a);
    printf("%s", risp(a));
    return 0;
}
