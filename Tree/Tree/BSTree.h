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

    /// скрытый метод поиска узла в дереве, используемый функцией Find для вывода, присутствует ли элемент в дереве
    template <class T>
    TreeNode<T>* FindNode(const T& item, TreeNode<T>*& parent) const
    {
        // пробежать по узлам дерева, начиная с корня
        TreeNode<T>* t = root;
        //у корня нет родителя
        parent = nullptr;
        // прерваться на пустом дереве
        while (t != nullptr)
        {
            // остановиться по совпадении
            if (item == t->GetData())
                break;
            else
            {
                // обновить родительский указатель и идти направо или налево
                parent = t;
                if (item < t->GetData())
                    t = t->GetLeft();
                else
                    t = t->GetRight();
            }
        }
        // возвратить указатель на узел; NULL, если не найден
        return t;
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

    //// создать объект TreeNode с указательными полями lptr и rptr.
    //// по умолчанию указатели nullptr
    //template <class T>
    //TreeNode<T>* GetTreeNode(T item, TreeNode<T>* lptr = nullptr,
    //    TreeNode<T>* rptr = nullptr)
    //{
    //    TreeNode<T>* p;
    //    // вызвать new для создания нового узла
    //    // передать туда параметры lptr и rptr
    //    p = new TreeNode<T>(item, lptr, rptr);
    //    // если памяти недостаточно, завершить программу сообщением об ошибке
    //    if (p == nullptr)
    //    {
    //        exit(1);
    //    }
    //    // вернуть указатель на выделенную системой память
    //    return p;
    //}

    //// создать дубликат дерева t и возвратить корень нового дерева
    //template <class T>
    //TreeNode<T>* CopyTree(TreeNode<T>* t)
    //{
    //    // переменная newnode указывает на новый узел, создаваемый
    //    // посредством вызова GetTreeNode и присоединяемый в дальнейшем
    //    // к новому дереву, указатели newlptr и newrptr адресуют сыновей
    //    // нового узла и передаются в качестве параметров в GetTreeNode
    //    TreeNode<T>* newlptr, * newrptr, * newnode;
    //    // остановить рекурсивное прохождение при достижении пустого дерева
    //    if (t == nullptr)
    //        return nullptr;
    //    // CopyTree строит новое дерево в процессе прохождения узлов дерева t. в каждом
    //    // узле этого дерева функция CopyTree проверяет наличие левого сына, если он
    //    // есть, создается его копия, в противном случае возвращается NULL. CopyTree
    //    // создает копию узла с помощью GetTreeNode и подвешивает к нему копии сыновей.
    //    if (t->GetLeft() != nullptr)
    //        newlptr = this->CopyTree(t->GetLeft());
    //    else
    //        newlptr - nullptr;
    //    if (t->GetRight() != nullptr)
    //        newrptr = this->CopyTree(t->GetRight());
    //    else
    //        newrptr = nullptr;
    //    // построить новое дерево снизу вверх, сначала создавая
    //    // двух сыновей, а затем их родителя
    //    newnode = this->GetTreeNode(t->GetData(), newlptr, newrptr);
    //    // вернуть указатель на вновь созданное дерево
    //    return newnode;
    //}

    //// оператор присваивания
    //BSTree<T>& operator =(const BSTree<T>& x)
    //{
    //    // если копирование дерева в само себя
    //    if (this == &x)
    //        return *this;
    //    // очистить текущее дерево, скопировать новое дерево в текущий объект
    //    ClearTree();
    //    root = this->CopyTree(this->GetRoot());
    //    // присвоить текущему указателю значение корня и задать размер дерева
    //    curr = this->GetRoot();
    //    size = this->GetSize();
    //    // возвратить ссылку на текущий объект
    //    return *this;
    //}

    /// <summary>
    /// удаление дерева
    /// </summary>
    /// <param name="current"></param>
    //void ClearTree()
    //{
    //    DeleteTree(root);
    //    root = nullptr;
    //}


    //// освободить динамическую память, занимаемую данным узлом
    //template <class t>
    //void FreeTreeNode(TreeNode<T>* p)
    //{
    //    delete p;
    //}

    //// обратный алгоритм для прохождения узлов дерева
    //// и удаление каждого узла при его посещении
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

    /// Вставка узла
    void Insert(const T& key)
    {
        T key_ = key;
        /// если такого узла нет
        if (this->Find(key_) == false)
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
            this->IncSize();
        }
    }



    /// Поиск по дереву
    bool Find(T& key)
    {
        //мы используем FindNode, который принимает параметр parent
        TreeNode<T>* parent = nullptr;
        // искать item, назначить совпавший узел текущим
        this->SetCurr(this->FindNode(key, parent));
        // если найден, присвоить данные узла и возвратить 1
        if (this->GetCurr() != nullptr)
        {
            key = this->GetCurr()->GetData();
            return true;// item найден, возвратить 1
        }
        else
            // item не найден, возвратить 0
        return false;
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
    void Delete(T& item)
    {
        //TreeNode<T>* parent, *deleted, *replaced;
        //if (deleted->Copy(FindNode(item, parent) == false))
        //    return;
        //
        //if((this->FindNode(item, parent))->GetLeft() == nullptr)
    }

    // если элемент находится на дереве, удалить его
    template <class T>
    TreeNode<T>* Successor(T& item)
    {
        // если такого элемента нет
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