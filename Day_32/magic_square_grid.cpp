class Solution {
public:

bool isMagical(vector<vector<int>>& grid,int r,int c)
{
    unordered_set<int> st;
    for(int i=0;i<3;i++)
    {
        
        for(int j=0;j<3;j++)
        {
            int val=grid[r+i][c+j];
            if(val<1||val>9||st.count(val))
            {
                return false;
            }
            else{
                st.insert(val);
            }
        }
    }
    int Rsum= grid[r][c]+grid[r][c+1]+grid[r][c+2];
    for(int i=0;i<3;i++)
    {
      if(grid[r+i][c]+grid[r+i][c+1]+grid[r+i][c+2]!=Rsum)
      {
        return false;
      }
        if(grid[r][c+i]+grid[r+1][c+i]+grid[r+2][c+i]!=Rsum)
      {
        return false;
      }
      
    }

if(grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2]!=Rsum)
{
    return false;
}
if(grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c]!=Rsum)
{
    return false;
}
return true;
}

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid.size();
        int count=0;
        for(int i=0;i<=row-3;i++)
        {
            for(int j=0;j<=col-3;j++)
            {
                 if(isMagical(grid,i,j))
            {
                 count++;
             }
            }
           
        }
 return count;
    }
       
};