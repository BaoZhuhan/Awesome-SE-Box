#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val( 0 ), left( nullptr ), right( nullptr ) {}
    TreeNode( int x ) : val( x ), left( nullptr ), right( nullptr ) {}
    TreeNode( int x, TreeNode* left, TreeNode* right ) : val( x ), left( left ), right( right ) {}
};

class Solution {
public:
    int FindStart( TreeNode* root, int start, TreeNode* target ) {
        int height = 0;
        if (root->val == start) return height;
        if (root != NULL) {
            height = FindFst( root->left, start, target ) + 1;
            height = FindFst( root->right, start, target ) + 1;
        }

    }

    int dfs( TreeNode* root, int t, int start ) {
        if (root == NULL) return t;
        int tl = dfs( root->left, t + 1, start );
        int tr = dfs( root->right, t + 1, start );
        if (root->val == start) { tl = tr = 0; }
        return (tl > tr ? tl : tr);
    }

    int amountOfTime( TreeNode* root, int start ) {
        TreeNode* tar = FindStart( root, start );
        int t1 =
    }
};

int main() {
    return 0;
}