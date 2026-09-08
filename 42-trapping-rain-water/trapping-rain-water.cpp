class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if (n <= 2)
            return 0;

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        // Left maximum
        leftMax[0] = height[0];

        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // Right maximum
        rightMax[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        // Calculate trapped water
        int waterTrapped = 0;

        for (int i = 0; i < n; i++) {
            int currWater = min(leftMax[i], rightMax[i]) - height[i];

            if (currWater > 0) {
                waterTrapped += currWater;
            }
        }

        return waterTrapped;
    }
};