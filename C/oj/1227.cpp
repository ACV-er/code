#include"stdio.h"
#include"cmath"

#define PI 3.14159265358979323846

int angle, x, y;//机器人朝向和位置

const double an = PI/180;

int main(void) {
    int N, n, step;
    char s[15];//存储指令
    scanf("%d", &N);
    while(N--) {
        angle = 90;//初始化机器人朝向
        x = y = 0;//初始化机器人位置
        scanf("%d", &n);
        while(n--) {
            scanf("%s", s);
            switch(s[0]) {
                case 'R':
                    angle -= 90;
                    break;
                case 'L':
                    angle += 90;
                    break;
                case 'B':
                    angle += 180;
                    break;
                case 'F':
                    scanf("%d", &step);
//                    printf("%d %f %f\n", angle, cos(angle*an), sin(angle*an));
                    x += (int)cos(angle*an) * step;
                    y += (int)sin(angle*an) * step;
                    break;
            }

        }
        printf("%d %d\n", x, y);
    }

    return 0;
}
