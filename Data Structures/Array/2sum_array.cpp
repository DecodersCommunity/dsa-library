class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
        int a=0, b=0;
        int s=nums.size();
        for(int i=0; i<s; i++){
            for(int j=i+1; j<s; j++){
                if(nums[i]+nums[j]==target){
                    a=i;
                    b=j;
                }
            }
        }
        return {a, b};
    }
};