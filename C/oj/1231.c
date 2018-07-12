#include"stdio.h"

int main(void) {
    int N, coun, sala;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &coun);
        if(coun<100) {
            sala = 200-(100-coun)*3;
        } else {
            sala = 200+(coun-100)*2;
        }
        printf("%d\n", sala);
    }

    return 0;
}
