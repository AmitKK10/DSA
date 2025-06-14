class Solution {
  public:
    bool rec(Node* p,Node* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        
        if(p->data!=q->data) return false;
        
        return rec(p->left,q->right) && rec(p->right,q->left);
    }
    bool isSymmetric(Node* root) {
        // Code here
        // do structured thinking in every q
        if(!root) return true;
        
        return rec(root->left,root->right);
    }
};