class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<vector<int>> ans;
        for(auto it : mp){
            ans.push_back({it.first,it.second});
        }
        sort(ans.begin(), ans.end(),[](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        vector<int> result;
        int n = ans.size();
        for(int i=n-1;i>=n-k;i--){
            result.push_back(ans[i][0]);
        }
        return result;
    }
};
