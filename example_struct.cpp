#include <iostream>

using namespace std;

struct ball
{
    string color;
    int size;
    bool statusOK = true;
    ball() //建構子
    {
        cout << "進入建構子" << endl;
        statusOK = false;
    }
} nike;

int main()
{
    // declare method 1
    // struct ball nike;
    // ball nike;
    nike.color = "black";
    nike.size = 29.5;

    // declare method 2
    // ball nike = {"yello", 29, false};

    cout << "Ball's color is " << nike.color << endl;
    cout << "Ball's size is " << nike.size << endl;
    cout << "Ball's statusOK is " << nike.statusOK << endl;

    return 0;
}