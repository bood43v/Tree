/// Работа с классом TreeNode - узел бинарного дерева
/// @author Будаев Г.Б.
#include <iostream>
#include "TreeNode.h"
#include "BSTNode.h"

using namespace std;

int main()
{
    // Создание узлов дерева с данными
    TreeNode<int>* A = new TreeNode<int>(11);
    TreeNode<int>* B = new TreeNode<int>(22);
    TreeNode<int>* C = new TreeNode<int>(33);
    TreeNode<int>* D = new TreeNode<int>(44);
    TreeNode<int>* E = new TreeNode<int>(55);


    // Установка левого и правого потомка для узла A
    A->SetLeft(B);
    A->SetRight(C);

    B->SetLeft(D);
    B->SetRight(E);

    //// Получение данных из узла
    //cout << "Data of A: " << A->GetData() << endl;
    //// Функцией
    //A->PrintNodeData();
    
    A->PrintTreeNLR();
    cout << endl;
    A->PrintTreeLNR();
    cout << endl;
    A->PrintTreeLRN();

    /// Удаление узлов
    A->DeleteTree();

    A->PrintNodeData();
    B->PrintNodeData();
    C->PrintNodeData();
    D->PrintNodeData();
    E->PrintNodeData();


    BSTNode<int>* b1 = new BSTNode<int>(10);
    b1->InsertNode(20);
    b1->InsertNode(5);
    b1->InsertNode(23);

    bool result = b1->Search(110);
    if (result) cout << "found" << endl;
    else cout << "not found" << endl;

    b1->Print_tree();
    return 0;
}
