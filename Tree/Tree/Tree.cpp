/// Работа с классом TreeNode - узел бинарного дерева
/// @author Будаев Г.Б.
#include <iostream>
#include "TreeNode.h"
//#include "BSTNode.h"
#include "BSTree.h"

using namespace std;

int main()
{
    //// Создание узлов дерева с данными
    //TreeNode<int>* A = new TreeNode<int>(11);
    //TreeNode<int>* B = new TreeNode<int>(22);
    //TreeNode<int>* C = new TreeNode<int>(33);
    //TreeNode<int>* D = new TreeNode<int>(44);
    //TreeNode<int>* E = new TreeNode<int>(55);


    //// Установка левого и правого потомка для узла A
    //A->SetLeft(B);
    //A->SetRight(C);

    //B->SetLeft(D);
    //B->SetRight(E);

    ////// Получение данных из узла
    ////cout << "Data of A: " << A->GetData() << endl;
    ////// Функцией
    ////A->PrintNodeData();
    //
    //A->PrintTreeNLR();
    //cout << endl;
    //A->PrintTreeLNR();
    //cout << endl;
    //A->PrintTreeLRN();

    ///// Удаление узлов
    //A->DeleteTree();

    //A->PrintNodeData();
    //B->PrintNodeData();
    //C->PrintNodeData();
    //D->PrintNodeData();
    //E->PrintNodeData();


    BSTree <int>* Aa = new BSTree<int>();

    Aa->Insert(50);
    Aa->Insert(30);
    Aa->Insert(5);
    Aa->Insert(0);
    Aa->Insert(-15);
    Aa->Insert(-2);
    Aa->Insert(45);
    Aa->Insert(45);
    // поиск по дереву
    int x = 30;
    if (Aa->Find(x) == false) cout << x << " isn't in tree";
    else cout << x << " is in tree";

    // массив
    int *arr = new int[Aa->GetSize()];

    Aa->AddToArrayLNR(Aa->GetRoot(), arr, 0);
    
    //вывод массива
    cout << endl;
    for (int i = 0; i < Aa->GetSize(); i++)
    {
        cout << arr[i] << " ";
    }



    int y = 30;
    Aa->Delete(y);

    cout << Aa->GetSize();

    cout << endl << (Aa->Successor(y))->GetData();
    // 
    //int key = 110;
    //bool result = b1->Search(key);
    //if (result) cout << key << " found" << endl;
    //else cout << key << " not found" << endl;

    //int *arr = NULL;
    //int i = 0;
    //b1->AddToArray(b1, arr, i);

 /*   for (int k = 0; k <= 5; k++) {
        cout << arr[i]  << " ";
    }*/

   // b1->Print_tree();
    return 0;
}
