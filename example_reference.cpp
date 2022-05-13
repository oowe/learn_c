#include <iostream>

using namespace std;

void add(int &a, int &b)
{
    a += 10;
    b += 10;
}

int main(void)
{
    // example1
    int a = 5;
    int b = 1;
    int &ref = a;
    //報錯，參照一旦指定後就不能重複指定
    // float &ref = b;

    cout << "a's address:" << &a << endl;
    cout << "&ref's address:" << &ref << endl;

    cout << "a's value:" << a << endl;
    cout << "&ref's value:" << ref << endl;

    ref = 10;
    cout << "令ref = 10" << endl;

    cout << "a's value:" << a << endl;
    cout << "&ref's value:" << ref << endl;

    // example2
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;

    add(a, b);
    cout << "run add() function" << endl;
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;

    return 0;
}