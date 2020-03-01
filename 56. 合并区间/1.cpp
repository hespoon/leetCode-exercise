#include <algorithm>
#include <vector>
using namespace std;

bool cmp(vector<int> const &a, vector<int> const &b)
{
    return a[0] < b[0];
}

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return intervals;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> tmp;
        tmp.push_back(intervals[0][0]);
        tmp.push_back(intervals[0][1]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= tmp[1])
            {
                tmp[1] = tmp[1] > intervals[i][1] ? tmp[1] : intervals[i][1];
            }
            else
            {
                ans.push_back(tmp);
                tmp.clear();
                tmp.push_back(intervals[i][0]);
                tmp.push_back(intervals[i][1]);
            }
        }
        ans.push_back(tmp);
        return ans;
    }
};