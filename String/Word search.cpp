class Solution {
public:
    bool solverec(vector<vector<char>> &board, int x, int y, string word){
        // char extra;
        if(word.size()==0){
            return true;
        }
        if(x>=board.size() || y>=board[0].size()){
            return false;
        }
        if(board[x][y]==word[0]){
            board[x][y]='.';
            bool ans1=solverec(board,x+1,y,word.substr(1));
            bool ans2=solverec(board,x-1,y,word.substr(1));
            bool ans3=solverec(board,x,y-1,word.substr(1));
            bool ans4=solverec(board,x,y+1,word.substr(1));
            board[x][y]=word[0];
            return (ans1 || ans2 || ans3 || ans4);
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int,int>> extra;
        unordered_map<char,int> m;
        vector<vector<char>> temp=board;
        for(int i=0 ; i<board.size() ; i++){
            for(int j=0 ; j<board[i].size() ; j++){
                if(board[i][j]==word[0]){
                    extra.push_back({i,j});
                }
                m[board[i][j]]++;
            }
        }
        for(int i=0 ; i<word.size() ; i++){
            if(m[word[i]]>0){
                m[word[i]]--;
            }
            else{
                return false;
            }
        }
        for(int i=0 ; i<extra.size() ; i++){
            if(solverec(board,extra[i].first,extra[i].second,word)){
                return true;
            }
            board=temp;
        }
        return false;
    }
};