#include <iostream>
#include <string>
#define PI 3.14

using namespace std;

int main(void)
{
    // get data type
    int a = 10;
    cout << typeid(a).name() << a << endl;
    // get define
    cout << PI << endl;
    // auto type
    auto i = "string";
    cout << i << endl;

    return 0;
}