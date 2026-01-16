import java.util.Arrays;

class Solution {
    public int countElements(int[] nums, int k) {
        int size = nums.length;
        if (k >= size) return 0;
        if (k <= 0) return size;

        Arrays.sort(nums);

        int limit = nums[size - k];

        int low = lower_bound(nums, limit);

        return low;
    }

    private static int lower_bound(int[] array, int key) {
        int low = 0, high = array.length;
        while (low < high) {
            int mid = low + (high - low) / 2;

            if(array[mid] >= key)
                high = mid;

            else 
                low = mid + 1;
        }

        return low;
    }
}