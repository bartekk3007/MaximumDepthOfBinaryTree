#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(struct TreeNode* root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
}

int main(void)
{
    struct TreeNode* r = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    r->val = 20;
    r->left = NULL;
    r->right = NULL;

    struct TreeNode* base = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    base->val = 10;
    base->right = r;
    base->left = NULL;

    printf("%d\n", minDepth(base));

    free(r);
    free(base);

    return 0;
}