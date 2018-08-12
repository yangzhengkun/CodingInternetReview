//
// Created by yangzhengkun on 2018/8/12.
//
#include <iostream>
#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    explicit ListNode(int value) : val(value), next(nullptr)
    {}
};

void PrintListReversingly_Iteratively(const ListNode *head)
{
    if (head == nullptr)
        return;
    stack<int> stack1;
    while (head)
    {
        stack1.emplace(head->val);
        head = head->next;
    }
    while (!stack1.empty())
    {
        cout << stack1.top() << " ";
        stack1.pop();
    }
}


void PrintListReversingly_Recursively(const ListNode *head)
{
    if (head == nullptr)
        return;
    if (head->next)
        PrintListReversingly_Recursively(head->next);
    cout << head->val << " ";
}

int main()
{
    ListNode head = ListNode(1);
    auto node2 = new ListNode(2);
    auto node3 = new ListNode(3);
    head.next = node2;
    node2->next = node3;
    PrintListReversingly_Recursively(&head);
    cout << endl;
    PrintListReversingly_Iteratively(&head);
    cout << endl;

    return 0;

}