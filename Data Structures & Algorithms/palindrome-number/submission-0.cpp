class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int m=x;
        int rev=0;
        while(m>0){
            int r=m%10;
            rev=rev*10+r;
            m=m/10;
        }
        return rev==x;
    }
};