//#include <iostream>
//#include <string>
//
//using namespace std;
//
//struct Node
//{
//    int Data;
//    Node* NextNode;
//
//    Node(int NewData) : Data(NewData), NextNode(nullptr) {}
//};
//
//class MyStack
//{
//public:
//    Node* Top;
//
//    MyStack() : Top(nullptr) {}
//    ~MyStack()
//    {
//        while (Top != nullptr)
//        {
//            Pop();
//        }
//    }
//
//    void Push(int X)
//    {
//        Node* NewNode = new Node(X);
//        NewNode->NextNode = Top;
//        Top = NewNode;
//    }
//
//    void Pop()
//    {
//        if (!IsEmpty())
//        {
//            Node* DeleteTarget = Top;
//            Top = Top->NextNode;
//            delete DeleteTarget;
//        }
//    }
//
//    int Size()
//    {
//        int Count = 0;
//        Node* Current = Top;
//        while (Current != nullptr)
//        {
//            Count++;
//            Current = Current->NextNode;
//        }
//        return Count;
//    }
//
//    bool IsEmpty()
//    {
//        return (Top == nullptr);
//    }
//
//    void PrintTop()
//    {
//        if (!IsEmpty())
//        {
//            cout << Top->Data << '\n';
//        }
//        else
//        {
//            cout << "-1" << '\n';
//        }
//    }
//};
//
//int main()
//{
//    MyStack Stack;
//
//    int N;
//    cin >> N;
//
//    for (int i = 0; i < N; ++i)
//    {
//        int Order;
//        int X;
//
//        cin >> Order;
//
//        if (Order == 1)
//        {
//            cin >> X;
//            Stack.Push(X);
//        }
//        else if (Order == 2)
//        {
//            Stack.Pop();
//        }
//        else if (Order == 3)
//        {
//            cout << Stack.Size() << '\n';
//        }
//        else if (Order == 4)
//        {
//            cout << Stack.IsEmpty() << '\n';
//        }
//        else
//        {
//            Stack.PrintTop();
//        }
//    }
//
//    return 0;
//}
