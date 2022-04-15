#include <iostream>

using namespace std;

int main()
{
    int level;
    cout << "請輸入你的英文等級:1(low), 2(middle), 3(high)" << endl;
    cin >> level;
    switch (level)
    {
    case 1:
        cout << "初級班" << endl;
        break;
    case 2:
        cout << "中級班" << endl;
        break;
    case 3:
        cout << "高級班" << endl;
        break;
    default:
        cout << "輸入錯誤！請再次確認..." << endl;
        break;
    }

    return 0;
}