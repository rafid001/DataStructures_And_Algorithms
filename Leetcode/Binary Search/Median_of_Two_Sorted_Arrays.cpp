class Solution
{
public:
    // optimal way BINARY SEARCH
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int low = 0;
        int high = n1;
        int left = (n1 + n2 + 1) / 2;
        int n = n1 + n2;
        while (low <= high)
        {
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];
            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];

            if (l1 <= r2 && l2 <= r1)
            {
                if (n % 2 == 1)
                    return max(l1, l2);
                return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            }

            else if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return -1;
    }

    // better way, no extra space
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        int total = (n + m);
        int ind1 = total / 2;
        int ind2 = total / 2 - 1;
        int el1 = -1, el2 = -1;
        int cnt = 0;
        bool isEven = total % 2 == 0;

        while (i < n && j < m)
        {
            if (nums1[i] < nums2[j])
            {
                if (cnt == ind1)
                    el1 = nums1[i];
                if (cnt == ind2)
                    el2 = nums1[i];
                cnt++;
                i++;
            }
            else
            {
                if (cnt == ind1)
                    el1 = nums2[j];
                if (cnt == ind2)
                    el2 = nums2[j];
                cnt++;
                j++;
            }
        }
        while (i < n)
        {
            if (cnt == ind1)
                el1 = nums1[i];
            if (cnt == ind2)
                el2 = nums1[i];
            cnt++;
            i++;
        }
        while (j < m)
        {
            if (cnt == ind1)
                el1 = nums2[j];
            if (cnt == ind2)
                el2 = nums2[j];
            cnt++;
            j++;
        }
        if (isEven)
        {
            return (el1 + el2) / 2.0;
        }
        else
            return el1;
    }

    // brute way, with extra space
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> nums3;
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;

        while (i < n && j < m)
        {
            if (nums1[i] < nums2[j])
            {
                nums3.push_back(nums1[i++]);
            }
            else
            {
                nums3.push_back(nums2[j++]);
            }
        }
        while (i < n)
        {
            nums3.push_back(nums1[i++]);
        }
        while (j < m)
        {
            nums3.push_back(nums2[j++]);
        }

        int total = nums3.size();

        if (total % 2 == 0)
        {
            return (double)((double)(nums3[total / 2]) + (double)(nums3[total / 2 - 1])) / 2.0;
        }
        else
        {
            for (int i : nums3)
            {
                cout << i << " ";
            }
            return nums3[(total / 2)];
        }
    }
};