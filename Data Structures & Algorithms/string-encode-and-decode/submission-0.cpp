class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(string t : strs) s+=(t+"Azamat");
        return s;
    }

    vector<string> decode(string s) {
        vector<string> v;
        while(!s.empty())
        {
            int x = s.find("Azamat");
            v.push_back(s.substr(0, x));
            s.erase(0, x+6);
        }
        return v;
    }
};
