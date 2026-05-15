class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;

        for(auto& string : strs)
        {
            encoded_string += to_string(string.size()) + "#" + string;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> strs;

        int i = 0;

        while(i < s.size())
        {
            int j = i;
            while(s[j] != '#')
            {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;
            strs.push_back(s.substr(i, length));
            i = j;
        }

        return strs;
    }
};
