class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            cout << " not valid anagrams\n";
            return false;
        }

        int count[26] = {0};
        for ( int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
        }

        for (int i = 0; i < t.length(); i++){
            if (count[t[i] - 'a'] == 0) {
                cout << "not valid anagrams\n";
                return false;
            }
            count[t[i] - 'a']--;
        }
        cout << "valid anagrams\n";
        return true;
    }
};