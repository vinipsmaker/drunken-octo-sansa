#include <iostream>
using namespace std;

inline int straightflush(const vector<string> &YyY)
{
    char menor = YyY[0][0];
    for (int i = 1; i < 5; ++i)
	{
            if (YyY[i][0] < menor)
                menor = YyY[i][0];
            if (YyY[0][1] != YyY[i][1])
                return 0;
	}

    for (int i = 0; i < 5; ++i)
        {
            if (YyY[i][0] > menor + 4)
                return 0;
        }

    // tipo_jogo*13*13+maior_carta*13+outro_criterio_desempate
    return 9*13*13;
}

inline int fourofakind(const vecto<string> &s)
{
    char count[] = {0, 0, 0, 0};
    for (int i = 0; i < 5; ++i)
        {
            count[s[i][1]]++;
        }

    for (int i = 0; i < 5; ++i)
        {
            if (count[i] == 4)
                return 8*13*13;
        }

    return 0;
}


inline int code(const vector<string> &YyY)
{
	
    if (straightflush(YyY))
        return 9;

}

inline void work(const vector<string> &black, const vector<string> &white)
{
    if (code(black) > code(white))
        ;
}

inline void nyan(string &s)
{
    char &c = s[0];
    switch (c) {
    case 'T':
        c = '9' + 1;
        break;
    case 'J':
        c = '9' + 2;
        break;
    case 'Q':
        c = '9' + 3;
        break;
    case 'K':
        c = '9' + 4;
        break;
    case 'A':
        c = '9' + 5;
        break;
    }

    c -= '2';

    switch (s[1]) {
    case 'C':
        s[1] = 0;
        break;
    case 'D':
        s[1] = 1;
        break;
    case 'H':
        s[1] = 2;
        break;
    case 'S':
        s[1] = 3;
    }
}

int main ()
{
    vector<string> white(5);
    vector<string> black(5);
    for (int i = 0; i < 5; ++i)
	{
            cin >> black[i];
            nyan(black[i]);
	}
    for (i = 0; i < 5; ++i)
	{
            cin >> white[i]
            nyan(white[i]);
        }

    work(black, white);

    return 0;
}
