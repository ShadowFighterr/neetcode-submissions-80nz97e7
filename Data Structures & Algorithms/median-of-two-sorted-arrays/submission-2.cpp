class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //idea: divide into 2 partitions then r index of the 1st partition 8 l of 2nd over 2
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int total = A.size() + B.size();
        int half = (total+1) / 2;
        if(B.size() < A.size()) swap(A, B);
        int l = 0, r = A.size();
        
        while(l <= r)
        {
            int i = (l+r)/2;
            int j = half-i;
            
            int al = i > 0 ? A[i-1] : INT_MIN;
            int ar = i < A.size() ? A[i] : INT_MAX;
            int bl = j > 0 ? B[j-1] : INT_MIN;
            int br = j < B.size() ? B[j] : INT_MAX;

            if(al <= br && bl <= ar)
            {
                if(total % 2 != 0) return max(al, bl);
                return (max(al, bl) + min(ar, br)) / 2.0; 
            }
            else if(al > br) r = i-1;
            else l = i+1;
        }

        return -1;
        
    }
};
