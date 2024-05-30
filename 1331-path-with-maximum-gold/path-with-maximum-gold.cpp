class Solution {
public:
    
    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
    
    bool surround(int i,int j,vector<vector<int>>& grid){
        
        int n = grid.size();
        int m = grid[0].size();

        for(auto &dir:directions){
            int neighbour_i = i + dir[0];
            int neighbour_j = j + dir[1];
            
        if(neighbour_i < 0 || neighbour_j >= m || neighbour_j < 0 || neighbour_i >= n)
           return false;

          if(grid[neighbour_i][neighbour_j] == 0)
           return false;      

        }

        return true;

    }


    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& path_visi,vector<vector<int>>& visi,int& profit,int& maxi_profit){
        
        int n = grid.size();
        int m = grid[0].size();

        path_visi[i][j] = 1;
        profit += grid[i][j];

        maxi_profit = max(profit,maxi_profit);

        for(auto &dir:directions){
            int neighbour_i = i + dir[0];
            int neighbour_j = j + dir[1];

            if( neighbour_i < 0 ||  neighbour_j < 0 || neighbour_i >= n || neighbour_j >= m)
             continue;

            if(grid[neighbour_i][neighbour_j] == 0 || path_visi[neighbour_i][neighbour_j] == 1)
             continue; 
    
            
            dfs(neighbour_i,neighbour_j,grid,path_visi,visi,profit,maxi_profit); 
  
        }

        path_visi[i][j] = 0;
        profit -= grid[i][j];

    }

    int getMaximumGold(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        int maxi = 0;

        vector<vector<int>> visi(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] != 0){   
                 vector<vector<int>> path_visi(n,vector<int> (m,0));

                  if(surround(i,j,grid))
                   continue;    

                 int profit = 0;
                 int maxi_profit = 0;

                 dfs(i,j,grid,path_visi,visi,profit,maxi_profit);

                 visi[i][j] = 1;

                 maxi = max(maxi_profit,maxi);

                } 
            }
        }

        return maxi;
        

    }
};