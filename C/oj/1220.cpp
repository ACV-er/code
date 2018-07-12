#include"iostream"

using namespace std;

int main(void) {
    int N, sum;
    cin >> N;
    while(N--) {
        int n;
        cin >> n;
        sum = (7*n - 6)*(n-1)/2 + 1;
        cout << sum << endl;

    }

    return 0;
}
