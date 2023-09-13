/// ����� TreeNode - ���� ��������� ������
/// @author ������ �.�.
#pragma once
using namespace std;

template<class T>
class BSTNode
{
private:
    T data;                /// ������
    BSTNode<T>* left;      /// ����� �������
    BSTNode<T>* right;     /// ������ �������

public:
    /// ����������� ��� ����������
    BSTNode(T data_) {
        data = data_;
        left = nullptr;
        right = nullptr;
    }

    /// ����������� ��� ����������
    BSTNode() {
        data = NULL;
        left = nullptr;
        right = nullptr;
    }

    /// ����������
    ~BSTNode() {}

    ///// ������� ������
    //void DeleteTree()
    //{

    //}

    /// ������� ����
    template<class T>
    void InsertNode(T key)
    {
        BSTNode* curr = this;
        while (curr && curr->data != key)
        {
            if (curr->data > key && curr->left == NULL)
            {
                curr->left = new BSTNode(key);
                return;
            }
            if (curr->data < key && curr->right == NULL)
            {
                curr->right = new BSTNode(key);
                return;
            }
            if (curr->data > key)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }


   
    void Print_tree()
    {
        BSTNode* curr = this;
        if (curr) // �������� �� ��������� ���������
        {
            curr->left->Print_tree();
            cout << curr->data << " ";
            curr->right->Print_tree();
        }
    }

    template<class T>
    bool Search(T key)
    {
        BSTNode* curr = this;
        while (curr && curr->data != key)
        {
            if (curr->data > key)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return curr != NULL;
    }

};



