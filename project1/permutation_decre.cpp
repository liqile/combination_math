/**
* Author: Jiancheng Li
* Description: generate all permutations of n using 递减进位制数法.
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
struct DecreMediaNumber
{
    vi a; // n - 1 elements, n >= 1
    int n;
    DecreMediaNumber(vi p)
    {
        n = p.size();
        // find the i_th smallest element.
        int rank[n];
        for (int i = 0; i < n; ++i)
            rank[p[i]] = i;
        // assume the element in a is 0 to n - 1.
        for (int i = 1; i < n; ++i)
        {
            int k = rank[i];
            int s = 0;
            for (int j = k + 1; j < n; ++j)
                s += p[j] < p[k];
            a.push_back(s);
        }
    }
    vi getPermutation()
    {
        vi ans(n, 0);
        for (int i = n - 2; i >= 0; --i)
        {
            int s = n;
            for (int j = 0; j <= a[i]; ++j)
            {
                --s;
                while (ans[s])
                    --s;
            }
            ans[s] = i + 1;
        }
        return ans;
    }
    DecreMediaNumber& operator+=(const int d)
    {
        if (n < 2)
            return *this;
        a[n - 2] += d;
        for (int i = n - 2; i > 0 && a[i] >= i + 2; --i)
        {
            a[i - 1] += a[i] / (i + 2);
            a[i] %= (i + 2);
        }
        // assume no overflow
        return *this;
    }
    void print()
    {
        printf("%d", a[0]);
        for (int i = 1; i < n - 1; ++i)
            printf(" %d", a[i]);
        puts("");
    }
};

void output(vi& a)
{
    // print the permutation
    int n = a.size();
    printf("%d", a[0] + 1);
    for (int i = 1; i < n; ++i)
        printf(" %d", a[i] + 1);
    puts("");
}

void solve(int n)
{
    vi a;
    int count = 1;
    for (int i = 1; i <= n; ++i)
    {
        a.push_back(i - 1);
        count *= i;
    }
    while (count--)
    {
        output(a);
        if (count)
        {
            DecreMediaNumber m(a);
            m += 1;
            a = m.getPermutation();
        }
    }
}

int main()
{
    int n;
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    solve(n);
    return 0;
}