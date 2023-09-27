/// ����� BSTree ��������� ������
/// @author ������ �.�.
#pragma once
#include "TreeNode.h"

/// <summary>
/// ��������� ����� �������� ������ ������, ������������ ����� ���� ������
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
class BSTree
{
private:
    TreeNode<T>* root;/// ������
    TreeNode<T>* curr;/// ������� ����
    int size; /// ������ ������ (���-�� �����)

public:
    /// <summary>
    /// ����������� ��� ����������
    /// </summary>
    BSTree() {
        root = nullptr;
        curr = nullptr;
        size = 0;
    };

    /// <summary>
    /// ����������� � �����������
    /// </summary>
    /// <param name="tree"></param>
    BSTree(const BSTree<T>& tree){
        this = tree;
    };

    /// ����������
    ~BSTree() {};

    /// <summary>
    /// ������� ������
    /// </summary>
    /// <returns></returns>
    TreeNode<T>* GetRoot() {
        return root;
    }

    /// <summary>
    /// �������� ������
    /// </summary>
    /// <returns></returns>
    void SetRoot(TreeNode<T>* root_) {
        root = root_;
    }

    /// <summary>
    /// ������� ������� ����
    /// </summary>
    /// <returns></returns>
    TreeNode<T>* GetCurr() {
        return curr;
    }

    /// <summary>
    /// ���������� ������� ����
    /// </summary>
    /// <returns></returns>
    void SetCurr(TreeNode<T>* curr_) {
        curr = curr_;
    }


    /// <summary>
    /// ������� ������
    /// </summary>
    /// <returns></returns>
    int GetSize() {
        return size;
    }

    void IncSize() {
        size++;
    }


    /// ������� ����
    void Insert(const T& key)
    {
        T key_ = key;
        /// ���� ������ ���� ���
        if (this->Find(root, key_) == nullptr)
        {
            // t � ������� ����, parent � ���������� ����
            TreeNode<T>* t = root, * parent = nullptr, * newNode;
            newNode = new TreeNode<T>(key);

            // ��������� �� ������ ������
            while (t != nullptr)
            {
                // �������� ��������� parent � ���� ������� ��� ������
                parent = t;
                if (key < t->GetData())
                    t = t->GetLeft();
                else
                    t = t->GetRight();
            }
            // ���� �������� ���, �������� � �������� ��������� ����
            if (parent == nullptr)
                this->SetRoot(newNode);
            // ���� item ������ ������������� ����, �������� � �������� ������ ����
            else if (key < parent->GetData())
                parent->SetLeft(newNode);
            else
                // ���� item ������ ��� ����� ������������� ����,
                // �������� � �������� ������� ����
                parent->SetRight(newNode);
            // ��������� ��������� current ����� ������ ���� � ��������� size �� �������
            this->SetCurr(newNode);
            size++;
        }
    }




    /// ����� �������� � ������
    template <class T>
    TreeNode<T>* Find(TreeNode<T>* root_, T key) {
        if (root_ == nullptr) return nullptr;
        else if (root_->GetData() == key) return root_;
        else if (root_->GetData() < key) return Find(root_->GetRight(), key);
        else return Find(root_->GetLeft(), key);
    }

    TreeNode<T>* FindMin(TreeNode<T>* root_) {
        if (root_ == nullptr) return nullptr;
        while (root_->GetLeft() != nullptr)
            root_ = root_->GetLeft();
        return root_;
    }

    // ���� ������� ��������� �� ������, ������� ���
    template <class T>
    TreeNode<T>* Successor(TreeNode<T>* root_, T key)
    {
        TreeNode<T>* current = this->Find(root_, key);
        if (current == nullptr) return nullptr;
        if (current->GetRight() != nullptr) {  
            return FindMin(current->GetRight()); 
        }
        else {   
            TreeNode<T>* successor = nullptr;
            TreeNode<T>* ancestor = root_;
            while (ancestor != current) {
                if (current->GetData() < ancestor->GetData()) {
                    successor = ancestor; 
                    ancestor = ancestor->GetLeft();
                }
                else
                    ancestor = ancestor->GetRight();
            }
            return successor;
        }
    }

    /// ���������� ����� � ������
    int AddToArrayLNR(TreeNode<T>* root_, T arr[], int i)
    {
        if (root_ == nullptr)
            return i;
        if (root_->GetLeft() != nullptr)
            i = AddToArrayLNR(root_->GetLeft(), arr, i);
        arr[i] = root_->GetData();
            i++;
        if (root_->GetRight() != nullptr)
            i = AddToArrayLNR(root_->GetRight(), arr, i);
        return i;
    }


    // ���� ������� ��������� �� ������, ������� ���
    template <class T>
    void DeleteNode(TreeNode<T>* root_,T data)
    {
        TreeNode<T>* current;
        if (root_ == nullptr) return;
        
        if ((this->Find(root_, data))->GetLeft() == nullptr && (this->Find(root_, data)) == nullptr)

            return;

    }


    //void print_tree(TreeNode*);
    //void delete_tree(TreeNode*);
    //void print();
    //
    //void erase(int);
    //int size();
};