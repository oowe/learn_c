#include <iostream>
#include <memory>

using namespace std;

int main()
{
    shared_ptr<int> a;
    {
        // shared_ptr<int> b(new int(10));
        shared_ptr<int> b = make_shared<int>(10);
        a = b;
        {
            shared_ptr<int> c = a;
            *c = 100;
        }
    }
    cout << *a << endl;
    return 0;
}