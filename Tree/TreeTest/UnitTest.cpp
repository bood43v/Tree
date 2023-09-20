#include "pch.h"
#include "CppUnitTest.h"
#include "../Tree/BSTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreeTest
{
    TEST_CLASS(UnitTest1)
    {
    public:
        /// <summary>
        /// тест вывода дерева в массив
        /// </summary>
        TEST_METHOD(Test_AddToArray)
        {
            BSTree <int>* A = new BSTree<int>();
            // массив
            int* arr = new int[A->GetSize()];

            A->Insert(50);
            A->Insert(30);
            A->Insert(30);
            A->AddToArrayLNR(A->GetRoot(), arr, 0);
            Assert::IsTrue(A->GetSize() == 2);
            Assert::IsTrue(A->GetSize() != 3 && A->GetSize() != 1);
        }


        /// <summary>
        /// тест вставки узла (без дублирования)
        /// </summary>
        TEST_METHOD(Test_Insert)
        {
            BSTree <int>* A = new BSTree<int>();
            // массив
            int* arr = new int[A->GetSize()];
            
            A->Insert(5);//         5
            A->Insert(3);//     3       7
            A->Insert(3);//   1
            A->Insert(1);//
            A->Insert(7);//
            A->AddToArrayLNR(A->GetRoot(), arr, 0);
            Assert::IsTrue(arr[0] == 1);
            Assert::IsTrue(arr[1] == 3);
            Assert::IsTrue(arr[2] == 5);
            Assert::IsTrue(arr[3] == 7);
        }

        /// <summary>
        /// тест поиска по дереву
        /// </summary>
        TEST_METHOD(Test_Find)
        {
            BSTree <int>* A = new BSTree<int>();   
            A->Insert(50);
            A->Insert(30);
            A->Insert(5);
            A->Insert(0);
            A->Insert(-15);
            A->Insert(-2);
            A->Insert(45);

            // искомое значение
            int x = 30;
            Assert::IsTrue(A->Find(x) == true);
            x = 0;
            Assert::IsTrue(A->Find(x) == true);
            x = 2;
            Assert::IsTrue(A->Find(x) == false);
        }
    };
}