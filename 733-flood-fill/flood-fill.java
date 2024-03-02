class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        if(image[sr][sc]==color) {
            return image;
        }
        int[][] ans = image;
        int iniColor = image[sr][sc];

        int delRow[] = { -1, 1, 0, 0 };
        int delCol[] = { 0, 0, 1, -1 };

        DFS(image, sr, sc, color, iniColor, delRow, delCol);

        for (int i = 0; i < image.length; i++) {
            for (int j = 0; j < image[0].length; j++) {
                System.out.print(image[i][j] + " ");
            }
            System.out.println();
        }
        for (int i = 0; i < image.length; i++) {
            for (int j = 0; j < image[0].length; j++) {
                System.out.print(ans[i][j] + " ");
            }
            System.out.println();
        }
        return ans;
    }

    public void DFS(int[][] image, int sr, int sc, int color, int iniColor,
        int delRow[], int delCol[]) {
        image[sr][sc] = color;
        int n = image.length;
        int m = image[0].length;

        for (int i = 0; i < 4; i++) {
            int nrow = sr + delRow[i];
            int ncol = sc + delCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor) {
                DFS(image, nrow, ncol, color, iniColor, delRow, delCol);
            }
        }
    }
}