class Solution {
    public int trap(int[] height) {

        int sum = 0;
        int i = 0;
        int k = height.length - 1;
        
        while (i + 1 < height.length && height[i + 1] > height[i]) {
            i++;
        }
        while (k - 1 >= 0 && height[k - 1] > height[k]) {
            k--;
        }
        int left = height[i];
        int right = height[k];
        while (i != k) {
            if (height[i] <= height[k]) {
                i++;
                if (left > height[i]) {
                    sum += left - height[i];
                } else {
                    left = height[i];
                }
            } else {
                k--;
                if (right > height[k]) {
                    sum += right - height[k];
                } else {
                    right = height[k];
                }
            }
        }
        
        
        return sum;
    }
}
