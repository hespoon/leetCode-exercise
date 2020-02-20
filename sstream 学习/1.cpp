#include <iostream>
#include <sstream>
using namespace std;
int main()
{
    istringstream istr("1 56.7");

    cout << istr.str() << endl; //直接输出字符串的数据 "1 56.7"

    string str = istr.str(); //函数str()返回一个字符串
    cout << str << endl;

    int n = 0;
    double d = 0;

    //以空格为界，把istringstream中数据取出，应进行类型转换
    istr >> n; //第一个数为整型数据，输出1
    istr >> d; //第二个数位浮点数，输出56.7

    cout << "d: " << d << endl;
    cout << "n: " << n << endl;

    cout << istr.str() << endl;

    int a = 0;
    double b = 0;

    //假设换下存储类型
    istr >> b; //第一个数要自动变成浮点型，输出仍为1
    istr >> a; //第二个数要自动变成整型，有数字的阶段，输出为56

    //测试输出
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    return 0;
}