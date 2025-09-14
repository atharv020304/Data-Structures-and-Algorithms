//tle error
// class Solution {
// public:
//     int countVowels(string& s){
//         int count = 0;
//         for(int i = 0 ; i < (int)s.size() ; i++){
//             char c = s[i];
//             if(c == 'a' || c == 'A' || c == 'e' || c == 'E' ||
//                c == 'i' || c == 'I' || c == 'o' || c == 'O' ||
//                c == 'u' || c == 'U'){
//                 count++;
//             }
//         }
//         return count;
//     }

//     string toLowerStr(const string &s){
//         string t = s;
//         for(char &c : t) c = tolower((unsigned char)c);
//         return t;
//     }

//     string devowel(const string &s){
//         string t = toLowerStr(s);
//         for(char &c : t){
//             if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') c = '*';
//         }
//         return t;
//     }

//     bool IsMatching(const string &a , const string &b){
//         return toLowerStr(a) == toLowerStr(b);
//     }

//     void processAns(const string& a, const string& b, string& exact, string& ci, string& vowel){
//         if(exact.empty() && a == b){
//             exact = b;
//             return;
//         }
//         if(ci.empty() && IsMatching(a, b)){
//             ci = b;
//         }
//         if(vowel.empty() && devowel(a) == devowel(b)){
//             vowel = b;
//         }
//     }

//     vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
//         vector<string> ans;

//         for(int i = 0 ; i < (int)queries.size(); i++){
//             string exact = "", ci = "", vowel = "";
//             for(int j = 0 ; j < (int)wordlist.size(); j++){
//                 processAns(queries[i], wordlist[j], exact, ci, vowel);
//                 if(!exact.empty()) break;
//             }

//             if(!exact.empty()) ans.push_back(exact);
//             else if(!ci.empty()) ans.push_back(ci);
//             else if(!vowel.empty()) ans.push_back(vowel);
//             else ans.push_back("");
//         }

//         return ans;
//     }
// };


class Solution {
public:
    string toLowerString(const string &word) {
        string result = word;
        for (char &c : result) c = tolower((unsigned char)c);
        return result;
    }

    string maskVowels(const string &word) {
        string lower = toLowerString(word);
        for (char &c : lower) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                c = '*';
        }
        return lower;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactWords(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitiveMap;
        unordered_map<string, string> vowelMaskedMap;

        for (const string &word : wordlist) {
            string lower = toLowerString(word);
            string masked = maskVowels(word);
            if (caseInsensitiveMap.find(lower) == caseInsensitiveMap.end()) {
                caseInsensitiveMap[lower] = word;
            }
            if (vowelMaskedMap.find(masked) == vowelMaskedMap.end()) {
                vowelMaskedMap[masked] = word;
            }
        }

        vector<string> results;
        results.reserve(queries.size());

        for (const string &query : queries) {
            if (exactWords.count(query)) {
                results.push_back(query);
            } else {
                string lower = toLowerString(query);
                string masked = maskVowels(query);
                if (caseInsensitiveMap.count(lower)) {
                    results.push_back(caseInsensitiveMap[lower]);
                } else if (vowelMaskedMap.count(masked)) {
                    results.push_back(vowelMaskedMap[masked]);
                } else {
                    results.push_back("");
                }
            }
        }
        return results;
    }
};
