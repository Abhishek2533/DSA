class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        stack<int> st;
        int n=preorder.size();
        vector<int> res;
        
        st.push(preorder[0]);
        
        for(int i=1; i<n; i++) {
            int count = 0;
            int top = st.top();
            while (!st.empty() && preorder[i] > st.top()){
                st.pop();
                count++;
            }
            
            if (count >= 2) res.push_back(top);
            st.push(preorder[i]);
        }
        
        if (res.empty() || res.back() != preorder[n - 1]) res.push_back(preorder[n - 1]);
        
        return res;
    }
};