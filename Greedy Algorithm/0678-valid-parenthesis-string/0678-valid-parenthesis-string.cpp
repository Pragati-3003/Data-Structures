
class Solution {
public:
    bool checkValidString(string s) {
        int cnt=0, spent=0, rem=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cnt++;  
            }else if(s[i]==')'){
                if(cnt) cnt--; 
                else if(spent){
                    spent--; rem++; 
                }else if(rem){
                    rem--;
                }else return false;  
            }else{
                if(cnt){
                    cnt--; spent++;  
                }else rem++;   
            }
        }
        return cnt==0;
    }
};