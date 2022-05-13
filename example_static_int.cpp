#include <iostream>

using namespace std;

void func(void)
{
    static int a = 10;
    a += 20;
    cout << a << endl;
}

int main(void)
{
    func();
    func();
    func();

    return 0;
}

/*
    30
    50
    70
*/