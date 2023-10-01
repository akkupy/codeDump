class Solution {
    public List<List<String>> solveNQueens(int n) { //n= num of queens
        List<List<String>> res = new ArrayList<>();
        boolean[][] board = new boolean[n][n];
        nQueen(board, 0, res);
        return res;
    }

    //main function to check
    public void nQueen(boolean[][] board, int row, List<List<String>> res){
        if(row== board.length){
            addList(board, res);
            return;
        }
        //checking every possible ans
        for(int col=0; col<board.length; col++){
            if(isSafe(board, row, col)){
                board[row][col] = true;
                nQueen(board, row+1, res);
                //bactracking
                board[row][col] = false;
            }
        }
        return;
    }

    //function to check if placing queen is safe
    public boolean isSafe(boolean[][] board, int row, int col){
        //vertical check
        for(int i= 0; i<row; i++){
            if(board[i][col]){
                return false;
            }
        }
        //diagonal check
        int maxLeft = Math.min(row, col);
        for(int i=1; i<=maxLeft; i++){
            if(board[row-i][col-i]){
                return false;
            }
        }
        //diagonal check
        int maxRight = Math.min(row, board.length-col-1);
        for(int i=1; i<=maxRight; i++){
            if(board[row-i][col+i]){
                return false;
            }
        }
        return true;
    }

    //function to add the ans into the list
    public void addList(boolean[][] board, List<List<String>> res){
        List<String> ans = new ArrayList<>();
        for(boolean[] row : board){
            String rowElement = "";
            for(boolean element : row){
                if(element){
                    rowElement += "Q";
                }else{
                    rowElement += ".";
                }
            }
            ans.add(rowElement);
        }
        res.add(ans);
    }
}
