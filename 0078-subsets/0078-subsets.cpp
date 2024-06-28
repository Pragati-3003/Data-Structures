class Solution {
public:
        vector<vector<int>>  ans;
    void solve(vector<int> nums,vector<int>op){
        if(nums.size()<=0)
        {
            ans.push_back(op);
            return;
        }
        
        //not include
        vector<int> op1= op;
        vector<int>op2=op;
        op2.push_back(nums[0]);
        nums.erase(nums.begin()+0);
        solve(nums,op1);
        solve(nums,op2);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<int>op;
        solve(nums,op);
        return ans;
    }
};