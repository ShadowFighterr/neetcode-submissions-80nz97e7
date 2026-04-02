class Solution {
public:
    int trap(vector<int>& height) {
        int mx = 0, idx = -1;
        for(int i = 0; i < height.size(); i++)
        {
            if(height[i] != 0)
            {
                int j = i;
                int tmp = 0;
                while(j+1 < height.size() && height[i] > height[j+1])
                {
                    tmp+=(height[i]-height[j+1]);
                    // cout << tmp << ' ' << mx << ' ' << j << '\n';
                    ++j;
                }
                if(j+1 < height.size()) mx+=tmp, i = j;
                else if(j+1 == height.size()) {idx = i; break;}
            }
        }
        if(idx != -1)
        {
            for(int i = height.size()-1; i >= idx; i--)
            {
                if(height[i] != 0)
                {
                    int j = i;
                    int tmp = 0;
                    while(j-1 >= idx && height[i] > height[j-1])
                    {
                        tmp+=(height[i]-height[j-1]);
                        // cout << tmp << ' ' << mx << ' ' << j << '\n';
                        --j;
                    }
                    if(j-1 >= idx) mx+=tmp, i = j;
                }
            }
        }
        return mx;
    }
};
// height=[0,1,0,2,1,0,1,3,2,1,2,1] 6