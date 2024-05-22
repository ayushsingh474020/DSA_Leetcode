class Solution {
public:
     long long int minEatingSpeed(vector<int>& piles, long long int h) {
        
       long long int low = 1;
        long long int high = *max_element(piles.begin(),piles.end());
        
        long long int ans = 0;
        while(low<=high)
        {
            long long int mid = (low+high)/2;
            long long int time = timefnc(mid,piles);
            if(time<=h)
            {  
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
            
        }
        
        return ans;
        
    }
    
    long long int timefnc(long long int mid,vector<int>&piles)
    {
          long long int sum = 0;
         
        for(long long int i=0;i<piles.size();i++)
        {
            sum+=(piles[i]/mid)+((piles[i]%mid)!=0);
        }
        return sum;
    }
};