class Solution {
public:
    bool isValid(string s) {
        return helper(s);
    }
private:
    stack <char> st;
    bool helper(string& s){
        bool pop = false;
        for (int i = 0; i < s.length(); i++){
            char x_ = s[i];
            string x(1, x_);
            if (st.empty() == false)
            {
                char& c_ = st.top();
                string c (1, c_);
                if (c == "(" && x == ")")
                {
                    st.pop();
                    pop = true;
                }
                else if (c == "[" && x == "]")
                {
                    st.pop();
                    pop = true;
                }
                else if (c == "{" && x == "}")
                {
                    st.pop();
                    pop = true;
                }
            }
            if (pop == false)
            {
                st.push(x_);
            }
            pop = false;
            
        }
        return st.empty() ? true : false;
    }
};

// Runtime 0 ms Beats 100%
// Memory 6.3 MB Beats 79.99%

// solution 2: hashmap C++

class Solution {
public:
    bool isValid(string s) {
        return helper(s);
    }
private:
    bool helper(string &s){
        stack<char> st;
        unordered_map<char, char> m;
        m['['] = ']';
        m['{'] = '}';
        m['('] = ')';

        char c = '\0';
        bool is_pair = false;

        for (auto& x : s){
            is_pair = false;
            if (st.empty() == false){
                c = st.top();
                if (m[c] == x){
                    st.pop();
                    is_pair = true;
                }
            }
            if (is_pair == false) {
                st.push(x); 
            }                       
        }
        return st.empty() == true ? true : false;
    }
};

// Runtime 4 ms Beats 33.40% 
// Memory 6.4 MB Beats 10.45%
