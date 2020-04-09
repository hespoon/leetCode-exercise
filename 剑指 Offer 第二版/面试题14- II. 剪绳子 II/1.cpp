/*
这一题的 n 的取值范围是 [2,1000]，使用动态规划时，中间结果会超出 long long 的表示范围。
C++ 中没有内置的大整数类！
因此，只能使用贪心法。
计算幂的值时，使用快速幂。
由贪心法可知，尽量多的剪出长度为 3 的绳子，可以使剪完后各段绳长之积最大。
1. n≤3 时，明显结果为 n-1
2. n>3 时，按照贪心的规则，剪出尽量多的 3。
   2.1 当 n%3==0 时，结果为 3^(n/3)
   2.2 当 n%3==1 时，应当在剪最后一个长度为 4 的绳子时，剪为 2×2 的两段，而不是 3×1。所以结果为 4×3^(n/3-1)
   2.3 当 n%3==2 时，结果为 2×3^(n/3)
*/
#include <algorithm>
#include <iostream>
using namespace std;
int cuttingRope(int n)
{
    if (n <= 3)
        return n - 1;
    int index = n / 3;     // 指数
    int remainder = n % 3; // 余数
    int modBase = 1e9 + 7; // 取模的基数
    long long ans;
    if (remainder == 0)
    {
        ans = quickPower(index, 3, modBase);
    }
    else if (remainder == 1)
    {
        ans = 4 * (quickPower(index - 1, 3, modBase) % modBase) % modBase;
    }
    else
    {
        ans = 2 * (quickPower(index, 3, modBase) % modBase) % modBase;
    }
    return (int)ans;
}
long long quickPower(int index, int radix, int modBase) // 基于递归的快速幂
{
    radix %= modBase; // 如果底数比取模的基数大，则应先让底数取模
    if (index == 0)
        return 1;
    if (index == 1)
        return radix % modBase;
    long long temp;
    if (index & 1 == 1)
    {
        temp = quickPower((index - 1) / 2, radix, modBase);
        return radix * (temp % modBase) * (temp % modBase) % modBase;
    }
    else
    {
        temp = quickPower(index / 2, radix, modBase);
        return (temp % modBase) * (temp % modBase) % modBase;
    }
}
/*
基于迭代的快速幂
对 a^b 来说，b 写成二进制，则 b 就可以写为若干次二次幂之和。
例如，13 写为二进制是 1101，13=8+4+1。所以，a^13 = a^8 × a^4 × a^1
通过上述例子，我们可以得出计算 a^b 的思路：
令 i 从右向左枚举 b 的二进制表示的每一位，i 的取值为 [0,k]，如果当前位为 1，则积累 a^(2i)。
具体实现如下：
1. 初始令 ans=1，用来存放最终结果
2. 判断 b 的二进制末尾是否为 1。如果是，则令 ans 乘上 a 的值。
3. 令 a 平方，并将 b 右移一位
4. 只要 b 大于零，就返回步骤 2。否则，函数返回。
*/
long long quickPower(int index, long long radix, int modBase) // 基于迭代的快速幂
{
    long long ans = 1; // 存放结果
    while (index)      // 指数不为 0，则一直循环
    {
        if (index & 1) // 如果指数二进制表示的最后一位是 1
        {
            ans = ans * radix % modBase; // 结果乘上底数
        }
        radix = radix * radix % modBase; // 底数每次都平方
        index >>= 1;                     // 指数每次都除以 2
    }
    return ans;
}