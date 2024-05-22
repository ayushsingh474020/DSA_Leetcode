class Solution {
public:
    int x=10;
    int process(vector<vector<int>> board, int i, int j){
        int n=board.size();
        int m=board[0].size();
        int count=0;
        if(i-1>=0 && j-1>=0){
            if(board[i-1][j-1]%x==1){
                count++;
            }
        }
        if(i-1>=0){
            if(board[i-1][j]%x==1){
                count++;
            }
        }
        if(i-1>=0 && j+1<m){
            if(board[i-1][j+1]%x==1){
                count++;
            }
        }
        if(j+1<m){
            if(board[i][j+1]%x==1){
                count++;
            }
        }
        if(i+1<n){
            if(board[i+1][j]%x==1){
                count++;
            }
        }
        if(i+1<n && j-1>=0){
            if(board[i+1][j-1]%x==1){
                count++;
            }
        }
        if(j-1>=0){
            if(board[i][j-1]%x==1){
                count++;
            }
        }
        if(i+1<n && j+1<m){
            if(board[i+1][j+1]%x==1){
                count++;
            }
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board[0].size();
        int n=board.size();
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(board[i][j]%x==0){
                    int a=process(board,i,j);
                    if(a==3){
                        board[i][j]+=x;
                    }
                }
                else if(board[i][j]%x==1){
                    int a=process(board,i,j);
                    // cout<<a<<endl;
                    if(a<2){
                        board[i][j]+=x;
                    }
                    else if(a>3){
                        board[i][j]+=x;
                    }
                }
            }
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(board[i][j]>=10){
                    int a=board[i][j]%10;
                    if(a==0){
                        board[i][j]=1;
                    }
                    else{
                        board[i][j]=0;
                    }
                }
            }
        }
            
    }
};