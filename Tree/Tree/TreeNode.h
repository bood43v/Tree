/// Класс TreeNode - узел бинарного дерева
/// @author Будаев Г.Б.
#pragma once
using namespace std;

template<class T>
class TreeNode
{
private:
    T data;                 /// Данные
    TreeNode<T>* left;      /// Левый потомок
    TreeNode<T>* right;     /// Правый потомок

public:
    /// Конструктор без параметров
    TreeNode(T data_){
        data = data_; 
        left = nullptr;
        right = nullptr;
    }

    /// Конструктор без параметров
    TreeNode() {
        data = NULL;
        left = nullptr;
        right = nullptr;
    }

    /// Деструктор
    ~TreeNode(){}

    void Copy(TreeNode<T>* node_) {
        this = node_;
    }
    /// Установить левого потомка
    void SetLeft(TreeNode<T>* node_)
    {
        left = node_;
    }

    /// Установить правого потомка
    void SetRight(TreeNode<T>* node_)
    {
        right = node_;
    }

    /// Вернуть данные
    T GetData() const
    {
        return data;
    }
    /// Вернуть левого потомка
    TreeNode<T>* GetLeft() const
    {
        return left;
    }

    /// Вернуть правого потомка
    TreeNode<T>* GetRight() const
    {
        return right;
    }

    /// Удалить дерево
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

    /// Вывести данные узла
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

    /// Вывести дерево NLR
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

    /// Вывести дерево LNR 
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

    /// Вывести дерево LRN
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



