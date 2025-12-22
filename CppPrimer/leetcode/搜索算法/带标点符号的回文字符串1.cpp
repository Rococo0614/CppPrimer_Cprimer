//我们有自带函数isalnum来判断是否是alphanumeric,同时也有tolower函数来大转小
//当然自己写也不费劲，isalnum就用三段if单独写一个判断，大小转换用if判断后写一个减掉const就行
//同时要注意，while循环才可以当一段都非所求的一次替换完
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            while(left < right && !isalnum(s[left])) left++;
            while(left < right && !isalnum(s[right])) right--;

            if(left < right){
                if(tolower(s[left]) != tolower(s[right])) return false;
                left++;
                right--;
            }

        }
        return true;
    }
};