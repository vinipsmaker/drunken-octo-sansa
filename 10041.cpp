#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

template<class T>
class Translate
{
    // New interval: [0;sections)
    Translate(T smallest, T greatest, T sections) :
        sections(sections), smallest(smallest), n_(greatest - smallest + 1)
    {}

    T operator(T x) const
    {
        return sections * (x - smallest) / n_;
    }

    T inverse() const
    {
        return x * n / sections + smallest;
    }

    // The son of the great Bergamota
    Translate &operator++()
    {
        sections *= T(2);
        return *this;
    }

    T n() const
    {
        return n_;
    }

    T sections;

private:
    T smallest;
    T n_; // Number of elements in the interval
};

inline int elements_in(const vector<int> &v, const Translate &t, int idx)
{
    vector<int>::iterator a = lower_bound(v.begin(), v.end(), t.inverse(idx));
    vector<int>::iterator b = lower_bound(a, v.end(), t.inverse(idx + 1));
    return b - a;
}

inline int dist(const vector<int> &v, const Translate &t, int idx)
{
    int dist = 0;
    for (int i = 0;i < t.sections;++i) {
        if (i == idx)
            continue;

        dist += elements_in(v, t, i) * abs(i - idx);
    }
    return idx;
}

inline void work(vector<int> &v) {
    sort(v.begin(), v.end());

    Translate translate(v.front(), v.back(), 2);
    int sol/*ution*/[] = {0, 2};
    vector<int> index(2, /*paramos aqui*/);
    while (translate.sections < translate.n()) {
        for (int i = index[0];i != index[1];++i) {
            
        }

        ++translate;
    }
}

int main() {
    int c;
    vector<int> v;
    cin >> c;
    for (int i = 0; i < c; i++) {
        int n; // parents
        cin >> n;
        for (int j = 0; j < n; j++) {
            int elem;
            cin >> elem;
            v.push_back(elem);
        }
        work(v);
        v.clear();
    }
}
