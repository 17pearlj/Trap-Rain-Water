class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) { return 0; }
        vector<int> lMaxes;

        int left = 0;
        while (left < height.size() -1 && (height[left] == 0 || height[left] < height[left + 1])) { left++; }
        int right = height.size() - 1;
        while (right > 0  && (height[right] == 0 || height[right] < height[right - 1])) { 
            right--; 
        }

        int lMax = left;
        int rMax = right;
        if (height[lMax] < height[rMax]) { left++; } else {right--; }
        int rIndex = 0;
        while (left < right) {
            if (left != lMax) {
                if (height[left] >= height[lMax] && left < height.size() -1 && height[left] > height[left + 1]) {
                    lMaxes.insert(lMaxes.begin() + rIndex, lMax);
                    lMax = left;
                    rIndex++;
                    if (height[lMax] < height[rMax]) { left++; } else {right--; }
                } else {
                    left++;
                }
            } else {
                if (height[right] >= height[rMax] && right > 0 && height[right] > height[right - 1]) {
                   lMaxes.insert(lMaxes.begin() + rIndex, rMax);
                    rMax = right;
                    if (height[lMax] < height[rMax]) { left++; } else {right--; }
                } else {
                    right--;
                }
            }
        }

        lMaxes.insert(lMaxes.begin() + rIndex, rMax);
        lMaxes.insert(lMaxes.begin() + rIndex, lMax);

        if (lMaxes.size() < 2) { return 0; }
        int water = 0;
        int minBorder;
        for (int i = 0; i < lMaxes.size() - 1; i++) {
            minBorder = min(height[lMaxes[i]], height[lMaxes[i + 1]]);
            for (int j = lMaxes[i] + 1; j < lMaxes[i + 1]; j++) {
                if (minBorder > height[j]) {
                    water += minBorder - height[j];
                }
                
            }
        }
        return water;
    }
};
