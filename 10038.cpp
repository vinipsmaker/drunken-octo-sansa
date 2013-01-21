#include <iostream>
#include <cstdlib>
#include <set>

using namespace std;

inline int diff(int a, int b)
{
  return abs(b - a);
}

inline int sum_n(int n)
{
  return double(1 + n) * double(n) / 2.;
}

int main()
{
  for (int n;cin >> n;) {
    int v[2];
    set<int> found;
    bool second = false;
    for (int i = 0;i != n;++i) {
      cin >> v[i % 2];
      if (second)
	found.insert(diff(v[0], v[1]));
      else
	second = true;
    }
    bool was_found = true;
    for (int i = 1;i != n;++i) {
      if (found.count(i) == 0){
	was_found = false;
	break;
      }
    }
    cout << (was_found ? "Jolly" : "Not jolly") << endl;
  }
  return 0;
}
