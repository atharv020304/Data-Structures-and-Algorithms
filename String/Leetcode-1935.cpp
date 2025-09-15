class Solution {
public:
    bool helper(string& s, unordered_map<char,int>& mp) {
        for (int i = 0; i < (int)s.size(); i++) {
            if (mp.find(s[i]) != mp.end()) {
                return false;
            }
        }
        return true;
    }

    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,int> mp;
        for (auto c : brokenLetters) {
            mp[c]++;
        }

        vector<string> words;
        int st = 0;
        for (int i = 0; i < (int)text.size(); i++) {
            if (text[i] == ' ') { 
                words.push_back(text.substr(st, i - st)); 
                st = i + 1; 
            }
        }
       
        if (st < text.size()) {
            words.push_back(text.substr(st));
        }

        int count = 0;
        for (int i = 0; i < (int)words.size(); i++) {
            if (helper(words[i], mp)) {
                count++;
            }
        }
        return count;
    }
};
