/**
 * Project1 of Combination Math
 * Description: Implementation by STL library，观察一下工业界的全排列是如何实现的
 *
 * Author: 
 *    李其乐(2015210918) 
 *    黎健成(2015210936) 
 *    谭川奇(2015310609)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

void permutation(vector<int> &v) {
  sort(v.begin(), v.end());
  do {
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
  }while(next_permutation(v.begin(), v.end()));
}

int main(void) {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (size_t i = 0; i < n; ++i) {
    vec[i] = i;
  }

  permutation(vec);
  return 0;
}
