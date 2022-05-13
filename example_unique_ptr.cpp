#include <iostream>
#include <memory>

using namespace std;

// void func1(unique_ptr &a)
// {
//     cout << "enter func1" << endl;
// }

// void func2(unique_ptr &b)
// {
//     cout << "enter func2" << endl;
// }

int main()
{
    unique_ptr<int> s1 = make_unique<int>(100);
    unique_ptr<int> s2 = make_unique<int>(200);

    // func1(s1);
    // func2(s2);

    cout << "s1:" << *s1 << endl;
    cout << "s1 postion:" << s1.get() << endl;
    cout << "s2:" << *s2 << endl;
    cout << "s2 postion:" << s2.get() << endl;

    s2 = move(s1);

    // cout << "s1:" << *s1 << endl;  //Segmentation fault (core dumped)
    cout << "s2:" << *s2 << endl;
    cout << "s2 postion:" << s2.get() << endl;

    return 0;
}