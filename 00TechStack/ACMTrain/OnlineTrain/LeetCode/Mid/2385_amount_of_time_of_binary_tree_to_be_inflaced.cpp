#include <bits/stdc++.h>
using namespace std;
/*Definition for a binary tree node.*/

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
    int FindFst( TreeNode* root, int start, TreeNode* target ) {
        int height = 0;
        if (root == NULL) {
            return height;
        }
        if (root->val == start) return height;
        height = FindFst( root->left, start, target ) + 1;
        height = FindFst( root->right, start, target ) + 1;
    }
    int TarInfect( TreeNode* root ) {
        int mx , ml , mr;
        if(root == NULL) {return 0;}
        ml = Infect(root->left) + 1;
        mr = Infect(root->right) + 1;
        mx = (mr > ml ? mr : ml);
        return mx;
    }
    int Infect(TreeNode *root , int start){
        int mx , ml , mr;
        if(root == NULL or root->val == start) {return 0;}
        ml = Infect(root->left) + 1;
        mr = Infect(root->right) + 1;
        mx = (mr > ml ? mr : ml);
        return mx;
    }
    int amountOfTime( TreeNode* root, int start ) {
        /*first we need to find the start*/
        TreeNode* target = NULL; /*target->val == start*/
        int t1 = FindFst( root, start, target );
        bool 
        int t2 = Infect(root);
        int t3 = Infect(target);
        

    }
};


int main() {

}