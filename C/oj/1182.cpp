#include"iostream"
#include"iomanip"

using namespace std;

int main(void) {
    int N, i;
    double x, y;
    int a[12];
    cin >> N;
    while(N--) {
        x = 1;
        for(i=0; i<12; i++) {
            cin >> a[i];
        }
        for(i=0; i<12; i++) {
            x *= 1.0 + double(a[i])/100.0;
        }
        cout <<fixed<<setprecision(3) << (x-1.0)*100 << endl;
    }

    return 0;
}
