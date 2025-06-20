#ifndef Utils_h
#define Utils_h

#include <string>

static bool is_number(const std::string& s) {
    if (s.empty()) return false;
    size_t start = 0;
    
    if (s[0] == '+' || s[0] == '-') {
        if (s.size() == 1) return false;
        start = 1;
    }

    for (size_t i = start; i < s.size(); ++i) {
        char c = s[i];
        if (c < '0' || c > '9') {
            return false;
        }
    }
    return true;
}

#endif /* Utils_h */
