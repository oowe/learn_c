#include <iostream>

using namespace std;

int main()
{
    short int a = 10;
    short int b = 3;

    cout << a / b << endl;
    //顯性資料型態轉換
    cout << (float)a / b << endl; //只有強制轉換a的資料型態

    return 0;
}