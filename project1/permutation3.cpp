#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
using namespace std;
int a[10];
bool f[10];
int n;
pthread_t ntid[10];
pthread_mutex_t wm;
struct Arg {
    int s;
    int t;
    bool* f;
    int* p;
};
Arg arg[10];
void init() {
    a[0] = 1;
    for (int i = 1; i <= n; ++ i) {
        a[i] = a[i - 1] * i;
    }
}
void generate(int order, bool* f, int* p) {
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
                    p[n - i] = k;
                    break;
                }
            }
        }
    }
    pthread_mutex_lock(&wm);
    for (int i = 0; i < n; ++ i) {
        cout << p[i] << " ";
    }
    cout << endl;
    pthread_mutex_unlock(&wm);
}
void printAll(int s, int t, bool* f, int* p) {
    for (int order = s; order <= t; ++ order) {
        generate(order, f, p);
    }
}
void* threadFunc(void* arg) {
    Arg* a = (Arg*) arg;
    int s = a->s;
    int t = a->t;
    bool* f = a->f;
    int* p = a->p;
    printAll(s, t, f, p);
    return NULL;
}
int main() {
    while (true) {
        cin >> n;
        init();
        int k = 10;
        if (k > a[n]) {
            k = a[n];
        }
        int start = 1;
        int len = a[n] / k;
        for (int i = 0; i < k; ++ i) {
            arg[i].f = new bool[10];
            arg[i].p = new int[10];
            arg[i].s = start;
            arg[i].t = start + len - 1;
            start = start + len;
        }
        arg[k - 1].t = a[n];
        for (int i = 0; i < k; ++ i) {
            pthread_create(&ntid[i], NULL, threadFunc, &arg[i]);
        }
        for (int i = 0; i < k; ++ i) {
            pthread_join(ntid[i], NULL);
        }
    }
}
