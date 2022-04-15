#include <iostream>

using namespace std;

int main(void)
{
    int target = 5050;
    int i = 0;
    int sum = target;

    while (sum > 0)
    {
        ++i;
        sum -= i;
    }

    if (sum < 0)
    {
        cout << "不符合" << endl;
    }
    else
    {
        cout << target << "=1+2+3+...+" << i << endl;
        cout << "target postion:" << &target << endl;
        cout << "sum postion:" << &sum << endl;
    }

    return 0;
}