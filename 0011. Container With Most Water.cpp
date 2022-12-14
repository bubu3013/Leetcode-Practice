class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int cur = 0;
        int max = -1;
        
        while (left < right){
//           find the smaller one and multiply with the interval to get the total water
            if (height[left] < height[right]){
                cur = height[left] * (right - left);
//               since the left is smaller, iterate left with a plus can find a larger container
                left++;
            }else if (height[left] >= height[right]){
                cur = height[right] * (right - left);
//               since the right is smaller, iterate right with a minus can find a larger container
                right--;
            }
//           update the max container 
            if (cur > max){
                max = cur;
            }
        }
        return max;
    }
};

// Runtime: 117 ms, faster than 80.01% of C++ online submissions for Container With Most Water.
// Memory Usage: 58.9 MB, less than 97.90% of C++ online submissions for Container With Most Water.

class Solution {
public:
    int maxArea(vector<int>& height) {
        return helper(height, height.size() - 1);
    }
private:
    int helper(vector<int>& height, int n){
        int left = 0;
        int right = n;
        int water = 0;
        while (left <= right){
            int tmp = min(height[left], height[right]) * (right - left);
            water = max(water, tmp);
            if (height[left] >= height[right]){
                right--;
            }else{
                left++;
            }
        }
        return water;
    }
};

// Runtime 102 ms Beats 90.61%
// Memory 58.9 MB Beats 80.88%
