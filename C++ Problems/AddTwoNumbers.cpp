#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode();
        ListNode* temp = sum;

        int total = 0, carry_val = 0;
        
        while(l1 || l2 || carry_val)
        {
            total = carry_val;

            if (l1)
            {
                total += l1->val;
                l1 = l1->next;
            }

            if(l2)
            {
                total += l2->val;
                l2 = l2->next;
            }
            
            int base_val = total % 10;
            carry_val = total / 10;

            sum->next = new ListNode(base_val);
            sum = sum->next;
        }

        ListNode* result = temp->next;
        delete temp;
        return result;
    }
};

int main()
{
    ListNode* l1 = new ListNode(9, new ListNode(9, new ListNode(9) ) );

    ListNode* l2 = new ListNode(4, new ListNode(6, (new ListNode(5) ) ) );

    Solution s;
    ListNode* solution_node = s.addTwoNumbers(l1, l2);

    cout << "[ ";
    while(solution_node != nullptr)
    {
        cout << solution_node->val << " ";
        solution_node = solution_node->next;
    }
    cout << "]";

    return 0;
}