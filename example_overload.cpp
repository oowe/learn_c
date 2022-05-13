#include <iostream>

using namespace std;

int add(int i, int j)
{
    return i + j;
}

int add(int i, int j, int k, int d = 10)
{
    return i + j + k + d;
}

int main(void)
{
    cout << add(1, 2) << endl;
    cout << add(1, 2, 3) << endl;

    return 0;
}
