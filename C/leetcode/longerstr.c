#include<stdio.h>

int lengthOfLongestSubstring(char* s) {
    int max, now, begin, i;
    int map[500] = {0};
    now = begin = max = i = 0;
    while( s[i] != '\0' ) {
        if( map[ s[i] ] == 0 ) {
            map[ s[i] ] = 1;
            now++;
        } else {
            if( now > max ) max = now;
            for( ; s[begin] != s[i]; begin++) {
                map[ s[begin] ] = 0;
                now--;
            }
            begin++;
        }
        i++;
    }
    if( now > max ) max = now;
    // printf("%d\n", max);
    return max;
}

int main(void) {
    char s[5000] = "bpfbhmipx";
    printf("%d", lengthOfLongestSubstring(s) );

    return 0;
}