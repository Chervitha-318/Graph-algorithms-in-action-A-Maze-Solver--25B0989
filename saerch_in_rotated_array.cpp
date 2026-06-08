class Solution {
public:
    int search(vector<int>& nums, int target) {
    int n=nums.size();
    int left=0;
    int right=n-1;
    while(left<=right){
        int index=(right+left)/2;
        if(nums[index]==target){
            return index;
        }
        else if (nums[left]<=nums[index]){
            if(nums[left] <= target && target < nums[index]){
                right=index-1;
            }
            else 
                left=index+1;
            
        }
        else if(nums[left]>nums[index]){
            if(nums[index] < target && target <= nums[right])
                left=index+1;
            else
                right=index-1;
        }
    }   
    return -1;
    
    }
};
