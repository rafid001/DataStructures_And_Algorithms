/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peakidx(MountainArray &mountainArr) {
        int n = mountainArr.length();

        int l = 0;
        int r = n-1;

        while(l < r) {
            int mid = (l+r) / 2;

            if(mountainArr.get(mid) < mountainArr.get(mid+1))
                l = mid+1;
            else
                r = mid;
        }

        return l;
    }

    int binarySearch(int l, int r, int target, MountainArray &mountainArr) {

        int mid;

        while(l <= r) {
            mid = l + (r-l) / 2;

            if(mountainArr.get(mid) == target)
                return mid;
            else if(mountainArr.get(mid) > target)
                r = mid - 1;
            else
                l = mid+1;
        }
        return -1;
    }

    int revBinarySearch(int l, int r, int target, MountainArray &mountainArr) {

        int mid;

        while(l <= r) {
            mid = l + (r-l) / 2;

            if(mountainArr.get(mid) == target)
                return mid;
            else if(mountainArr.get(mid) > target)
                l = mid+1;
            else
               r = mid-1;
        }
        return -1;
    }


    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int idx = peakidx(mountainArr);

        int result_idx = binarySearch(0, idx, target, mountainArr);

        if(result_idx != -1) {
            return result_idx;
        }

        result_idx = revBinarySearch(idx, n-1, target, mountainArr);

        return result_idx;
    }
};