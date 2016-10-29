#include <stdio.h>

int contiene(char* a, int b) {
    int i;
    for(i=0; a[i]!='\0'; i++) {
        if((int)a[i]==b)
            return 1;
    }
    return 0;
}

int doppio(char* a, char* b) {
    int i;
    for(i=0; a[i]!='\0'; i++) {
        if(a[i]==b[2])
            return 1;
    }
    return 0;
}

char* color(char* a) {
    int i;
    for(i=0; i<5; i++) {
        if(i==0) {
            if(!(contiene(a, 105)))
                return "White";
        }
        if(i==1) {
            if(!(contiene(a, 97)))
                return "Black";
        }
        if(i==2) {
            if(!(contiene(a, 117)))
                return "Blue";
        }
        if(i==3) {
            if(!(contiene(a, 100)))
                return "Red";
        }
        if(i==4) {
            if(!(contiene(a, 108)))
                return "Yellow";
        }
    }
    return 0;
}

int main() {
    int a, i, j=0;
    char b[100];
    char c[100];
    c[0]='\0';
    scanf("%d", &a);
    for(i=0; i<a; i++) {
        scanf("%s", b);
        if(!(doppio(c, b))) {
            c[j]=b[2];
            j++;
        }
    }
    c[j]='\0';
    printf("%s\n", c);
    printf("%s", color(c));
    return 0;
}
