class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int j = numbers.size()-1;
        for(int i = 0; i < numbers.size(); i++)
        {
            if(numbers[i]+numbers[j] == target) return {i+1, j+1};
            if(numbers[i]+numbers[j] > target)
            {
                while(numbers[i]+numbers[j] > target && i < j)
                {
                    --j;
                }
                if(numbers[i]+numbers[j] == target) return {i+1, j+1};
            }
        }
    }
};
