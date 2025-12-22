//虽然直接塞进去然后sort确实能解决问题，但是观察数组已经是有序的，我们应该利用这种顺序
class Solution{
    public:
    void merge(vector<int>& nums1, m, vector<int>& nums2, n){
        int i = m - 1; 
        int j = n - 1;
        int k = m + n - 1;
        while(k >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
}