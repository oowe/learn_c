#include <iostream>

using namespace std;

class Motor
{
private:
    float pwm = 1.1;

public:
    string name;

    float print_pwm()
    {
        return pwm;
    }
};

int main(void)
{
    Motor a;
    a.name = "DELTA";
    cout << a.name << endl;
    cout << a.print_pwm() << endl;

    return 0;
}