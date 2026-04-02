class Solution {
public:
    bool func(vector<int>& piles, int x, int t)
    {
        int i = 0;
        while(t >= 0)
        {
            int k = (piles[i]/x) + (piles[i]%x>0);
            if(t-k >= 0) t-=k;
            else return false;
            if(i+1 < piles.size()) ++i;
            else break;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // sort(piles.begin(), piles.end());
        int l = 1, r = (int)1e9, m;
        while(l <= r)
        {
            m = (l+r)/2; 
            if(func(piles, m, h)) r = m-1;
            else l = m+1;
            cout << l << ' ' << r << '\n';
        }
        return l;
    }
};
