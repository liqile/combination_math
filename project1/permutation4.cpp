#include <iostream>
using namespace std;
void reverse(int* a, int n) {
    for (int i = 0; i < (n >> 1); ++ i) {
        int x = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = x;
    }
}
void getNextSub(int* a, int n) {
    for (int i = n - 1; i > 0; -- i) {
        if (a[i] > a[0]) {
            int k = a[0];
            a[0] = a[i];
            a[i] = k;
            reverse(a + 1, n - 1);
            break;
        }
    }
}
bool getNext(int* a, int n) {
    int i = n - 2;
    while (i >= 0) {
        if (a[i] < a[i + 1]) {
            break;
        }
        i --;
    }
    if (i < 0) {
        return false;
    }
    getNextSub(a + i, n - i);
    return true;
}
void print(int* a, int n) {
    for (int i = 0; i < n; ++ i) {  
        cout << a[i] << " ";
    }
    cout << endl;
}
int main() {
    int* a = new int[10];
    while (true) {  
        int n;
        cin >>n;
        for (int i = 0; i < n; ++ i) {  
            a[i] = i;
        }
        print(a, n);
        while (getNext(a, n)) {
            print(a, n);
        }
    }
}
