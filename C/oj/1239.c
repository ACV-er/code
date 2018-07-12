#include<stdio.h>

char inst[10];
int a[4][4];

void show(void) {
	int i, j;
	for(i=0; i<4; i++) {
	    for(j=0; j<3; j++) {
	        printf("%d ", a[i][j]);
	    }
	    printf("%d\n", a[i][j]);
	}
	printf("\n");
	
	return;
}

void move(void) {
    int i, j, cnt;
    if(inst[0] == 'L') {
        for(i=0; i<4; i++) {
            for(j=0, cnt=0; j<4; j++) {
                if( a[i][j] == 0 ) {
                    continue;
                } else {
                    a[i][cnt++] = a[i][j];
                    if(cnt != j+1)
                    a[i][j] = 0;
                }
            }
            for(j=0; j<3; j++) {
                if( a[i][j] == a[i][j+1] && a[i][j] != 0) {
                    a[i][j] *= 2;
                    a[i][j+1] = 0;
                } else {
                    continue;
                }
            }
            for(j=0, cnt=0; j<4; j++) {
                if( a[i][j] == 0 ) {
                    continue;
                } else {
                    a[i][cnt++] = a[i][j];
                    if(cnt != j+1)
                    a[i][j] = 0;
                }
            }
        }
    } else if(inst[0] == 'U') {
        for(i=0; i<4; i++) {
            for(j=0, cnt=0; j<4; j++) {
                if( a[j][i] == 0 ) {
                    continue;
                } else {
                    a[cnt++][i] = a[j][i];
                    if(cnt != j+1)
                    a[j][i] = 0;
                }
            }
            for(j=0; j<3; j++) {
                if( a[j][i] == a[j+1][i] && a[j][i] != 0) {
                    a[j][i] *= 2;
                    a[j+1][i] = 0;
                } else {
                    continue;
                }
            }
            for(j=0, cnt=0; j<4; j++) {
                if( a[j][i] == 0 ) {
                    continue;
                } else {
                    a[cnt++][i] = a[j][i];
                    if(cnt != j+1)
                    a[j][i] = 0;
                }
            }
        }
    } else if(inst[0] == 'D') {
        for(i=3; i>=0; i--) {
            for(j=3, cnt=3; j>-1; j--) {
                if( a[j][i] == 0 ) {
                    continue;
                } else {
                    a[cnt--][i] = a[j][i];
                    if(cnt != j-1)
                    a[j][i] = 0;
                }
            }
            for(j=3; j>0; j--) {
                if( a[j][i] == a[j-1][i] && a[j][i] != 0) {
                    a[j][i] *= 2;
                    a[j-1][i] = 0;
                } else {
                    continue;
                }
            }
            for(j=3, cnt=3; j>-1; j--) {
                if( a[j][i] == 0 ) {
                    continue;
                } else {
                    a[cnt--][i] = a[j][i];
                    if(cnt != j-1)
                    a[j][i] = 0;
                }
            }
        }
    } else if(inst[0] == 'R') {
        for(i=3; i>=0; i--) {
            for(j=3, cnt=3; j>-1; j--) {
                if( a[i][j] == 0 ) {
                    continue;
                } else {
                    a[i][cnt--] = a[i][j];
                    if(cnt != j-1)
                    a[i][j] = 0;
                }
            }
            for(j=3; j>0; j--) {
                if( a[i][j] == a[i][j-1] && a[i][j] != 0) {
                    a[i][j] *= 2;
                    a[i][j-1] = 0;
                } else {
                    continue;
                }
            }
            for(j=3, cnt=3; j>-1; j--) {
                if( a[i][j] == 0 ) {
                    continue;
                } else {
                    a[i][cnt--] = a[i][j];
                    if(cnt != j-1)
                    a[i][j] = 0;
                }
            }
        }
    }

    return;
}

int main(void) {
    int N, i, j;
    scanf("%d", &N);
    while(N--) {
        for(i=0; i<4; i++) {
            for(j=0; j<4; j++) {
                scanf("%d", &a[i][j]);
            }
    	}
        scanf("%s", inst);
        move();
        show();
    }

    return 0;
}
