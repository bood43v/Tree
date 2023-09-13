#pragma once

template<class T>
class binary_tree
{
private:
    TreeNode* m_root;
    int m_size;


public:
    void print_tree(tree_elem*);
    void delete_tree(tree_elem*);
    binary_tree(int);
    ~binary_tree();
    void print();
    bool find(int);
    void insert(int);
    void erase(int);
    int size();
};