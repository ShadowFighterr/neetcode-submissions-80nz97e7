class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size()-1, m;
        while(l <= r)
        {
            m = (l+r)/2;
            if(matrix[m][0] == target) return true;
            ((matrix[m][0] > target) ? r = m-1 : l = m+1);
        }
        if(l >= matrix.size()) --l;
        if(r < 0) ++r;
        for(int i = min(l, r); i <= max(l, r); i++)
        {
            int j = 0, k = matrix[i].size(), mid;
            while(j <= k)
            {
                mid = (j+k)/2;
                if(matrix[i][mid] == target) return true;
                ((matrix[i][mid] > target) ? k = mid-1 : j = mid+1);
            }
        }
        return false;
    }
};
