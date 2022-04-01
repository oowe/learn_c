#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{

    int a = 10;
    int b = 6;
    int c;

    // tradition
    if (a > b)
    {
        c = a;
    }
    else
    {
        c = b;
    }
    // mehod2
    //  c = (a > b) ? a : b;
    cout << c << endl;

    return 0;
}