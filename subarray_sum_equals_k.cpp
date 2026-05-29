class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     unordered_map<int,int> mp;
        mp[0] = 1;
        int currentSum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            if(mp.count(currentSum - k)) {
                count += mp[currentSum - k];
            }
            mp[currentSum]++;
        }
        return count;  
    }
};
