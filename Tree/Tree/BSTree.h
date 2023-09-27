/// Класс BSTree бинарного дерева
/// @author Будаев Г.Б.
#pragma once
#include "TreeNode.h"

/// <summary>
/// шаблонный класс бинарное дерево поиска, использующий класс узел дерева
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
class BSTree
{
private:
    TreeNode<T>* root;/// корень
    TreeNode<T>* curr;/// текущий узел
    int size; /// размер дерева (кол-во узлов)

public:
    /// <summary>
    /// конструктор без параметров
    /// </summary>
    BSTree() {
        root = nullptr;
        curr = nullptr;
        size = 0;
    };

    /// <summary>
    /// конструктор с параметромм
    /// </summary>
    /// <param name="tree"></param>
    BSTree(const BSTree<T>& tree){
        this = tree;
    };

    /// деструктор
    ~BSTree() {};

    /// <summary>
    /// вернуть корень
    /// </summary>
    /// <returns></returns>
    TreeNode<T>* GetRoot() {
        return root;
    }

    /// <summary>
    /// изменить корень
    /// </summary>
    /// <returns></returns>
    void SetRoot(TreeNode<T>* root_) {
        root = root_;
    }

    /// <summary>
    /// вернуть текущий узел
    /// </summary>
    /// <returns></returns>
    TreeNode<T>* GetCurr() {
        return curr;
    }

    /// <summary>
    /// установить текущий узел
    /// </summary>
    /// <returns></returns>
    void SetCurr(TreeNode<T>* curr_) {
        curr = curr_;
    }


    /// <summary>
    /// вернуть размер
    /// </summary>
    /// <returns></returns>
    int GetSize() {
        return size;
    }

    void IncSize() {
        size++;
    }


    /// Вставка узла
    void Insert(const T& key)
    {
        T key_ = key;
        /// если такого узла нет
        if (this->Find(root, key_) == nullptr)
        {
            // t — текущий узел, parent — предыдущий узел
            TreeNode<T>* t = root, * parent = nullptr, * newNode;
            newNode = new TreeNode<T>(key);

            // закончить на пустом дереве
            while (t != nullptr)
            {
                // обновить указатель parent и идти направо или налево
                parent = t;
                if (key < t->GetData())
                    t = t->GetLeft();
                else
                    t = t->GetRight();
            }
            // если родителя нет, вставить в качестве корневого узла
            if (parent == nullptr)
                this->SetRoot(newNode);
            // если item меньше родительского узла, вставить в качестве левого сына
            else if (key < parent->GetData())
                parent->SetLeft(newNode);
            else
                // если item больше или равен родительскому узлу,
                // вставить в качестве правого сына
                parent->SetRight(newNode);
            // присвоить указателю current адрес нового узла и увеличить size на единицу
            this->SetCurr(newNode);
            size++;
        }
    }




    /// Поиск элемента в дереве
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

    // если элемент находится на дереве, удалить его
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

    /// добавление узлов в массив
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


    // если элемент находится на дереве, удалить его
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