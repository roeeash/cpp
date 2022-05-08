class Solution {
public:
    
     vector<int> generate(int numRows) {
        vector<int> prevRow;
        
        
        for(int i=0;i< numRows;i++){
            vector<int> row(i+1);
            row[0] = 1;
            row[i] = 1;
            
            for(int j=1;j<i;j++){
            
                row[j] = prevRow[j-1]+prevRow[j];
            }
            
            prevRow = row;
           
            
        }
        
        return prevRow;
       
        
    }
    
    vector<int> getRow(int rowIndex) {
          
         vector<int> ans =  generate(rowIndex+1);
         return ans;
    }
};