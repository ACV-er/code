#include"iostream"
#include"algorithm"
#include"iomanip"

using namespace std;

int main(void) {
    int N, i, sum;
    double arv;
    int scr[55];
    while(cin >> N && N != 0) {
        for(i=0; i<N; i++) {
            cin >> scr[i];
        }
        sort(scr, scr+N);
        N--;
        for(i=1, sum=0; i<N; i++) {
            sum += scr[i];
        }
 //       cout << sum << " " << N << endl;
        N--;
        arv = (double)sum/(double)N;
        cout << fixed <<setprecision(1) << arv << endl;
    }

    return 0;
}
