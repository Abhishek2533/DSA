class Solution {
  public:
    string caseSort(string& s) {
        // code here
        vector<int> isLowerCase(26, 0);
        vector<int> isUpperCase(26, 0);
        
        for(auto &e : s){
            if(isupper(e)){
                isUpperCase[e - 'A']++;
            }else{
                isLowerCase[e - 'a']++;
            }
        }
        
        int idx1 = 0;
        int idx2 = 0;
        for(int i = 0; i < s.length(); i++){
            if(isupper(s[i])){
                while(isUpperCase[idx1] == 0){
                    idx1++;
                }
                s[i] = char('A' + idx1);
                isUpperCase[idx1]--;
            }else{
                while(isLowerCase[idx2] == 0){
                    idx2++;
                }
                s[i] = char('a' + idx2);
                isLowerCase[idx2]--;
            }
        }
        return s;
    }
};