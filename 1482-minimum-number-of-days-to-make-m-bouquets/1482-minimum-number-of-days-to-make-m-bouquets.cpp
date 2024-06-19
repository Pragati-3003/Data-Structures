class Solution {
private:
    int find(vector<int>& arr,int time,int k)
    {
        int ans=0;
        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>time) 
            count=0;
            if(arr[i]<=time)
            count++;
            if(count==k)
            {
                count=0;
                ans++;
            }
        }
        return ans;
    }
public:
    int minDays(vector<int>& arr, int m, int k)
    {
        int n=arr.size();
        int ans=0;
        long long mul=(long long) m*k;
        if(mul>(long long) n) return -1;
        int maxi=0;
        for(auto& it:arr) maxi=max(maxi,it);
        int low=0,high=maxi,mid;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            int c=find(arr,mid,k);
            if(c<m) low=mid+1;
            else{
                ans=mid;
                high=mid-1;
            }
        }
    return ans;
    }
};