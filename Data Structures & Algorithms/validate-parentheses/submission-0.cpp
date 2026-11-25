class Solution {
public:
  bool isOpen(char c) {
    return c == '[' || c == '(' || c == '{';
  }

  bool isMatching(char open, char close) {
    if (open == '(' && close == ')') {
      return true;
    } else if (open == '[' && close == ']') {
      return true;
    } else if (open == '{' && close == '}') {
      return true;
    } 
    return false;
  }

  bool isValid(string s) {
    string st;
    for (auto &v: s) {
      if (isOpen(v)) {
        st += v;
      } else {
        if (st.length() > 0) {
          char last = st.back();
          st.pop_back();
          if (!isMatching(last, v)) {
            return false;
          }
        } else {
          return false;
        }
      }
    }

    if (st.length() > 0) {
      return false;
    }
    return true;
  }
};