/************************************/
/*              ^-_-^               */
/*  M. Cihan Ozer - mcihanozer.com  */
/************************************/

/************************************************/
/*   Time: O(n)                     		*/
/*   Memory: O(1) -Thanks to inorder traversal  */
/************************************************/

/*Tree Node:

struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

// Modified inorder traversal
bool traverseForBST(Node* node, int& lastValue)
{
    if(node != NULL)
    {
        if(traverseForBST(node->left, lastValue))
        {
            if(node->data > lastValue)	// In inorder, the last value should alway be
					// smaller than the next value.
            {
                lastValue = node->data;
                return traverseForBST(node->right, lastValue);
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    } 
       
    return true;	// If the node is NULL, it is true
}

bool isBST(Node* root)
{
    int lastValue = -1; // I assume data is in [0, 10^4] range
    return traverseForBST(root, lastValue);
}
