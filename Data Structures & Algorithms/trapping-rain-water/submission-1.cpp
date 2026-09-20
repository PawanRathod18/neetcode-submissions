class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        int water = 0;

        while (left < right) {
            if (leftMax < rightMax) {
                left++;

                if (height[left] > leftMax) {
                    leftMax = height[left];
                }
                else {
                    water += leftMax - height[left];
                }
            }
            else {
                right--;

                if (height[right] > rightMax) {
                    rightMax = height[right];
                }
                else {
                    water += rightMax - height[right];
                }
            }
        }

        return water;
    }
};