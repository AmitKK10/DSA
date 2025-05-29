class Solution {
  public:
    void fun(Node* root,vector<pair<int,int>> &ans,int len, int sum){
      if(root==NULL) return; //base case
      
      sum+=root->data;
      if(root->left==NULL && root->right==NULL){
          ans.push_back({len,sum});
      }
      
      fun(root->left,ans,len+1,sum);
      fun(root->right,ans,len+1,sum);
  }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        vector<pair<int,int>> ans;
        fun(root,ans,0,0);
        int maxi=0,sum=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i].first>maxi){
                maxi=max(maxi,ans[i].first);
                sum=ans[i].second;
            }
            if(ans[i].first==maxi){
                sum=max(sum,ans[i].second);
            }
        }
        return sum;
    }
};