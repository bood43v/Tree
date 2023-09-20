/// ����� TreeNode - ���� ��������� ������
/// @author ������ �.�.
#pragma once
using namespace std;

template<class T>
class TreeNode
{
private:
    T data;                 /// ������
    TreeNode<T>* left;      /// ����� �������
    TreeNode<T>* right;     /// ������ �������

public:
    /// ����������� ��� ����������
    TreeNode(T data_){
        data = data_; 
        left = nullptr;
        right = nullptr;
    }

    /// ����������� ��� ����������
    TreeNode() {
        data = NULL;
        left = nullptr;
        right = nullptr;
    }

    /// ����������
    ~TreeNode(){}

    void Copy(TreeNode<T>* node_) {
        this = node_;
    }
    /// ���������� ������ �������
    void SetLeft(TreeNode<T>* node_)
    {
        left = node_;
    }

    /// ���������� ������� �������
    void SetRight(TreeNode<T>* node_)
    {
        right = node_;
    }

    /// ������� ������
    T GetData() const
    {
        return data;
    }
    /// ������� ������ �������
    TreeNode<T>* GetLeft() const
    {
        return left;
    }

    /// ������� ������� �������
    TreeNode<T>* GetRight() const
    {
        return right;
    }

    /// ������� ������
    void DeleteTree()
    {
        TreeNode<T>* node_;
        node_ = this;
        if (node_ == nullptr)
            return;

        node_->GetLeft()->DeleteTree();
        node_->GetRight()->DeleteTree();
        delete node_;
    }

    /// ������� ������ ����
    void PrintNodeData()
    {
        if (this != nullptr)
        {
            cout << "Data of node: " << this->GetData() << endl;
        }
        else
        {
            cout << "Node is null" << endl;
        }
    }

    /// ������� ������ NLR
    void PrintTreeNLR()
    {
        TreeNode<T>* node_;
        node_ = this;
        if (node_ == nullptr)
            return;
        node_->PrintNodeData();
        node_->GetLeft()->PrintTreeNLR();
        node_->GetRight()->PrintTreeNLR();
    }

    /// ������� ������ LNR 
    void PrintTreeLNR()
    {
        TreeNode<T>* node_;
        node_ = this;
        if (node_ == nullptr)
            return;
        node_->GetLeft()->PrintTreeLNR();
        node_->PrintNodeData();
        node_->GetRight()->PrintTreeLNR();
    }

    /// ������� ������ LRN
    void PrintTreeLRN()
    {
        TreeNode<T>* node_;
        node_ = this;
        if (node_ == nullptr)
            return;
        node_->GetLeft()->PrintTreeLRN();
        node_->GetRight()->PrintTreeLRN();
        node_->PrintNodeData();
    }

};



