/// Класс TreeNode - узел бинарного дерева
/// @author Будаев Г.Б.
#pragma once
using namespace std;

template<class T>
class BSTNode
{
private:
    T data;                /// Данные
    BSTNode<T>* left;      /// Левый потомок
    BSTNode<T>* right;     /// Правый потомок

public:
    /// Конструктор без параметров
    BSTNode(T data_) {
        data = data_;
        left = nullptr;
        right = nullptr;
    }

    /// Конструктор без параметров
    BSTNode() {
        data = NULL;
        left = nullptr;
        right = nullptr;
    }

    /// Деструктор
    ~BSTNode() {}

    ///// Удалить дерево
    //void DeleteTree()
    //{

    //}

    /// Вставка узла
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
        if (curr) // Проверка на ненулевой указатель
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



