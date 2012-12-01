#include <iostream>
#include <string>

using namespace std;

char digits[10] =
  {
    // '0'
    1 | 1 << 1 | 1 << 2 | 1 << 3 | 1 << 4 | 1 << 5,
    // '1'
    1 << 1 | 1 << 2,
    // '2'
    1 | 1 << 1 | 1 << 3 | 1 << 4 | 1 << 6,
    // '3'
    1 | 1 << 1 | 1 << 2 | 1 << 3 | 1 << 6,
    // '4'
    1 << 1 | 1 << 2 | 1 << 5 | 1 << 6,
    // '5'
    1 | 1 << 2 | 1 << 3 | 1 << 5 | 1 << 6,
    // '6'
    1 | 1 << 2 | 1 << 3 | 1 << 4 | 1 << 5 | 1 << 6,
    // '7'
    1 | 1 << 1 | 1 << 2,
    // '8'
    1 | 1 << 1 | 1 << 2 | 1 << 3 | 1 << 4 | 1 << 5 | 1 << 6,
    // '9'
    1 | 1 << 1 | 1 << 2 | 1 << 3 | 1 << 5 | 1 << 6
  };

void work(int s, string m)
{
  const string filled_chunk(s, '-');
  const string empty_chunk(s, ' ');

  // 1 << 0
  for (string::size_type i = 0;i != m.size();++i) {
    if (digits[m[i] - '0'] & 1) {
      cout << ' ' << filled_chunk << ' ';
    } else {
      cout << empty_chunk << "  ";
    }

    if (i != m.size() - 1)
      cout << ' ';
  }
  cout << '\n';

  // 1 << 5 | 1 << 1
  for (int j = 0;j != s;++j) {
    for (string::size_type i = 0;i != m.size();++i) {
      switch (digits[m[i] - '0'] & (1 << 5 | 1 << 1)) {
      case 1 << 5 | 1 << 1:
	cout << '|' << empty_chunk << '|';
	break;
      case 1 << 5:
	cout << '|' << empty_chunk << ' ';
	break;
      case 1 << 1:
	cout << ' ' << empty_chunk << '|';
	break;
      default:
	cout << empty_chunk << "  ";
      }

      if (i != m.size() - 1)
	cout << ' ';
    }
    cout << '\n';
  }

  // 1 << 6
  for (string::size_type i = 0;i != m.size();++i) {
    if (digits[m[i] - '0'] & 1 << 6) {
      cout << ' ' << filled_chunk << ' ';
    } else {
      cout << empty_chunk << "  ";
    }

    if (i != m.size() - 1)
      cout << ' ';
  }
  cout << '\n';

  // 1 << 4 | 1 << 2
  for (int j = 0;j != s;++j) {
    for (string::size_type i = 0;i != m.size();++i) {
      switch (digits[m[i] - '0'] & (1 << 4 | 1 << 2)) {
      case 1 << 4 | 1 << 2:
	cout << '|' << empty_chunk << '|';
	break;
      case 1 << 4:
	cout << '|' << empty_chunk << ' ';
	break;
      case 1 << 2:
	cout << ' ' << empty_chunk << '|';
	break;
      default:
	cout << empty_chunk << "  ";
      }

      if (i != m.size() - 1)
	cout << ' ';
    }
    cout << '\n';
  }

  // 1 << 3
  for (string::size_type i = 0;i != m.size();++i) {
    if (digits[m[i] - '0'] & 1 << 3) {
      cout << ' ' << filled_chunk << ' ';
    } else {
      cout << empty_chunk << "  ";
    }

    if (i != m.size() - 1)
      cout << ' ';
  }
  cout << '\n';
}

int main()
{
  int s;
  string m;
  while (cin >> s >> m && (s || m != "0")) {
    work(s, m);
    cout << '\n';
  }
  return 0;
}
