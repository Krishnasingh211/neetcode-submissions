class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nse(n,n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[i]<heights[st.top()]){
                nse[st.top()]=i;
                st.pop();
            }
            st.push(i);

        }
        st = stack<int>();
        vector<int>pse(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&heights[i]<heights[st.top()]){
                pse[st.top()]=i;
                st.pop();
            }
            st.push(i);

        }
        int ans=0;
        for(int i=0;i<n;i++){
            int wt=(nse[i]-pse[i]-1);
            int ht=heights[i];
            ans=max(ans,wt*ht);
        }
       return ans;
    }
};
