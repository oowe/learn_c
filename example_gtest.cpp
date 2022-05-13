#include <iostream>
//引用gtest函數庫
#include <gtest/gtest.h>

// gtest的命名空間為testing
using namespace testing;
using namespace std;

#define HELLOWORLD "Hello World"

class ABC
{
private:
    int shoeSize = 10;

public:
    string name;
    string gender;
    int printShoeSize()
    {
        return shoeSize;
    }
};

TEST(ABC, printShoeSize)
{
    ABC a;
    a.name = "Aaron";
    a.gender = "Man";
    ASSERT_EQ(1, a.printShoeSize());
}

//一個完整的測項
// TEST(class name.單元測試名稱)
TEST(GoogleTest, HelloWorld)
{
    //(期望值,實際值)
    cout << "run1" << endl;
    ASSERT_EQ("Hello World", HELLOWORLD);
    cout << "run2" << endl;
    ASSERT_EQ("Hello World1", HELLOWORLD);
    cout << "run3" << endl;
    ASSERT_EQ("Hello World", HELLOWORLD);
    cout << "run4" << endl;
    ASSERT_EQ("Hello World", HELLOWORLD);
}

// main function
int main(int argc, char **argv)
{
    //初始化
    InitGoogleTest(&argc, argv);

    //全部測試
    return RUN_ALL_TESTS();

    //部份測試
}