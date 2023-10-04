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
    TreeNode<T>* curr = root;/// ������� ����
    int size; /// ������ ������ (���-�� �����)

    void IncSize() {
        size++;
    }

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
    //�������� �����

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

    /// ������� ����
    void Insert(const T& key)
    {
        T key_ = key;
        /// ���� ������ ���� ���
        if (this->Find(key_) == nullptr)
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
    TreeNode<T>* Find(T key) {
        if (curr == nullptr) return nullptr;
        else if (curr->GetData() == key) return root;
        else if (curr->GetData() < key) {
            curr = root->GetRight();
            return Find(key);
        }
        else {
            curr->GetLeft();
            return Find(key);
        }
    }

    /// ����� ������������ � ����� (��� ������)

    TreeNode<T>* FindMin() {
        TreeNode<T>* current = root;
        if (current == nullptr) return nullptr;
        while (current->GetLeft() != nullptr)
            current = current->GetLeft();
        return current;
    }

    /// ��������� ����������
    template <class T>
    TreeNode<T>* Successor( T key)
    {
        curr = this->Find(key);
        if (curr == nullptr) return nullptr;
        if (curr->GetRight() != nullptr) {  
            return FindMin(); 
        }
        else {   
            TreeNode<T>* successor = nullptr;
            TreeNode<T>* ancestor = root;
            while (ancestor != curr) {
                if (curr->GetData() < ancestor->GetData()) {
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
    int AddToArrayLNR(T arr[], int i)
    {
        if (curr == nullptr)
            return i;
        if (curr->GetLeft() != nullptr)
            i = AddToArrayLNR(arr, i);
        arr[i] = curr->GetData();
            i++;
        if (curr->GetRight() != nullptr)
            i = AddToArrayLNR(arr, i);
        return i;
    }

    // ����������� ������� ��� ���������� ������ ��������� ��������� ������
    int Height(TreeNode<T>* root)
    {
        // ������� ������: ������ ������ ����� ������ 0
        if (root == nullptr) {
            return 0;
        }

        // ��������� ��� ������ � ������� ��������� � ��������� ������������ �������
        
        return 1 + max( Height(root->GetLeft()), Height(root->GetRight()) );
    }

    /// ���� ������� ��������� �� ������, ������� ���
    template <class T>
    void DeleteNode(T key)
    {
        TreeNode<T> *parent;
        // ���� ������ ������
        if (root == nullptr) return;
       
        // ����� �����
        curr = this->Find(key);

        // ����������, ���� ���� �� ������ � ������
        if (curr == nullptr) {
            return;
        }
        TreeNode<T>* parent = this->FindParent(this->GetRoot(), key);
        // ��������� ���� �� ����� �������� ���������
        if (curr->GetLeft() == nullptr && curr->GetRight() == nullptr)
        {

            // ���� ��������� ���� �� �������� �������� �����, �� ������������� ���
            // ������������ �����/������ �������� ������� � null
            if (curr != root)
            {

                if (parent->GetLeft() == curr) {
                    parent->GetLeft() = nullptr;
                }
                else {
                    parent->GetRight() = nullptr;
                }
            }
            // ���� ������ ����� ������ �������� ����, ������������� ��� � null
            else {
                root = nullptr;
            }

            // ����������� ������
            delete curr;   
        }

        // ��������� ���� ����� ���� ��������
        else if (curr->GetLeft() && curr->GetRight())
        {
            // ����� ��� ��������������� ����-��������
            TreeNode<T>* successor = this->Successor(curr->GetRight());

            // ��������� ����������� ��������
            T val = successor->GetData();

            // ���������� ������� ���������. �������� ��������, ��� ��������
            // ����� ����� �� ����� ������ ������� (������� �������)
            this->DeleteNode(successor->GetData());

            // �������� �������� ��������� � ������� ����
            curr->data = val;
        }

        // ������ 3: ��������� ���� ����� ������ ������ �������
        else {
            // �������� �������� ����
            TreeNode<T>* child = (curr->GetLeft()) ? curr->GetLeft() : curr->GetRight();

            // ���� ��������� ���� �� �������� �������� �����, ������������� ��� ��������
            // ������ �������
            if (curr != root)
            {
                if (curr == parent->GetLeft()) {
                    parent->left = child;
                }
                else {
                    parent->right = child;
                }
            }

            // ���� ��������� ���� �������� �������� �����, �� ���������� ������ ���������
            else {
                this->SetRoot(child);
            }

            // ����������� ������
            delete curr;
        }
    }


    


    //void print_tree(TreeNode*);
    //void delete_tree(TreeNode*);
    //void print();
    //
    //void erase(int);
    //int size();
};