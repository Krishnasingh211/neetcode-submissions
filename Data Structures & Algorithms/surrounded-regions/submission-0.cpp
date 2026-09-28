class Solution {
public:
    int m,n;
    vector<int>r={-1,0,1,0};
    vector<int>c={0,-1,0,1};

    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>&vis){
        vis[row][col]=1;
        for(int i=0 ; i<4;i++){
            int nr=row+r[i];
            int nc=col+c[i];
            if(nr>=0&&nr<m&&nc>=0&&nc<n&&vis[nr][nc]==0&&board[nr][nc]=='O'){
                dfs(nr,nc,board,vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'&&vis[i][0]==0){
                dfs(i,0,board,vis);
            }
            if(board[i][n-1]=='O'&&vis[i][n-1]==0){
                dfs(i,n-1,board,vis);
            }
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'&&vis[0][i]==0){
                dfs(0,i,board,vis);
            }
            if(board[m-1][i]=='O'&&vis[m-1][i]==0){
                dfs(m-1,i,board,vis);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'&&vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
        
    }
};
