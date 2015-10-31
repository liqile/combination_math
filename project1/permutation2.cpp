#include <iostream>
using namespace std;
int a[10];
bool f[10];
int n;
void init() {
    a[0] = 1;
    for (int i = 1; i <= n; ++ i) {
        a[i] = a[i - 1] * i;
    }
}
void generate(int order, bool* f) {
    int w = order;
    for (int i = 0; i < n; ++ i) {
        f[i] = false;
    }
    for (int i = n; i > 0; -- i) {
        int j;
        for (j = 0; j < i; ++ j) {
            if (j * a[i - 1] >= w) {
                break;
            }
        }
        int count = 0;
        for (int k = 0; k < n; ++ k) {
            if (!f[k]) {
                ++ count;
                if (count == j) {
                    f[k] = true;
                    //cout << j <<  " " <<  k << " ";
                    w -= (j - 1) * a[i - 1];
                    cout << k << " ";
                    break;
                }
            }
        }
    }
//    cout << w << endl;
    cout << endl;
}
void printAll(int s, int t) {
    for (int order = s; order <= t; ++ order) {
        generate(order, f);
    }
}
int main() {
    while (true) {
        cin >> n;
        init();
        printAll(1, a[n]);
    }
}
