#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

inline char count_mines(const vector<string> &lines, const size_t line,
                        const size_t column)
{
    char mines = '0';

    const size_t line_count = lines.size();
    const size_t column_count = lines[0].size();

    // top-left
    if (line != 0 && column != 0) {
        if (lines[line - 1][column - 1] == '*')
            ++mines;
    }

    // top
    if (line != 0) {
        if (lines[line - 1][column] == '*')
            ++mines;
    }

    // top-right
    if (line != 0 && column < column_count - 1) {
        if (lines[line - 1][column + 1] == '*')
            ++mines;
    }

    // right
    if (column < column_count - 1) {
        if (lines[line][column + 1] == '*')
            ++mines;
    }

    // bottom-right
    if (line < line_count - 1 && column < column_count - 1) {
        if (lines[line + 1][column + 1] == '*')
            ++mines;
    }

    // bottom
    if (line < line_count - 1) {
        if (lines[line + 1][column] == '*')
            ++mines;
    }

    // bottom-left
    if (line < line_count - 1 && column != 0) {
        if (lines[line + 1][column - 1] == '*')
            ++mines;
    }

    // left
    if (column != 0) {
        if (lines[line][column - 1] == '*')
            ++mines;
    }

    return mines;
}

inline void do_work(int line_count, int column_count)
{
    // init and feed variables with user input
    vector<string> lines(line_count, string());
    for (vector<string>::iterator i = lines.begin();i != lines.end();++i) {
        i->reserve(column_count);
        cin >> *i;
        //replace(i->begin(), i->end(), '.', '0');
    }

    // calculate
    for (int i = 0;i != line_count;++i) {
        for (int j = 0;j != column_count;++j) {
            if (lines[i][j] != '*')
                lines[i][j] = count_mines(lines, i, j);
        }
    }

    // print
    for (size_t i = 0;i != line_count;++i) {
        cout << lines[i] << '\n';
    }
}

int main()
{
    int n, m;
    int field = 0;
    bool print_space = false;

    while (cin >> n >> m) {
        if (!n && !m)
            return 0;

        if (print_space)
            cout << '\n';
        else
            print_space = true;

        cout << "Field #" << ++field << ":\n";
        do_work(n, m);
    }
}
