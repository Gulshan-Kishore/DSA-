class Solution {
public:

    // Helper Function :- 
    int binSearch(vector<int>& arr, int target, int start, int end) {
        if (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == target) 
                return mid;
            
            else if (arr[mid] <= target) 
                return binSearch(arr, target, mid+1, end);
            
            else
                return binSearch(arr, target, start, mid-1);

        }
        return -1;
    }

    int search(vector<int>& arr, int target) {
        return binSearch(arr, target, 0, arr.size()-1);
    }
};