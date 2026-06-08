class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int index = left + (right - left)/2;

            if(nums[index] == target) {
                first = index;
                right = index - 1;
            }
            else if(nums[index] < target)
                left = index + 1;
            else
                right = index - 1;
        }
        left = 0;
        right = nums.size() - 1;
        while(left <= right) {

            int index = left + (right - left)/2;

            if(nums[index] == target) {
                last = index;
                left = index + 1;
            }
            else if(nums[index] < target)
                left = index + 1;
            else
                right = index - 1;
        }

        return {first, last};
    }
};
