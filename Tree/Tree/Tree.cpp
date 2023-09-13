/// Работа с классом TreeNode - узел бинарного дерева
/// @author Будаев Г.Б.
#include <iostream>
#include "TreeNode.h"

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




    return 0;
}
