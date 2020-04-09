#include <string>
#include <iostream>

using namespace std;
bool isInteger(string s)
{
    bool ans = true;
    int len = s.length();
    if (len == 0)
        ans = false;
    else if (len == 1 && (s[0] == '+' || s[0] == '-'))
        ans = false;
    else
    {
        int i = 0;
        if (s[0] == '+' || s[0] == '-')
            i++;
        while (i < len)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                i++;
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    return ans;
}
bool isUnsignedInteger(string s)
{
    bool ans = true;
    int len = s.length();
    if (len == 0)
        ans = false;
    else
    {
        for (int i = 0; i < len; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                continue;
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    return ans;
}
bool isNumber(string s)
{
    string A, B, C;
    int len = s.length();
    bool ans = true;
    if (len == 0)
        ans = false;
    else
    {
        if (s[0] == '.')
        {              // 小数点开头
            int i = 1; // 字符串 s 中的下标
            int j = i; // 临时下标
            int tlen = 0;
            while (j < len && (s[j] != 'e' || s[j] != 'E'))
            {
                tlen++;
                j++;
            }
            if (tlen == 0)
            { // 小数点后没有数字
                ans = false;
            }
            else
            {                                      // 小数点后有数字
                B = s.substr(i, tlen);             // 将小数点后的数字切分出来
                ans = ans && isUnsignedInteger(B); // 判断小数点后的数字否是无符号整数
                i = j;
                if (i < len)
                { // 小数后有指数
                    if (s[i] == 'e' || s[i] == 'E')
                    {
                        i++;
                        j = i;
                        tlen = 0;
                        while (j < len)
                        {
                            j++;
                            tlen++;
                        }
                        if (tlen == 0)
                        { // e/E 后没有内容
                            ans = false;
                        }
                        else
                        {
                            C = s.substr(i, tlen);
                            ans = ans && isInteger(C);
                        }
                        i = j;
                    }
                    else
                    {
                        ans = false;
                    }
                }
            }
        }
        else
        {
            int i = 0;
            int j = i;
            int tlen = 0;
            while (j < len)
            {
                if (s[j] == '.')
                    break;
                if (s[j] == 'e' || s[j] == 'E')
                    break;
                tlen++;
                j++;
            }
            A = s.substr(i, tlen); // 小数点或指数之前的部分
            ans = ans && isInteger(A);
            i = j;
            if (i < len)
            { // 整数部分后还有内容
                if (s[i] == '.')
                { // 整数部分后是小数
                    tlen = 0;
                    i++;
                    j = i;
                    while (j < len && (s[j] != 'e' || s[j] != 'E'))
                    {
                        j++;
                        tlen++;
                    }
                    if (tlen != 0)
                    { // 小数点后的内容不为空
                        B = s.substr(i, tlen);
                        ans = ans && isUnsignedInteger(B);
                    }
                    i = j;
                    if (i < len)
                    { // 小数后面还有内容
                        if (s[i] == 'e' || s[i] == 'E')
                        { // 小数部分后是指数部分
                            i++;
                            tlen = len - i;
                            C = s.substr(i, tlen);
                            ans = ans && isInteger(C);
                        }
                        else
                        {
                            ans = false;
                        }
                    }
                }
                else if (s[i] == 'e' || s[i] == 'E')
                { // 整数部分后是指数
                    i++;
                    tlen = len - i;
                    C = s.substr(i, tlen);
                    ans = ans && isInteger(C);
                }
                else
                { // 整数部分后是其他内容
                    ans = false;
                }
            }
        }
    }
    return ans;
}
int main()
{
    string s;
    getline(cin, s);
    bool ans = isNumber(s);
    cout << ans << endl;
    return 0;
}