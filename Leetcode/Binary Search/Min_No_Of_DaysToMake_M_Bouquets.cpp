class Solution
{
public:
    int minVal(vector<int> &bloomDay)
    {
        int ans = INT_MAX;
        for (int i : bloomDay)
        {
            if (ans > i)
            {
                ans = i;
            }
        }
        return ans;
    }
    int maxVal(vector<int> &bloomDay)
    {
        int ans = INT_MIN;
        for (int i : bloomDay)
        {
            if (ans < i)
            {
                ans = i;
            }
        }
        return ans;
    }
    bool isPossible(vector<int> &arr, int bouquets, int flowers, int x)
    {
        long long cnt = 0;
        long long noOfB = 0;
        for (int i : arr)
        {
            if (i <= x)
            {
                cnt++;
            }
            else
            {
                noOfB += (cnt / flowers);
                cnt = 0;
            }
        }
        noOfB += (cnt / flowers);
        return noOfB >= bouquets;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        long long temp_m = m;
        long long temp_k = k;
        if (temp_m * temp_k > bloomDay.size())
            return -1;
        long long low = minVal(bloomDay);
        long long high = maxVal(bloomDay);
        long long ans = -1;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;

            if (isPossible(bloomDay, m, k, mid))
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