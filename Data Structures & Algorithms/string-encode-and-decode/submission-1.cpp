
class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded_string="";
        for (string s:strs){
            encoded_string+=to_string(s.size())+"#"+s;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;
        int i=0;
        while (i<s.size()){
            int j=i;
            while (s[j]!='#'){
                j++;
            }
            int len=stoi(s.substr(i,j-i));
            string word=s.substr(j+1,len);
            decoded_strs.push_back(word);
            i=j+1+len;
        }
        return decoded_strs;
    }
};
