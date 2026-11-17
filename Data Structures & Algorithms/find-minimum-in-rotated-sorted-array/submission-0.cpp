class Solution {
public:
    int findMin(vector<int> &arr) {
        int n = arr.size();

        int low = 0;
        int high = n - 1;
        int ans = arr[0];

        while (low <= high) {
            int mid = (low + high) / 2;
            
            if (arr[mid] <= arr[high]) {
                ans = min(ans, arr[mid]);
                high = mid - 1;
            } else if (arr[low] <= arr[mid]) {
                low = mid + 1;
            }
        } 
        return ans;
    }
};
// 3,4,5,6,1,2
//       3   5
// mid = 4
