#include <iostream>

using namespace std;

int main(void)
{
    int sum = 0;
    int max = 100;

    for (int i = 0; i <= max; i++)
    {
        sum += i;
    }
    cout << "1+2+3+...+" << max << "=" << sum << endl;
    return 0;
}