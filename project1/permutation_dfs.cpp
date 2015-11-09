/**
 * Project1 of Combination Math
 * Description: 深度优先算法
 *
 * Author: 
 *    李其乐(2015210918) 
 *    黎健成(2015210936) 
 *    谭川奇(2015310609)
 */

#include <iostream>
using namespace std;
int n;
bool f[100];
int a[100];
void dfs(int  t) {
    if (t == n) {
        for (int i = 0; i < t; ++ i) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; ++ i) {
        if (!f[i]) {
            f[i] = true;
            a[t] = i;
            dfs(t + 1);
            f[i] = false;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        f[i] = false;
    }
    dfs(0);
}
