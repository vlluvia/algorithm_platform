class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }else if(nums.size() ==1){
            return nums[0];
        }
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(i-1 >= 0 && i+1 <nums.size()){
                if(nums[i] !=nums[i-1] && nums[i] != nums[i+1]){
                    return nums[i];
                }
            }else if(i == 0 && i < nums.size()){
                if(nums[i] != nums[i+1]){
                    return nums[i];
                }
            }else if(i == nums.size()-1){
                return nums[i];
            }
        }
        return 0;
    }
};