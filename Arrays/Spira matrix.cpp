class Solution {
public:
    vector <int> answer;
    void process(vector<vector<int>>& matrix, int ans,int m,int n){
        if(answer.size()==m*n){
            return;
        }
        else{
            for(int j=ans ; j<n-ans ; j++){
                if(answer.size()==m*n){
                    return;
                }
                answer.push_back(matrix[ans][j]); 
            }
            for(int i=ans+1 ; i<m-ans ; i++){
                if(answer.size()==m*n){
                    return;
                }
                answer.push_back(matrix[i][n-ans-1]);
            }
            for(int j=n-ans-2 ; j>=ans ; j--){
                if(answer.size()==m*n){
                    return;
                }
                answer.push_back(matrix[m-ans-1][j]);
            }
            for(int i=m-ans-2 ; i>ans ; i--){
                if(answer.size()==m*n){
                    return;
                }
                answer.push_back(matrix[i][ans]);
            }
            
        }
        ans++;
        process(matrix,ans,matrix.size(),matrix[0].size());
        

    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        process(matrix,0,matrix.size(),matrix[0].size());
        return answer;

    }
};