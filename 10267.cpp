#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stack>
#include <algorithm> 
#include <utility>
#include <sstream>

using namespace std;

struct matrix {
  char &operator()(int x, int y) {
    return v[y * width + x];
  }

  void set_size(int w, int h) {
    v.clear();
    v.resize(w * h, 'O');
    width = w;
    height = h;
  }

  void clear() {
    set_size(width, height);
  }

  void color(int x, int y, char c) {
    (*this)(x, y) = c;
  }

  void v_segment(int x, int y1, int y2, char c) {
    for (int i = y1; i <= y2; i++) {
      (*this)(x, i) = c;
    }
  }

  void h_segment(int x1, int x2, int y, char c) {
    for (int i = x1; i <= x2; i++) {
      (*this)(i, y) = c;
    }
  }

  void rectangle(int x1, int y1, int x2, int y2, char c) {
    for (int i = y1; i <= y2; i++) {
      h_segment(x1, x2, i, c);
    }
  }

  /*
   * I'm naming this algorithm as Bergamota
   * Have fun trying to understand it
   */
  void fill(int x, int y, char c) {
    stack<pair<int, int> > s;
    const char initial_color = (*this)(x, y);
    set<pair<int, int> > visited;

    s.push(make_pair(x, y));
    visited.insert(s.top());

    while (s.size()) {
      (*this)(s.top()) = c;
      vector<pair<int, int> > new_ = unvisited(neighbors(s.top(), initial_color),
					       visited);
      s.pop();
      for (vector<pair<int, int> >::size_type i = 0;i != new_.size();++i) {
        visited.insert(new_[i]);
	s.push(new_[i]);
      }
    }
  }

  void write(string name) {
    cout << name << '\n';
    for (int j = 0; j < height; j++) {
      for (int i = 0; i < width; i++) {
	cout << (*this)(i, j);
      }
      cout << '\n';
    }
  }

private:
  vector<pair<int, int> > unvisited(vector<pair<int, int> > v,
				    const set<pair<int, int> > &filter)
  {
    vector<pair<int, int> > ret;

    for (vector<pair<int, int> >::size_type i = 0;i != v.size();++i) {
      if (!filter.count(v[i]))
        ret.push_back(v[i]);
    }

    return ret;
  }

  vector<pair<int, int> > neighbors(pair<int, int> c, char filter)
  {
    vector<pair<int, int> > ret;

    {
      pair<int, int> top = make_pair(c.first, c.second - 1);
      if (top.second >= 0 && (*this)(top) == filter)
	ret.push_back(top);
    }
    {
      pair<int, int> right = make_pair(c.first + 1, c.second);
      if (right.first < width && (*this)(right) == filter)
	ret.push_back(right);
    }
    {
      pair<int, int> bottom = make_pair(c.first, c.second + 1);
      if (bottom.second < height && (*this)(bottom) == filter)
	ret.push_back(bottom);
    }
    {
      pair<int, int> left = make_pair(c.first - 1, c.second);
      if (left.first >= 0 && (*this)(left) == filter)
	ret.push_back(left);
    }

    return ret;
  }

  char &operator()(pair<int, int> c)
  {
    return (*this)(c.first, c.second);
  }

  vector<char> v;
  int width;
  int height;
};

int main() {
  string line;
  matrix m;
  while (getline(cin, line) && line[0] != 'X') {
    istringstream linein(line);
    {
      string cmd;
      linein >> cmd;
    }
    switch(line[0]) {
    case 'I' :{
      int M;
      int N;
      linein >> M >> N;
      m.set_size(M, N);}
      break;
    case 'C' : m.clear();
      break;
    case 'L' :{
      int x;
      int y;
      string c;
      linein >> x >> y >> c;
      m.color(x - 1, y - 1, c[0]);}
      break;
    case 'V' :{
      int x;
      int y1;
      int y2;
      string c;
      linein >> x >> y1 >> y2 >> c;
      if (y2 < y1) swap(y1, y2);
      m.v_segment(x - 1, y1 - 1, y2 - 1, c[0]);}
      break;
    case 'H' :{
      int x1;
      int x2;
      int y;
      string c;
      linein >> x1 >> x2 >> y >> c;
      if (x2 < x1) swap(x1, x2);
      m.h_segment(x1 - 1, x2 - 1, y - 1, c[0]);}
      break;
    case 'K' :{
      int x1;
      int y1;
      int x2;
      int y2;
      string c;
      linein >> x1 >> y1 >> x2 >> y2 >> c;
      m.rectangle(x1 - 1, y1 - 1, x2 - 1, y2 - 1, c[0]);}
      break;
    case 'F' :{
      int x;
      int y;
      string c;
      linein >> x >> y >> c;
      m.fill(x - 1, y - 1, c[0]);}
      break;
    case 'S' :{
      string name;
      linein >> name;
      m.write(name);}
      break;
    }
  }
}
