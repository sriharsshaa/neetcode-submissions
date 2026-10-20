class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        if(m>n) return false;
        unordered_map<char,int> c1,c2;
        for(char s:s1) c1[s]++;
        for(int i=0;i<m;i++)
            c2[s2[i]]++;

        if(c1==c2) return true;

        for(int r=m;r<n;r++){
            c2[s2[r]]++;
            char old=s2[r-m];
            c2[old]--;
            if (c2[old]==0)
                c2.erase(old);
            if(c1==c2) return true;
        }
        return false;
    }
/*
    1. Count the characters in the first window.
    2. Move one step to the right.
    3. Add the new character entering the window.
    4. Remove the character leaving the window.
    5. Compare its character counts with s1.
    6. If all counts match, return true.If no window matches, return false.
*/
};
