class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0, open = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
            } else {
                if (i + 1 < n && s[i + 1] == ')') {
                    i++;                 // consume the pair "))"
                } else {
                    insertions++;        // lone ')': insert the missing ')'
                }
                if (open > 0) open--;    // matched with a '('
                else insertions++;       // nothing to match: insert a '('
            }
        }
        return insertions + 2 * open;    // each leftover '(' needs "))"
    }
};
