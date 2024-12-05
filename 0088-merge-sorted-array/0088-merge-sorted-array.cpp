class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        vector<int> arr;
        while(i<m && j<n) {
            if(nums1[i]<=nums2[j]) {
                arr.push_back(nums1[i]);
                i++;
            }
            else {
                arr.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m) {
            arr.push_back(nums1[i]);
            i++;
        }
        while(j<n) {
            arr.push_back(nums2[j]);
            j++;
        }
        i=0;
        for(int num : arr) {
            nums1[i] = num;
            i++;
        }
    }
};