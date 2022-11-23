/* Here's code Kash had at the end of of his public methods in bstree.h. I'm assuming these were used in the final exam or exam 3
   to count the "leaves" on each binary tree. Will be clutch if thats the case. And if so, we should change it up a bit so it's not
   so obvious. But I tested the output and these are NOT REQUIRED */

// EXAM 3
    size_t count_leaves(node<K, V>*) const;
    size_t count_leaves() const;


// EXAM 3
template <class K, class V>
size_t bstree<K, V>::count_leaves() const
{
    if (root == nullptr)
        return 0;
    else
        return count_leaves(root);
}

template <class K, class V>
size_t bstree<K, V>::count_leaves(node<K, V> *root) const
{
    // base case
    if (root == nullptr)
    {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }
    return count_leaves(root->left) + count_leaves(root->right);
}