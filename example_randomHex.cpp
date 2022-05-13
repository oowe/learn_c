#include <iostream>

using namespace std;

class RandomHex
{
private:
    static char m_hexDigits[];

public:
    RandomHex();
    virtual ~RandomHex();

    string generateRandomHex(int length = 10);

    void seed(unsigned int seed);
};

char RandomHex::m_hexDigits[] = "0123456789ABCDEF";

RandomHex::RandomHex()
{
    srand(time(NULL));
}

/********************************************************************************/

RandomHex::~RandomHex()
{
}

/********************************************************************************/

string RandomHex::generateRandomHex(int length)
{
    string s;

    for (int x = 0; x < length; x++)
        s.append(1, m_hexDigits[rand() % 16]);

    return s;
}

/********************************************************************************/

void seed(unsigned int seed)
{
    srand(seed);
}

int main(void)
{
    RandomHex m_randomHex;
    cout << m_randomHex.generateRandomHex() << endl;

    return 0;
}
