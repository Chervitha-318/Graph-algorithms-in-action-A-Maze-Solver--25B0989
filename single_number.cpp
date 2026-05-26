class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int n=nums.size();
    int single=0;
    sort(nums.begin() , nums.end());
    if(n==1){single= nums[0];}
    else{
    for(int i=0;i<n;i+=2){
        if(nums[i]!=nums[i+1]){
            single= nums[i];
            break; 
        }
    }
    }
return single;
    }
};
