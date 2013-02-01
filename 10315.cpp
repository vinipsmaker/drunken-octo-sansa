#include <iostream>
using namespace std;

inline bool straightflush(const vector<string> &YyY)
{
	bool truth = true;
	for (int i = 1; i < 5; ++i)
	{
		if (YyY[0][1] != YyY[i][1])
			return false;
	}



	return truth;
}


inline int code(const vector<string> &YyY)
{
	
	if (straightflush(YyY))
		return 9;

}

inline void work(const vector<string> &black, const vector<string> &white)
{
	if (code(black) > code(white))

}

int main ()
{
	vector<string> white(5);
	vector<string> black(5);
	for (int i = 0; i < 5; ++i)
	{
		cin >> black[i];

	}
	for (i = 0; i < 5; ++i)
	{
		cin >> white[i]
	}

	work(black, white);

	return 0;
}
