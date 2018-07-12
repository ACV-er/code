#include<stdio.h>
#include<string.h>

int main(void) {
    int N, i, len, flag;
    char s[33];
    char gjz[32][10] = {
     "auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof", "static", "struct", "switch", "typedef", "union", "unsigned","void", "volatile", "while"
    };
    scanf("%d", &N);
    while(N--) {
        flag = 1;
        scanf("%s", s);
        if(s[0]>='0' && s[0]<='9') {
            printf("No\n");
            continue;
        }
        for(i=0; i<32; i++) {
            if( strcmp(s, gjz[i]) == 0 ) {
                printf("No\n");
                flag = 0;
            }
        }
        if(flag == 0) continue;
        len = strlen(s);
        for(i=0; i<len; i++) {
            if( !(s[i]=='_'||(s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')) ) {
                printf("No\n");
                flag = 0;
                break;
            }
        }
        if(flag == 0) continue;
        printf ("Yes\n");
    }

    return 0;
}
