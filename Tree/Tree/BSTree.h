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

    /// ������� ����� ������ ���� � ������, ������������ �������� Find ��� ������, ������������ �� ������� � ������
    template <class T>
    TreeNode<T>* FindNode(const T& item, TreeNode<T>*& parent) const
    {
        // ��������� �� ����� ������, ������� � �����
        TreeNode<T>* t = root;
        //� ����� ��� ��������
        parent = nullptr;
        // ���������� �� ������ ������
        while (t != nullptr)
        {
            // ������������ �� ����������
            if (item == t->GetData())
                break;
            else
            {
                // �������� ������������ ��������� � ���� ������� ��� ������
                parent = t;
                if (item < t->GetData())
                    t = t->GetLeft();
                else
                    t = t->GetRight();
            }
        }
        // ���������� ��������� �� ����; NULL, ���� �� ������
        return t;
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

    //// ������� ������ TreeNode � ������������� ������ lptr � rptr.
    //// �� ��������� ��������� nullptr
    //template <class T>
    //TreeNode<T>* GetTreeNode(T item, TreeNode<T>* lptr = nullptr,
    //    TreeNode<T>* rptr = nullptr)
    //{
    //    TreeNode<T>* p;
    //    // ������� new ��� �������� ������ ����
    //    // �������� ���� ��������� lptr � rptr
    //    p = new TreeNode<T>(item, lptr, rptr);
    //    // ���� ������ ������������, ��������� ��������� ���������� �� ������
    //    if (p == nullptr)
    //    {
    //        exit(1);
    //    }
    //    // ������� ��������� �� ���������� �������� ������
    //    return p;
    //}

    //// ������� �������� ������ t � ���������� ������ ������ ������
    //template <class T>
    //TreeNode<T>* CopyTree(TreeNode<T>* t)
    //{
    //    // ���������� newnode ��������� �� ����� ����, �����������
    //    // ����������� ������ GetTreeNode � �������������� � ����������
    //    // � ������ ������, ��������� newlptr � newrptr �������� �������
    //    // ������ ���� � ���������� � �������� ���������� � GetTreeNode
    //    TreeNode<T>* newlptr, * newrptr, * newnode;
    //    // ���������� ����������� ����������� ��� ���������� ������� ������
    //    if (t == nullptr)
    //        return nullptr;
    //    // CopyTree ������ ����� ������ � �������� ����������� ����� ������ t. � ������
    //    // ���� ����� ������ ������� CopyTree ��������� ������� ������ ����, ���� ��
    //    // ����, ��������� ��� �����, � ��������� ������ ������������ NULL. CopyTree
    //    // ������� ����� ���� � ������� GetTreeNode � ����������� � ���� ����� �������.
    //    if (t->GetLeft() != nullptr)
    //        newlptr = this->CopyTree(t->GetLeft());
    //    else
    //        newlptr - nullptr;
    //    if (t->GetRight() != nullptr)
    //        newrptr = this->CopyTree(t->GetRight());
    //    else
    //        newrptr = nullptr;
    //    // ��������� ����� ������ ����� �����, ������� ��������
    //    // ���� �������, � ����� �� ��������
    //    newnode = this->GetTreeNode(t->GetData(), newlptr, newrptr);
    //    // ������� ��������� �� ����� ��������� ������
    //    return newnode;
    //}

    //// �������� ������������
    //BSTree<T>& operator =(const BSTree<T>& x)
    //{
    //    // ���� ����������� ������ � ���� ����
    //    if (this == &x)
    //        return *this;
    //    // �������� ������� ������, ����������� ����� ������ � ������� ������
    //    ClearTree();
    //    root = this->CopyTree(this->GetRoot());
    //    // ��������� �������� ��������� �������� ����� � ������ ������ ������
    //    curr = this->GetRoot();
    //    size = this->GetSize();
    //    // ���������� ������ �� ������� ������
    //    return *this;
    //}

    /// <summary>
    /// �������� ������
    /// </summary>
    /// <param name="current"></param>
    //void ClearTree()
    //{
    //    DeleteTree(root);
    //    root = nullptr;
    //}


    //// ���������� ������������ ������, ���������� ������ �����
    //template <class t>
    //void FreeTreeNode(TreeNode<T>* p)
    //{
    //    delete p;
    //}

    //// �������� �������� ��� ����������� ����� ������
    //// � �������� ������� ���� ��� ��� ���������
    //template <class T>
    //void DeleteTree(TreeNode<T> *t)
    //{
    //    if (this->GetRoot() != nullptr)
    //    {
    //        this->DeleteTree(t->GetLeft());
    //        this->DeleteTree(t->GetRight());
    //        delete t;
    //    }
    //}

    /// ������� ����
    void Insert(const T& key)
    {
        T key_ = key;
        /// ���� ������ ���� ���
        if (this->Find(key_) == false)
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
            this->IncSize();
        }
    }



    /// ����� �� ������
    bool Find(T& key)
    {
        //�� ���������� FindNode, ������� ��������� �������� parent
        TreeNode<T>* parent = nullptr;
        // ������ item, ��������� ��������� ���� �������
        this->SetCurr(this->FindNode(key, parent));
        // ���� ������, ��������� ������ ���� � ���������� 1
        if (this->GetCurr() != nullptr)
        {
            key = this->GetCurr()->GetData();
            return true;// item ������, ���������� 1
        }
        else
            // item �� ������, ���������� 0
        return false;
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
    void Delete(T& item)
    {
        //TreeNode<T>* parent, *deleted, *replaced;
        //if (deleted->Copy(FindNode(item, parent) == false))
        //    return;
        //
        //if((this->FindNode(item, parent))->GetLeft() == nullptr)
    }

    // ���� ������� ��������� �� ������, ������� ���
    template <class T>
    TreeNode<T>* Successor(T& item)
    {
        // ���� ������ �������� ���
        if (this->Find(item) == false) return nullptr;

        if ((this->FindNode(item, root))->GetRight() != nullptr)
            return (this->FindNode(item, root))->GetRight();
    }

    //void print_tree(TreeNode*);
    //void delete_tree(TreeNode*);
    //void print();
    //
    //void erase(int);
    //int size();
};