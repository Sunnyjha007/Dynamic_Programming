 unordered_map<TreeNode*,int> map;
    int rob(TreeNode* root) {
        if(!root)return 0;
        if(map.find(root)!=map.end())return map[root];
        int sum = 0;
        sum+=root->val;
        if(root->left){
            sum+=rob(root->left->left);
            sum+=rob(root->left->right);
        }
        if(root->right){
            sum+=rob(root->right->left);
            sum+=rob(root->right->right);
        }
        int sum2 = rob(root->left) + rob(root->right);
        int ans = max(sum,sum2);
        return map[root] = ans;
}
