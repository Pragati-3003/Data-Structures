class Solution {
public:
    void solve(string digit,vector<string> &ans,string out,int index,string map[]){
        if(index>=digit.length()){
            ans.push_back(out);
            return;
        }
        int key=digit[index]-'0';
        string value=map[key];
        for(int i=0;i<value.length();i++){
            out.push_back(value[i]);
            solve(digit,ans,out,index+1,map);
            out.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string out;
        int index=0;
        string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,ans,out,index,map);
        return ans;
    }
};