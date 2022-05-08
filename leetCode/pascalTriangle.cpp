class Solution {
public:
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prevRow;
        
        
        for(int i=0;i< numRows;i++){
            vector<int> row(i+1);
            row[0] = 1;
            row[i] = 1;
            
            for(int j=1;j<i;j++){
            
                row[j] = prevRow[j-1]+prevRow[j];
            }
            
            prevRow = row;
            ans.push_back(row);
            
        }
        
        return ans;
       
        
    }
};