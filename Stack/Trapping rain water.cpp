class Solution {
public:
    int minimum(int a, int b){
        if(a<b){
            return a;
        }
        else{
            return b;
        }
    }
    int trap(vector<int>& height) {
        vector <int> lmax;
        lmax.push_back(0);
        int max=height[0];
        for(int i=1 ; i<height.size() ; i++){
            lmax.push_back(max);
            if(max<height[i]){
                max=height[i];
            }
        }
        vector <int> rmax;
        rmax.push_back(0);
        int max2=height[height.size()-1];
        for(int i=height.size()-2 ; i>=0 ; i--){
            rmax.push_back(max2);
            if(max2<height[i]){
                max2=height[i];
            }
        }
        // for(int i=0 ; i<rmax.size() ; i++){
        //     cout<<rmax[i]<<" ";
        // }
        // cout<<rmax;
        reverse(rmax.begin(),rmax.end());
        int ans=0;
        for(int i=1 ; i<height.size()-1 ; i++){
            int min=minimum(lmax[i],rmax[i]);
            if(min>height[i]){
                ans+=min-height[i];
            }
        }
        return ans;

    }
};