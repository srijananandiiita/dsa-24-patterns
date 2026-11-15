// ============================================================================
// Template 4: Fast and Slow (Tortoise and Hare) - Linked Lists & Cycles
// When to Use:
//   - Detecting cycles in a Linked List or functional graph
//   - Finding the middle node of a Linked List in a single pass
//   - Finding the duplicate number in an array of [1..n] (Floyd's Cycle Detection)
// Time Complexity: O(n)
// Space Complexity: O(1)
// ============================================================================

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 1. Find the middle of a linked list
ListNode* findMiddleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // When fast reaches the end, slow will be right at the middle
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;       // 1 step
        fast = fast->next->next; // 2 steps
    }
    return slow;
}

// 2. Detect if a cycle exists and return the cycle entry node (or nullptr)
ListNode* detectCycleStart(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        // Cycle detected!
        if (slow == fast) {
            // Reset one pointer to head; advance both by 1 step to find cycle entrance
            ListNode* entry = head;
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry;
        }
    }
    return nullptr; // No cycle
}

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    n1->next = n2;
    n2->next = n3;

    cout << "Middle Node Value: " << findMiddleNode(n1)->val << endl;
    return 0;
}
