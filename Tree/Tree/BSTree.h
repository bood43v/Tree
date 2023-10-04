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
    TreeNode<T>* curr = root;/// текущий узел
    int size; /// размер дерева (кол-во узлов)

    void IncSize() {
        size++;
    }

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
    //Удаление узлов

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

    /// Вставка узла
    void Insert(const T& key)
    {
        T key_ = key;
        /// если такого узла нет
        if (this->Find(key_) == nullptr)
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

    /// Поиск минимального в ветке (или дереве)

    TreeNode<T>* FindMin() {
        TreeNode<T>* current = root;
        if (current == nullptr) return nullptr;
        while (current->GetLeft() != nullptr)
            current = current->GetLeft();
        return current;
    }

    /// следующий наибольший
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

    /// добавление узлов в массив
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

    // Рекурсивная функция для вычисления высоты заданного бинарного дерева
    int Height(TreeNode<T>* root)
    {
        // базовый случай: пустое дерево имеет высоту 0
        if (root == nullptr) {
            return 0;
        }

        // повторяем для левого и правого поддерева и учитываем максимальную глубину
        
        return 1 + max( Height(root->GetLeft()), Height(root->GetRight()) );
    }

    /// если элемент находится на дереве, удалить его
    template <class T>
    void DeleteNode(T key)
    {
        TreeNode<T> *parent;
        // если дерево пустое
        if (root == nullptr) return;
       
        // поиск ключа
        curr = this->Find(key);

        // возвращаем, если ключ не найден в дереве
        if (curr == nullptr) {
            return;
        }
        TreeNode<T>* parent = this->FindParent(this->GetRoot(), key);
        // удаляемый узел не имеет дочерних элементов
        if (curr->GetLeft() == nullptr && curr->GetRight() == nullptr)
        {

            // если удаляемый узел не является корневым узлом, то устанавливаем его
            // родительский левый/правый дочерний элемент в null
            if (curr != root)
            {

                if (parent->GetLeft() == curr) {
                    parent->GetLeft() = nullptr;
                }
                else {
                    parent->GetRight() = nullptr;
                }
            }
            // если дерево имеет только корневой узел, устанавливаем его в null
            else {
                root = nullptr;
            }

            // освобождаем память
            delete curr;   
        }

        // удаляемый узел имеет двух потомков
        else if (curr->GetLeft() && curr->GetRight())
        {
            // найти его неупорядоченный узел-преемник
            TreeNode<T>* successor = this->Successor(curr->GetRight());

            // сохраняем последующее значение
            T val = successor->GetData();

            // рекурсивно удаляем преемника. Обратите внимание, что преемник
            // будет иметь не более одного потомка (правого потомка)
            this->DeleteNode(successor->GetData());

            // копируем значение преемника в текущий узел
            curr->data = val;
        }

        // Случай 3: удаляемый узел имеет только одного потомка
        else {
            // выбираем дочерний узел
            TreeNode<T>* child = (curr->GetLeft()) ? curr->GetLeft() : curr->GetRight();

            // если удаляемый узел не является корневым узлом, устанавливаем его родителя
            // своему потомку
            if (curr != root)
            {
                if (curr == parent->GetLeft()) {
                    parent->left = child;
                }
                else {
                    parent->right = child;
                }
            }

            // если удаляемый узел является корневым узлом, то установить корень дочернему
            else {
                this->SetRoot(child);
            }

            // освобождаем память
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