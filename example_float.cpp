#include <iostream>

using namespace std;

int main()
{
    short int a = 10;
    short int b = 3;

    cout << a / b << endl;
    //顯性資料型態轉換
    cout << (float)a / b << endl;

    return 0;
}