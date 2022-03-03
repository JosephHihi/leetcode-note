
#include <string.h>
bool isAnagram (string s, string t) {
    int record[26] = {0};
    for (int i = 0; i < strlen(s), i++) {
        record[s[i]-'a']++;
    }
    for (int i = 0; i < strlen(t); i++) {
        record[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (record[i] != 0) {
            return false;
        }
    }
    return true;
}