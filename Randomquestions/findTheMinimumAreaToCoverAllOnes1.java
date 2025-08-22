class Solution {
    public int minimumArea(int[][] grid) {
        int minRow = grid.length;
        int maxRow = -1;

        int minCol = grid[0].length;
        int maxCol = -1;

        for(int i=0; i<grid.length; i++) {
            for(int j=0; j<grid[0].length; j++) {
                if(grid[i][j] == 1) {
                    maxRow = Math.max(maxRow, i);
                    minRow = Math.min(minRow, i);

                    maxCol = Math.max(maxCol, j);
                    minCol = Math.min(minCol, j);
                }
            }
        } 

        return (maxRow-minRow+1) * (maxCol-minCol+1);
        
    }
}


