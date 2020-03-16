/*
普通竖式乘法
将大整数 A 的每一位与大整数 B 相乘，然后将结果相加，注意处理进位。
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
    Bigint add(const Bigint &a, const Bigint &b)
    { // 大整数相加
        int carry = 0, i = 0, j = 0, k = 0, temp;
        Bigint ans;
        while (i < a.len || j < b.len)
        {
            if (i < a.len)
            {
                carry += a.data[i++];
            }
            if (j < b.len)
            {
                carry += b.data[j++];
            }
            ans.data[k++] = carry % 10;
            carry /= 10;
        }
        if (carry)
        { // 加法的进位只有一位
            ans.data[k++] = carry;
        }
        ans.len = k;
        return ans;
    }
    Bigint multiply(const Bigint &a, const int &b)
    { // 大整数乘以一个普通整数
        Bigint ans;
        int carry = 0;
        for (int i = 0; i < a.len; i++)
        {
            carry += (a.data[i] * b);
            ans.data[ans.len++] = carry % 10;
            carry /= 10;
        }
        while (carry)
        { // 乘法可能有多个进位
            ans.data[ans.len++] = carry % 10;
            carry /= 10;
        }
        return ans;
    }
    Bigint modBigint(const Bigint &a)
    { // 大整数对 10 取模，用于进位处理
        Bigint ans;
        for (int i = 1; i < a.len; i++)
        {
            ans.data[ans.len++] = a.data[i];
        }
        return ans;
    }
    Bigint multiplyBigint(const Bigint &a, const Bigint &b)
    {                      // 大整数相乘
        Bigint carry, ans; // 进位和结果
        for (int i = 0; i < a.len; i++)
        {
            carry = add(carry, multiply(b, a.data[i]));
            ans.data[ans.len++] = carry.data[0]; // 进位的最低位放入结果中
            carry = modBigint(carry);            // 进位的其他位作为新的进位
        }
        for (int i = 0; i < carry.len; i++) // 将最后的进位放入结果中
        {
            ans.data[ans.len++] = carry.data[i];
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