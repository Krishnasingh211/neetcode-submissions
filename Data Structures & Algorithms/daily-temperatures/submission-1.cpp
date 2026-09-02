class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&temperatures[i]>temperatures[st.top()]){
               ans[st.top()]=i;
               st.pop();
            }
            st.push(i);
        }
        vector<int>ans1;
        for(int i=0;i<n;i++){
            if(ans[i]==-1) ans1.push_back(0);
            else{
                ans1.push_back(ans[i]-i);
            }
        }
        return ans1;
    }
};
