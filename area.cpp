#include <iostream>
#include <math.h>

using namespace std;

float area(float);

int main()
{

    float r = 10;
    float ans;
    ans = area(r);
    cout << ans << endl; //需要回傳int

    return 0;
}

/*計算圓面積
  公式: 圓周率*半徑平方
  平方 pow()
 */
float area(float r)
{

    return r = 3.14 * pow(r, 2);
}