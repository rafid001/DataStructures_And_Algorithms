#include <vector>
#include <cmath>
using namespace std;
class Solution
{
public:
    long long maxElement(vector<int> &piles)
    {
        long long ans = 0;
        for (int i : piles)
        {
            if (i > ans)
            {
                ans = i;
            }
        }
        return ans;
    }
    long long checkHours(int speed, vector<int> &piles)
    {
        long long hrs = 0;
        for (int i : piles)
        {
            hrs += ceil((double)i / (double)speed);
        }
        return hrs;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        long long low = 1;
        long long high = maxElement(piles);
        long long ans = high;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;

            long long hours = checkHours(mid, piles);

            if (hours <= h)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};