class Solution {
public:
    int checkforrow(vector<char> arr, int size){
        unordered_set<char> s;
        for(int i=0 ; i<size ; i++){
            if(s.find(arr[i])!=s.end()){
                return 1;
            }
            else if(arr[i]!='.'){
                s.insert(arr[i]);
            }
        }
        return 0;
    }
    int checkformatrix(vector<vector<char>> arr,int starti, int startj, int endi, int endj){
        unordered_set<int> s;
        for(int i=starti ; i<endi ; i++){
            for(int j=startj ; j<endj ; j++){
                if(s.find(arr[i][j])!=s.end()){
                    return 1;
                }
                else if(arr[i][j]!='.'){
                    s.insert(arr[i][j]);
                }
            }
            
        }
        return 0;
    }
    void transpose(vector<vector<char>> &arr){
        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<i ; j++){
                char a=arr[i][j];
                arr[i][j]=arr[j][i];
                arr[j][i]=a;
            }
        }

    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0 ; i<9 ; i++){
            if(checkforrow(board[i],9)){
                return 0;
            }

        }
        transpose(board);
        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0 ; i<9 ; i++){
            if(checkforrow(board[i],9)){
                return 0;
            }
        }
        if(checkformatrix(board,0,0,3,3)){
            return 0;
        }
        if(checkformatrix(board,0,3,3,6)){
            return 0;
        }
        if(checkformatrix(board,0,6,3,9)){
            return 0;
        }
        if(checkformatrix(board,3,0,6,3)){
            return 0;
        }
        if(checkformatrix(board,3,3,6,6)){
            return 0;
        }
        if(checkformatrix(board,3,6,6,9)){
            return 0;
        }
        if(checkformatrix(board,6,0,9,3)){
            return 0;
        }
        if(checkformatrix(board,6,3,9,6)){
            return 0;
        }
        if(checkformatrix(board,6,6,9,9)){
            return 0;
        }
        return 1;
    }
};