#ifndef BSTREE_H
#define BSTREE_H

/**
 * @file bstree.h
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 11
 * @date 11-23-2022
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>

using std::cout;
using std::endl;


//Node Struct
template <class K, class V>
struct node
{
    K key;
    V value;
    node<K, V> *left;
    node<K, V> *right;

    node<K, V> (const K &k = K(), const V &v = V(), node<K, V> *L = nullptr, node<K, V> *R = nullptr)
    {
        key = k;
        value = v;
        left = L;
        right = R;
    }
};


//Binary Search Tree Class
template <class K, class V>
class bstree
{
private:

    //Data Members
    node<K, V> *root;
    size_t tree_size;

    //Private Methods
    node<K, V> *clone(node<K, V> *root);
    size_t height(node<K, V> *n) const;
    const node<K, V> *find(const K &key, node<K, V> *root) const;
    void preorder(node<K, V> *root) const;
    void postorder(node<K, V> *root) const;
    void inorder(node<K, V> *root) const;
    void print_level(node<K, V> *root, int level) const;
    const K &min(node<K, V> *root) const;
    const K &max(node<K, V> *root) const;

public:

    //Public Methods
    bstree();
    ~bstree();
    bstree(const bstree<K, V> &x);
    bstree<K, V> &operator=(const bstree<K, V> &rhs);
    void clear();
    size_t size() const;
    size_t height() const;
    bool empty() const;
    const K &min() const;
    const K &max() const;
    bool insert(const K &key, const V &value);
    bool remove(const K &key);
    const node<K, V> *find(const K &key) const;
    void preorder() const;
    void inorder() const;
    void postorder() const;
    void level_order() const;
    void destroy(node<K, V> *root);

};


/**
 * @brief Default constructor; Sets the root to nullptr and the tree_size to 0
 * 
 */
template <class K, class V>
bstree<K, V>::bstree()
{
    //Initialize the data members
    root = nullptr;
    tree_size = 0;
}


/**
 * @brief Destructor; Calls the clear() method
 * 
 */
template <class K, class V>
bstree<K, V>::~bstree()
{
    clear();
}


/**
 * @brief Copy constructor; Copies the tree's nodes
 * 
 * @param x A reference to a const bstree to be copied
 */
template <class K, class V>
bstree<K, V>::bstree(const bstree<K, V> &x)
{
    tree_size = x.tree_size;
    root = clone(x.root);
}


/**
 * @brief Overloads the assignment operator
 * 
 * @param rhs Binary search tree to be copied
 * 
 * @return bstree<K, V>& reference to this
 */
template <class K, class V>
bstree<K, V> &bstree<K, V>::operator=(const bstree<K, V> &rhs)
{
    if (this != &rhs)
    {
        clear();
        tree_size = rhs.tree_size;
        root = clone(rhs.root);
    }
    return *this;
}


/**
 * @brief Sets the tree back to an empty state, deleting all of the nodes in the tree 
 *        and setting the size back to 0.
 *
 */
template <class K, class V>
void bstree<K, V>::clear()
{
    destroy(root);
    root = nullptr;
    tree_size = 0;
}


/**
 * @brief Returns the tree size
 * 
 * @return tree_size, The size of the tree 
 */
template <class K, class V>
size_t bstree<K, V>::size() const
{
    return tree_size;
}


/**
 * @brief Returns the height of the tree
 * 
 * @return height(root): The height of the tree
 */
template <class K, class V>
size_t bstree<K, V>::height() const
{
    return height(root);
}


/**
 * @brief Helper function for the height function, recursivly finds the height/depth of the tree
 *
 * @param n A node in the tree
 *
 * @return size_t the height of tree
 */
template <class K, class V>
size_t bstree<K, V>::height(node<K, V> *n) const
{
    if (n == nullptr)
    {
        return 0;
    }

    int leftheight = height(n->left);
    int rightheight = height(n->right);

    return std::max(leftheight, rightheight) + 1;
}


/**
 * @brief Checks if tree is empty
 * 
 * @return true: If tree is empty
 * @return false: If there is at least one node
 */
template <class K, class V>
bool bstree<K, V>::empty() const
{
    return (tree_size == 0);
}


/**
 * @brief Returns the minimum key in the tree
 * 
 * @return The minimum key
 */
template <class K, class V>
const K &bstree<K, V>::min() const
{
    return min(root);
}


/**
 *
 * @brief Helper function for min, recursively looks for the max key
 *
 * @param root The current node
 *
 * @return const K& The min key
 *
 */
template <class K, class V>
const K &bstree<K, V>::min(node<K, V> *root) const
{
    if (root->left != nullptr)
    {
        return min(root->left);
    }
    return root->key;
}


/**
 * @brief Returns the maximum key in the tree
 * 
 * @return maximum key
 */
template <class K, class V>
const K &bstree<K, V>::max() const
{
    return max(root);
}


/**
 *
 * @brief Helper function for max, recursively looks for the max key
 *
 * @param root The current node
 *
 * @return const K& the max key
 *
 */
template <class K, class V>
const K &bstree<K, V>::max(node<K, V> *root) const
{
    if (root->right != nullptr)
    {
        return max(root->right);
    }
    return root->key;
}


/**
 * @brief Inserts a new node into the tree
 * 
 * @param key The key of the new node
 * @param value The value of the new node
 * 
 * @return true if the node was inserted
 * @return false if the node was not inserted
 */
template <class K, class V>
bool bstree<K, V>::insert(const K &key, const V &value)
{
    // root     : pointer to the root node of the tree (nullptr if tree is empty)
    // tree_size: tree size  
    // p        : pointer to a tree node
    // parent   : pointer to the parent node of p (nullptr if p points to the root node)
    // new_node : pointer used to create a new tree node
    
    // Start at the root of the tree
    node<K, V> *p = root;
    node<K, V> *parent = nullptr;

    // Search the tree for a null link or a duplicate key
    while (p != nullptr && key != p->key)
    {
        parent = p;
        if (key < p->key)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    // If duplicates are disallowed, signal that insertion has failed.
    if (p != nullptr)
    {
        return false;
    }

    // Otherwise, create a tree node and insert it as a new leaf node
    node<K, V> *new_node = new node<K, V>(key, value);

    if (parent == nullptr)
    {
        root = new_node;
    }
    else
    {
        if (new_node->key < parent->key)
        {
            parent->left = new_node;
        }
        else
        {
            parent->right = new_node;
        }
    }
    tree_size++;

    return true;
}


/**
 * @brief Removes a node from the tree
 * 
 * @param key Key of the node to be removed
 * 
 * @return true if node removed
 * @return false if node not removed
 */
template <class K, class V>
bool bstree<K, V>::remove(const K& key)
{
    // root           : pointer to the root of the binary search tree
    // tree_size      : tree size  
    // p              : pointer to the node to delete from the tree
    // parent         : pointer to the parent node of the node to delete from the tree (or 
    //                  nullptr if deleting the root node)
    // replace        : pointer to node that will replace the deleted node
    // replace_parent : pointer to parent of node that will replace the deleted node

    // Start at the root of the tree and search for the key to delete.
    node<K, V> *p = root;
    node<K, V> *parent = nullptr;
    while (p != nullptr && key != p->key)
    {
        parent = p;
        if (key < p->key)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }

    // If the node to delete was not found, signal failure.
    if (p == nullptr)
    {
        return false;
    }

    node<K, V> *replace;
    node<K, V> *replace_parent;
    if (p->left == nullptr)
    {
        // Case 1a: p has no children. Replace p with its right child
        // (which is nullptr).
        //   - or -
        // Case 1b: p has no left child but has a right child. Replace 
        // p with its right child.
        replace = p->right;
    }
    else if (p->right == nullptr)
    {
        // Case 2: p has a left child but no right child. Replace p 
        // with its left child.
        replace = p->left;
    }
    else
    {
        // Case 3: p has two children. Replace p with its inorder predecessor.

        // Go left...
        replace_parent = p;
        replace = p->left;

        // ...then all the way to the right.
        while (replace->right != nullptr)
        {
            replace_parent = replace;
            replace = replace->right;
        }

        // If we were able to go to the right, make the replacement node's
        // left child the right child of its parent. Then make the left child
        // of p the replacement's left child.
        if (replace_parent != p)
        {
            replace_parent->right = replace->left;
            replace->left = p->left;
        }

        // Make the right child of p the replacement's right child.
        replace->right = p->right;
    }

    // Connect replacement node to the parent node of p (or the root if p has no parent).    
    if (parent == nullptr)
    {
        root = replace;
    }
    else
    {
        if (p->key < parent->key)
        {
            parent->left = replace;
        }
        else
        {
            parent->right = replace;
        }
    }

    // Delete the node, decrement the tree size, and signal success.
    delete[] p;
    tree_size--;

    return true;
}


/**
 * @brief Finds the specified key in the bstree
 * 
 * @param key A node key to search for
 * 
 * @return bstree node if found, otherwise return nullptr
 *
*/
template <class K, class V>
const node<K, V> *bstree<K, V>::find(const K &key) const
{    
    return find(key, root);
}


/**
 * @brief Helper function for find, recursivly searches the bstree for the key
 *
 * @param key A node key to search for
 * @param root The pointer to the current node
 *
 * @return bstree node if found, otherwise nullptr
 *
 */
template <class K, class V>
const node<K, V> *bstree<K, V>::find(const K &key, node<K, V> *root) const
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->key == key)
    {
        return root;
    }

    if (key < root->key)
    {
        return find(key, root->left);
    }
    else
    {
        return find(key, root->right);
    }
}


/**
 * @brief Preorder traversal of the tree
 */
template <class K, class V>
void bstree<K, V>::preorder() const
{
    preorder(root);
}


 /**
 *
 * @brief Helper function for preorder, prints out key and value for the preorder traversal
 *
 * @param root The pointer to the current node
 *
 */
template <class K, class V>
void bstree<K, V>::preorder(node<K, V> *root) const
{
    if (root != nullptr)
    {
        cout << root->key << ": " << root->value << endl;
        preorder(root->left);
        preorder(root->right);
    }
}


/**
 * @brief Inorder traversal of the tree
 */
template <class K, class V>
void bstree<K, V>::inorder() const
{
    inorder(root);
}


/**
 *
 * @brief Helper function for inorder, prints out key and value for the inorder traversal
 *
 * @param root The pointer to the current node
 *
 */
template <class K, class V>
void bstree<K, V>::inorder(node<K, V> *root) const
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->key << ": " << root->value << endl;
        inorder(root->right);
    }
}


/**
 * @brief Postorder traversal of the tree
 */
template <class K, class V>
void bstree<K, V>::postorder() const
{
    postorder(root);
}


 /**
 *
 * @brief Helper function for postorder, prints out key and value for the postorder traversal
 *
 * @param root The pointer to the current node
 */
template <class K, class V>
void bstree<K, V>::postorder(node<K, V> *root) const
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << ": " << root->value << endl;
    }
}


/**
 * @brief Level order traversal of the tree
 */
template <class K, class V>
void bstree<K, V>::level_order() const
{
    size_t h = height(root);

    for (size_t i = 1; i <= h; i++)
    {
        print_level(root, i);
    }
}


/**
 *
 * @brief Helper function for level order traversal, prints out key and value for the level order traversal
 *
 * @param root current node
 *
 * @param level current level on the bstree
 */
template <class K, class V>
void bstree<K, V>::print_level(node<K, V> *root, int level) const
{
    if (root == nullptr)
    {
        return;
    }

    if (level == 1)
    {
        cout << root->key << ": " << root->value << endl;
    }
    else if (level > 1)
    {
        print_level(root->left, level - 1);
        print_level(root->right, level - 1);
    }
}


/**
 * @brief Recursively destroys the dynamically allocated storage if the bst's nodes 
 * 
 * @param root* A point to the current root node to be destroyed
 */
template <class K, class V>
void bstree<K, V>::destroy(node<K, V> *root)
{
    if (root != nullptr)
    {
        // Recursively destroy the left and right subtrees of the node pointed to by p.
        destroy(root->left);
        destroy(root->right);

        delete[] root;
    }
}


/**
 * @brief Helper function for the copy constructor, recursive preorder traversal to copy a bstree
 *
 * @param n  A node in the bstree
 * @param root*  Pointer to the current root node
 *
 * @return new_node  A new bstree node, otherwise nullptr
 */
template <class K, class V>
node<K, V> *bstree<K, V>::clone(node<K, V> *root)
{
    if (root != nullptr)
    {
        // Make a copy of the node pointed to by root
        node<K, V> *new_node = new node<K, V>(root->key, root->value);

        // Recursively copy the left and right subtrees of the node
        new_node->left = clone(root->left);
        new_node->right = clone(root->right);

        return new_node;
    }
    else
    {
        return nullptr;
    }
}

#endif