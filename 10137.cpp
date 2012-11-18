#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

inline double truncate(double d)
{
  int tmp = d * pow(10, 2);
  return tmp / pow(10, 2);
}

inline double work(const vector<double> &v)
{
  double avg = 0.0;
  for (vector<double>::size_type i = 0;i != v.size();++i) {
    avg += v[i];
  }
  avg /= v.size();
  
  double pos = 0.0, neg = 0.0;
  for (vector<double>::size_type i = 0;i != v.size();++i) {
    double aux = v[i] - avg;
    (aux > 0) ? pos += truncate(aux): neg += truncate(-aux);
  }
  pos = truncate(pos);
  neg = truncate(neg);

  printf("~~~%.20f\n", pos);
  printf("~~~%.20f\n", neg);
  printf("~~~%.20f\n", fabs(pos - neg));
  //printf("~~~%.20f\n", truncate(0.01));
  //printf("~~~%.20f\n", fabs(fabs(pos - neg) - truncate(0.01)));
  if (truncate(0.01) < fabs(pos - neg)) {
  //if (fabs(fabs(pos - neg) - truncate(0.01)) > 0.001) {
    printf(">>>>><<<<<\n");
    return (pos + neg) * 0.5;
  } else {
    printf("<<<<<>>>>>\n");
    return truncate(min(pos, neg));
  }
}

int main()
{
  int n;
  vector<double> v;
  while(cin >> n && n) {
    double aux;
    v.reserve(n);
    for (int i = 0;i < n; i++){
      cin >> aux;
      v.push_back(aux);
    }
    printf("$%.2lf\n", work(v));
    v.clear();
  }
  return 0;
}
