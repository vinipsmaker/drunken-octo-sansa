#include <iostream>
#include <sstream>
#include <map>

using namespace std;

inline int digit0(int value)
{
    return value / 100;
}

inline int digit1(int value)
{
    return value % 100 / 10;
}

inline int digit2(int value)
{
    return value % 10;
}

inline int work(map<int, int> &ram)
{
    int ip = 0;
    int registers[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int counter = 1;true;++counter) {
        int i = ram[ip++];
        switch (digit0(i)) {
        case 0:
            // GOTO
            if (registers[digit2(i)])
                ip = registers[digit1(i)];
            break;
        case 1:
            // HALT
            return counter;
        case 2:
            // SET
            registers[digit1(i)] = digit2(i);
            break;
        case 3:
            // ADD
            registers[digit1(i)] += digit2(i);
            registers[digit1(i)] %= 1000;
            break;
        case 4:
            // MULTIPLY
            registers[digit1(i)] *= digit2(i);
            registers[digit1(i)] %= 1000;
            break;
        case 5:
            // SET by reference
            registers[digit1(i)] = registers[digit2(i)];
            break;
        case 6:
            // ADD by reference
            registers[digit1(i)] += registers[digit2(i)];
            registers[digit1(i)] %= 1000;
            break;
        case 7:
            // MULTIPLY by reference
            registers[digit1(i)] *= registers[digit2(i)];
            registers[digit1(i)] %= 1000;
            break;
        case 8:
            // REGISTER := RAM
            registers[digit1(i)] = ram[registers[digit2(i)]];
            break;
        case 9:
            // RAM := REGISTER
            ram[registers[digit2(i)]] = registers[digit1(i)];
        }
    }
}

int main()
{
    int n;
    cin >> n;

    string str;
    // consumes empty line
    getline(cin, str);
    getline(cin, str);

    map<int, int> ram;
    int counter = 0;

    while (getline(cin, str)) {
        if (str.empty()) {
            cout << work(ram) << "\n\n";
            counter = 0;
            ram.clear();
            continue;
        }

        istringstream strin(str);
        strin >> ram[counter++];
    }

    cout << work(ram) << '\n';
    return 0;
}
