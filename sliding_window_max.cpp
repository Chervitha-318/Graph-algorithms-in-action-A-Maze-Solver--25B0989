class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> answer;
        for (int i = 0; i <= nums.size() - k; i++) {
            int maximum = nums[i];
            for (int j = i; j < i + k; j++) {
                if (nums[j] > maximum) {
                    maximum = nums[j];
                }
            }
            answer.push_back(maximum);
        }
        return answer;
    }
};
