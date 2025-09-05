class Solution {
public:
    int minDistance(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        vector<vector<int>> table(len1 + 1, vector<int>(len2 + 1, 0));

        for (int i = 0; i <= len1; i++) 
            table[i][0] = i;
        for (int j = 0; j <= len2; j++) 
            table[0][j] = j;

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    table[i][j] = table[i - 1][j - 1];
                } else {
                    int insertOp = table[i][j - 1];
                    int deleteOp = table[i - 1][j];
                    int replaceOp = table[i - 1][j - 1];
                    table[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
                }
            }
        }

        int ans = table[len1][len2];
        return ans;
    }
};
