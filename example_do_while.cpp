#include <iostream>

using namespace std;

int main()
{
    int maxInput = 3;
    int input;
    int answer = 1234;
    int i = 0;
    do
    {
        cout << "請輸入密碼:" << endl;
        cin >> input;
        if (input == answer)
        {
            cout << "密碼正確" << endl;
            break;
        }
        else
        {
            cout << "密碼錯誤!" << endl;
            i++;
            if (i == maxInput)
                break;
        }
    } while (i < maxInput);

    return 0;
}