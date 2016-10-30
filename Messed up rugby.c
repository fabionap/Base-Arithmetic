#include <stdio.h>

void risultato(int a) {
    int i, j, k;
    for(i=0; i<a/7+1; i++) {
        for(j=0; j<a/3+1; j++) {
            for(k=0; k<a/2+1; k++) {
                if(a-((i*7)+(j*3)+(k*2))==0) {
                    printf("%d %d %d\n", i, j, k);
                }
            }
        }
    }
}

int main() {
    int a;
    scanf("%d", &a);
    risultato(a);
    return 0;
}
