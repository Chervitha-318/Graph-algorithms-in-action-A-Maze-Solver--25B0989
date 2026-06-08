class Solution {
public:
    set<vector<int>> s;
    void combinationSum(vector<int>& candidates,int index,vector<int>& combi,vector<vector<int>>&  ans, int target){
        if(index==candidates.size() || target<0){
            return;
        }
        if(target==0){
            if(s.find(combi)==s.end()){
            ans.push_back(combi);
            s.insert(combi);
            }
            return;
        }

        combi.push_back(candidates[index]);
        combinationSum(candidates,index+1,combi,ans,target-candidates[index]);
        combinationSum(candidates,index,combi,ans,target-candidates[index]);
        combi.pop_back();
        combinationSum(candidates,index+1,combi,ans,target);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combi;
        vector<vector<int>> ans;

        combinationSum(candidates,0,combi,ans,target);

        return ans; 
    }
};
