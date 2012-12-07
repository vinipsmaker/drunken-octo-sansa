#include <iostream>
#include <string>
#include <utility>

using namespace std;

typedef pair<int, int> point;

char &p2i(string s, int x, int y)
{
    static char null = '\0';
    if (x < 0 || x > 7 || y < 0 || y > 7)
        return null;
    return s[y * 8 + x];
}

char &p2i(string s, point p)
{
    return p2i(board, p.first, p.second);
}

pair<point, point> find_kings(const string & board)
{
    pair<point, point> aux = make_pair(make_pair(-1,-1), make_pair(-1,-1));
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (p2i(board, i, j) == 'k')
            {
                aux.first = make_pair(i, j);
                if (aux.second != make_pair(-1, -1))
                {
                    return aux;
                }
            }
            else if (p2i(board, i, j) == 'K')
            {
                aux.second = make_pair(i, j);
                if (aux.first != make_pair(-1, -1))
                {
                    return aux;
                }
            }
        }
    }
}

bool check(const string & board, point king)
{
    // king == 'K' + offset
    // opposite == 'k' - offset
    char offset = p2i(board, king) >= 'a' ? 'a' - 'A' : 0;

    // Pawn
    {
        int voffset = p2i(board, king) >= 'a' ? 1 : -1;
        if (p2i(board, king.first - 1, king.second + voffset) == 'p' - offset
            || p2i(board, king.first + 1, king.second + voffset))
            return true;
    }

    // Rook - North
    for (int i = king.second; i > 0; --i)
    {
        if (p2i(board, king.first, i) == 'r' - offset)
        {
            return true;
        }
        else if (p2i(board, king.first, i) != '.')
        {
            break;
        }
    }
}

void work ()
{
    
}

int main()
{
    string board, aux;
    board.reserve(65);
    aux.reserve(9);
    
    int counter = 0;
    
    while (cin >> aux)
    {
        if (aux.empty())
        {
            continue;
        }
        board.push_back(aux);
        for (int i = 0; i != 7; ++i)
        {
            cin >> aux;
            board.push_back(aux);
        }
        cout << "Game #" << counter << ": ";
        work();
    }
}
