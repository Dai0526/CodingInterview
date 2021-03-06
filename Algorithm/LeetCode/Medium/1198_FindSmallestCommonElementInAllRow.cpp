#include <vector>

using namespace std;

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        
        int row = mat.size();
        int col = mat[0].size();
        
        for(int j = 0; j < col; ++j){
            bool found = true;
            int target = mat[0][j];
            
            for(int i = 1; i < row; ++i){
                found = Exist(mat[i], target);
                if(found == false){
                    break;
                }
            }
            
            if(found){
                return target;
            }
            
        }
        return -1;
        
    }
    
    // can use binary search since it is a sorted list
    bool Exist(const vector<int>& vec, int tar){
        
        for(int n : vec){
            if(n == tar){
                return true;
            }
        }
        
        return false;
    }
};

class Solution2 {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int row = mat.size();
        if(row < 1){
            return -1;
        }
        
        int col = mat[0].size();
        if(col < 1){
            return -1;
        }
        
        unordered_map<int, int> count;
        
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                int val = mat[i][j];
                ++count[val];
                
                if(count[val] == row){
                    return val;
                }
                
            }
        }

        return -1;
    }
};