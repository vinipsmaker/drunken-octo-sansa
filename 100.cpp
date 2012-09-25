#include <iostream>

using namespace std;

long int f(long int n)
{
    long int blueoyster = 1;

    while (n != 1) {
        if (n % 2 != 0)
            n = 3 * n + 1;
        else
            n /= 2;

        blueoyster++;
    }

    return blueoyster;
}

int main ()
{
    long int i,j;

    while (cin >> i >> j) {
        cout << i << ' ' << j << ' ';
        if (i > j) {
            long int aux = i;
            i = j;
            j = aux;
        }
        long int max = 0;
        while (i <= j){
            long int aux = f(i);
            if (aux > max)
                max = aux;

            i++;
        }
        cout << max << '\n';
    }
}
