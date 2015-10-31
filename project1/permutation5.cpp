#include <iostream>
using namespace std;
int n;
int a[10];
bool f[10]; //false: left, true: right;
void print() {
    for (int i = 0; i < n; ++ i) {
        cout << a[i] << " ";
    }
    cout << endl;
}
bool moveable(int p) {
    if (f[p]) {
        if (p == n - 1) {
            return false;
        }
        if (a[p] > a[p + 1]) {
            return true;
        }
    } else {
        if (p == 0) {
            return false;
        }
        if (a[p] > a[p - 1]) {
            return true;
        }
    }
    return false;
}
void move(int p) {
    if (f[p]) {
        int k = a[p + 1];
        a[p + 1] = a[p];
        a[p] = k;
        bool kk = f[p + 1];
        f[p + 1] = f[p];
        f[p] = kk;
    } else {
        int k = a[p - 1];
        a[p - 1] = a[p];
        a[p] = k;
        bool kk = f[p - 1];
        f[p - 1] = f[p];
        f[p] = kk;
    }
}
void change(int m) {
    for (int i = 0; i < n; ++ i) {
        if (a[i] > m) {
            f[i] = (!f[i]);
        }
    }
}
bool hasNext() {
    int m = -1;
    int idx = -1;
    for (int i = 0; i < n; ++ i) {
        if (moveable(i) && a[i] > m) {
            m = a[i];
            idx = i;
        }
    }
    if (m == -1) {
        return false;
    }
    move(idx);
    change(m);
    return true;
}
int main() {
    while(true) {
        cin >> n;
        for (int i = 0 ; i < n; ++ i) {
            a[i] = i;
            f[i] = false;
        }
        print();
        while(hasNext()) {
            print();
        }
    }
}
