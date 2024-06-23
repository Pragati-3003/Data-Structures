class Solution {
public:
    static bool comp(const vector<int>& v1,const vector<int>& v2){
        return v1[1]>v2[1];
    }
    int maximumUnits(vector<vector<int>>& b, int t) {
        sort(b.begin(),b.end(),comp);
        int bx=0;
        int ans=0;
        for(int i=0;i<b.size();i++){
            bx+=b[i][0];
            if(bx>t){
                bx-=b[i][0];
                ans+=(t-bx)*b[i][1];
                break;
            }
            else{
                ans+=b[i][0]*b[i][1];
            }
        }
        return ans;
    }
};