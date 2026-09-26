class Solution {
private:
    int searchHelper(int arr[], int si, int ei, int target) {
        if (si > ei) {
            return -1;
        }
        
        int mid = si + (ei - si) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[si] <= arr[mid]) {
            if (arr[si] <= target && target <= arr[mid]) {
                return searchHelper(arr, si, mid - 1, target);
            } else {
                return searchHelper(arr, mid + 1, ei, target);
            }
        } else {
            if (arr[mid] <= target && target <= arr[ei]) {
                return searchHelper(arr, mid + 1, ei, target);
            } else {
                return searchHelper(arr, si, mid - 1, target);
            }
        }
    }

public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        return searchHelper(nums.data(), 0, nums.size() - 1, target);
    }
};
