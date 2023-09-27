#include "pch.h"
#include "CppUnitTest.h"
#include "../Tree/BSTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreeTest
{
    TEST_CLASS(UnitTest1)
    {
    public:
        void Generate(BSTree <int>* & tr1, BSTree <int>*& tr2, BSTree <int>*& tr3, BSTree <int>*& tr4, BSTree <int>*& tr5, BSTree <int>*& tr6) {
            
            tr1->Insert(5);/// вырожденное 5    
            tr1->Insert(10);///               10
            tr1->Insert(20);///                   20
            tr1->Insert(30);///                       30    
            tr1->Insert(40);///                           40

            tr2->Insert(1); /// 1 узел

            /// t3 пустое

            tr4->Insert(10);//          10  
            tr4->Insert(5);//       5        15
            tr4->Insert(2);///  2     6   12
            tr4->Insert(6);///
            tr4->Insert(15);///           
            tr4->Insert(12);///  

            tr5->Insert(10);///        10  
            tr5->Insert(5);///      5      15
            tr5->Insert(2);///  2             20  
            tr5->Insert(15);///           
            tr5->Insert(20);///  

            tr6->Insert(0);///   0
            tr6->Insert(1);///      1
        }

        /// <summary>
        /// тест вывода дерева в массив
        /// </summary>
        TEST_METHOD(Test_AddToArray)
        {

            BSTree <int>* t1 = new BSTree<int>();
            BSTree <int>* t2 = new BSTree<int>();
            BSTree <int>* t3 = new BSTree<int>();
            BSTree <int>* t4 = new BSTree<int>();
            BSTree <int>* t5 = new BSTree<int>();
            BSTree <int>* t6 = new BSTree<int>();
            Generate(t1, t2, t3, t4, t5, t6);

            int* arr1 = new int[t1->GetSize()];
            t1->AddToArrayLNR(t1->GetRoot(), arr1, 0);
            Assert::IsTrue(t1->GetSize() == 5);

            int* arr2 = new int[t2->GetSize()];
            t2->AddToArrayLNR(t2->GetRoot(), arr2, 0);
            Assert::IsTrue(t2->GetSize() == 1);

            int* arr3 = new int[t3->GetSize()];
            t3->AddToArrayLNR(t3->GetRoot(), arr3, 0);
            Assert::IsTrue(t3->GetSize() == 0);

            int* arr4 = new int[t4->GetSize()];
            t4->AddToArrayLNR(t4->GetRoot(), arr4, 0);
            Assert::IsTrue(t4->GetSize() == 6);

            int* arr5 = new int[t5->GetSize()];
            t5->AddToArrayLNR(t5->GetRoot(), arr5, 0);
            Assert::IsTrue(t5->GetSize() == 5);

            int* arr6 = new int[t6->GetSize()];
            t6->AddToArrayLNR(t6->GetRoot(), arr6, 0);
            Assert::IsTrue(t6->GetSize() == 2);
        }


        /// <summary>
        /// тест вставки узла (без дублирования)
        /// </summary>
        TEST_METHOD(Test_Insert)
        {
            BSTree <int>* t1 = new BSTree<int>();
            BSTree <int>* t2 = new BSTree<int>();
            BSTree <int>* t3 = new BSTree<int>();
            BSTree <int>* t4 = new BSTree<int>();
            BSTree <int>* t5 = new BSTree<int>();
            BSTree <int>* t6 = new BSTree<int>();
            Generate(t1, t2, t3, t4, t5, t6);

            int* arr1 = new int[t1->GetSize()];
            t1->AddToArrayLNR(t1->GetRoot(), arr1, 0);
            Assert::IsTrue(arr1[0] == 5);
            Assert::IsTrue(arr1[2] == 20);
            Assert::IsTrue(arr1[4] == 40);

            int* arr2 = new int[t2->GetSize()];
            t2->AddToArrayLNR(t2->GetRoot(), arr2, 0);
            Assert::IsTrue(arr2[0] == 1);

            Assert::IsTrue(t3->GetSize() == 0);

            int* arr4 = new int[t4->GetSize()];
            t4->AddToArrayLNR(t4->GetRoot(), arr4, 0);
            Assert::IsTrue(arr4[0] == 2);
            Assert::IsTrue(arr4[2] == 6);
            Assert::IsTrue(arr4[4] == 12);

        }

        /// <summary>
        /// тест поиска по дереву
        /// </summary>
        TEST_METHOD(Test_Find)
        {
            BSTree <int>* t1 = new BSTree<int>();
            BSTree <int>* t2 = new BSTree<int>();
            BSTree <int>* t3 = new BSTree<int>();
            BSTree <int>* t4 = new BSTree<int>();
            BSTree <int>* t5 = new BSTree<int>();
            BSTree <int>* t6 = new BSTree<int>();
            Generate(t1, t2, t3, t4, t5, t6);

            // искомое значение
            int x = 5;
            Assert::IsTrue(t1->Find(t1->GetRoot(), x) != nullptr);
            x = 40;
            Assert::IsTrue(t1->Find(t1->GetRoot(), x) != nullptr);
            x = 7;
            Assert::IsTrue(t1->Find(t1->GetRoot(), x) == nullptr);

            x = 1;
            Assert::IsTrue(t2->Find(t2->GetRoot(), x) != nullptr);
            x = -2;
            Assert::IsTrue(t2->Find(t2->GetRoot(), x) == nullptr);

            
            x = 1;
            Assert::IsTrue(t3->Find(t3->GetRoot(), x) == nullptr);

            x = 2;
            Assert::IsTrue(t4->Find(t4->GetRoot(), x) != nullptr);
            x = 15;
            Assert::IsTrue(t4->Find(t4->GetRoot(), x) != nullptr);
            x = 6;
            Assert::IsTrue(t4->Find(t4->GetRoot(), x) != nullptr);
            x = 116;
            Assert::IsTrue(t4->Find(t4->GetRoot(), x) == nullptr);

            x = 2;
            Assert::IsTrue(t5->Find(t5->GetRoot(), x) != nullptr);
            x = 20;
            Assert::IsTrue(t5->Find(t5->GetRoot(), x) != nullptr);

            x = 0;
            Assert::IsTrue(t6->Find(t6->GetRoot(), x) != nullptr);
            x = 1;
            Assert::IsTrue(t6->Find(t6->GetRoot(), x) != nullptr);
            x = 3;
            Assert::IsTrue(t6->Find(t6->GetRoot(), x) == nullptr);
        }

        TEST_METHOD(Test_Successor)
        {
            BSTree <int>* t1 = new BSTree<int>();
            BSTree <int>* t2 = new BSTree<int>();
            BSTree <int>* t3 = new BSTree<int>();
            BSTree <int>* t4 = new BSTree<int>();
            BSTree <int>* t5 = new BSTree<int>();
            BSTree <int>* t6 = new BSTree<int>();
            Generate(t1, t2, t3, t4, t5, t6);

            int y = 5;
            Assert::IsTrue((t1->Successor(t1->GetRoot(), y))->GetData() == 10);
            y = 30;
            Assert::IsTrue((t1->Successor(t1->GetRoot(), y))->GetData() == 40);
            y = 40;
            Assert::IsTrue((t1->Successor(t1->GetRoot(), y)) == nullptr);
            y = 999;
            Assert::IsTrue((t1->Successor(t1->GetRoot(), y)) == nullptr);

            y = 1;
            Assert::IsTrue((t2->Successor(t2->GetRoot(), y)) == nullptr);

            y = 5;
            Assert::IsTrue((t3->Successor(t3->GetRoot(), y)) == nullptr);

            y = 5;
            Assert::IsTrue((t4->Successor(t4->GetRoot(), y))->GetData() == 6);
            y = 6;
            Assert::IsTrue((t4->Successor(t4->GetRoot(), y))->GetData() == 10);
            y = 10;
            Assert::IsTrue((t4->Successor(t4->GetRoot(), y))->GetData() == 12);
            y = 12;
            Assert::IsTrue((t4->Successor(t4->GetRoot(), y))->GetData() == 15);

            y = 5;
            Assert::IsTrue((t5->Successor(t5->GetRoot(), y))->GetData() == 10);
            y = 10;
            Assert::IsTrue((t5->Successor(t5->GetRoot(), y))->GetData() == 15);

        }


        TEST_METHOD(Test_Delete)
        {
            BSTree <int>* A = new BSTree<int>();
            A->Insert(50);
            A->Insert(30);
            A->Insert(5);
            A->Insert(0);
            A->Insert(-15);
            A->Insert(-2);
            A->Insert(45);

            int x = 0;
            A->DeleteNode(A->GetRoot(), x);
            
            Assert::IsTrue(A->Find(A->GetRoot(), x) == nullptr);
        }
    };
}