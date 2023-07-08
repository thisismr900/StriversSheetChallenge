class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0;
        int n=height.size();
        int left=0,right=n-1;
        while(left<=right)
        {
            int high=min(height[left],height[right]);
            int base=right-left;
            int vol=high * base;
            res=max(res,vol);

            if(height[left] <= height[right])
                left++;
            else
                right--;
        }
        return res;
        
        // for(int i=0;i<n-1;i++)
        // {
        //     for(int j=i;j<n;j++)
        //     {
        //         int base=j-i;
        //         int high=min(height[i],height[j]);
        //         res=max(res, base*high);
        //     }
        // }
        // return res;
    }
};