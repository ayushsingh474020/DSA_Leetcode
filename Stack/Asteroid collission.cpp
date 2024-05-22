class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int i=0;
        while(i<asteroids.size()){
            if(asteroids[i]<0){
                if(s.empty() || s.top()<0){
                    s.push(asteroids[i]);
                }
                while(s.top()>0){
                    if(s.top()<-(asteroids[i])){
                        s.pop();
                        if(s.empty() || s.top()<0){
                            s.push(asteroids[i]);
                        }
                    }
                    else if(s.top()==-(asteroids[i])){
                        s.pop();
                        break;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                s.push(asteroids[i]);
            }
            i++;
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};