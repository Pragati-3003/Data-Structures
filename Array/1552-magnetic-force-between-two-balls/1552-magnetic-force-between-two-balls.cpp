class Solution {
public:

  int isvalid(int mid ,vector<int>position){
    int total = 1;
    int curDist= position[0];
     for (int i = 1; i < position.size(); i++) {
                if (position[i] - curDist >= mid) {
                    total++;
                    curDist = position[i];
                }
            }
            return total;
  }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int l =0;
        int r = 1e9;

        int currMax = 0;
        while(l<=r){
          int   mid = (l+r)/2;
          if(isvalid(mid,position)>=m){
            l =  mid+1;
            currMax = max(currMax,mid);

          }
          else {
            r =  mid-1;
          }
        }
        return currMax;
    }
};