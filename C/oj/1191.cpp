#include"iostream"
#include"algorithm"

using namespace std;

int main(void) {
    int coun, num, i;
    int a[4];
    while(cin >> num && num != 0) {
        coun = 0;
        while(num != 6174) {
            coun++;
            for(i=0; i<4; i++) {
                a[i] = num % 10;
                num /= 10;
            }
            sort(a, a+4);
            num = a[3]*999 + a[2]*90 - a[1]*90 - a[0]*999;
        }
        cout << coun << endl;
    }

    return 0;
}
