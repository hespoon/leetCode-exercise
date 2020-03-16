/*
优化的竖式乘法
1. 乘数 num1 位数为 M，乘数 num2 位数为 N，两者乘积 product 的最大中位数为 M+N
2. num1[i] × num2[j] 的结果为 tmp，tmp 的格式为 "0x" 或 "yx"。
   其中低位 x 位于 product[i+j] 的位置，高位 0 或 y 位于 product[i+j+1] 的位置
   高位相当于 num1[i] × num2[j] 产生的进位
*/
#include <string>
using namespace std;
class Solution
{
public:
    struct Bigint
    {                  // 表示大整数的结构体
        int data[222]; // 用于存放大整数的每一位，长度为 M 和 N 的大整数相乘后的位数最大为 M + N
        int len;       // 大整数的长度
        Bigint(string s)
        { // 由字符串构造大整数
            fill(data, data + 222, 0);
            int i = 0, j = s.length() - 1; // 小端存储，数值低位存储在下标低位
            while (j >= 0)
            {
                data[i++] = s[j--] - '0';
            }
            len = i;
        }
        Bigint()
        {
            fill(data, data + 222, 0);
            len = 0;
        }
    };
    string BigintToString(const Bigint &a)
    { // 大整数转换为字符串
        string ans = "";
        for (int i = 0; i < a.len; i++)
        {
            ans = to_string(a.data[i]) + ans;
        }
        return ans;
    }
    Bigint multiplyBigint(const Bigint &a, const Bigint &b)
    {               // 大整数相乘
        Bigint ans; // 结果
        for (int i = 0; i < a.len; i++)
        {
            for (int j = 0; j < b.len; j++)
            {
                int temp = a.data[i] * b.data[j];
                ans.data[i + j] += temp % 10;
                ans.data[i + j + 1] += temp / 10;
            }
        }
        for (int i = 0; i < a.len + b.len - 1; i++)
        { // 处理进位
            if (ans.data[i] >= 10)
            {
                ans.data[i + 1] += ans.data[i] / 10;
                ans.data[i] %= 10;
            }
        }
        for (int i = a.len + b.len - 1; i >= 0; i--)
        { // 确定乘积的位数
            if (ans.data[i] != 0)
            {
                ans.len = i + 1;
                break;
            }
        }
        return ans;
    }
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        Bigint b1(num1);
        Bigint b2(num2);
        Bigint b3 = multiplyBigint(b1, b2);
        string ans = BigintToString(b3);
        return ans;
    }
};