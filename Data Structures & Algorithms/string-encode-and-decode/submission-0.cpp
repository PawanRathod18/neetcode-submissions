class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded="";
        for(string s:strs){
            encoded += to_string(s.length());
            encoded+='#';

            encoded+=s;
        }
        return encoded;


    }

    vector<string> decode(string s) {
        vector<string>result;
        int i=0;
        while (i<s.length()){
            int j=i;

            while (s[j] != '#'){
                j++;
            } 
            int length=stoi(s.substr(i,j-i));
            i = j+1;
            string word=s.substr(i,length);
            result.push_back(word);
            i=i+length;

        }
        return result;

    }
};
