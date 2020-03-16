/*
使用异或实现原地交换
*/
#include <vector>
using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // 按主对角线交换
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                myswap(matrix[i][j], matrix[j][i]);
            }
        }
        // 按行反转
        for (int i = 0; i < n; i++)
        {
            int l = 0, r = n - 1;
            while (l < r)
            {
                myswap(matrix[i][l], matrix[i][r]);
                l++;
                r--;
            }
        }
    }
    void myswap(int &a, int &b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};