#include <iostream>
//#include <bits/sdtc++.h>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* remove_last_occurrences(ListNode* head) {
    if(head==NULL){
        return head;
    }
    unordered_map<int,ListNode*>m;
    ListNode*c=head;
    while(c!=NULL){
        m[c->val]=c;
        c=c->next;
    }
    c=head;
    ListNode*d=new ListNode(0);
    d->next=head;
    ListNode*prev=d;
    while(c!=NULL){
        if(m[c->val]==c){
            prev->next=c->next;
            delete c;
            c=prev->next;
        }
        else{
            prev=c;
            c=c->next;
        }
    }
    // Write your logic here to remove the last occurrence of all elements in the linked list.
    return d->next;
}

void print_linked_list(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << endl;
        return 0;
    }

    ListNode* head = NULL;
    ListNode* current = NULL;

    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        ListNode* new_node = new ListNode(value);
        if (head == NULL) {
            head = new_node;
            current = head;
        } else {
            current->next = new_node;
            current = current->next;
        }
    }

    // Call user logic function
    ListNode* modified_head = remove_last_occurrences(head);

    // Print the modified linked list
    print_linked_list(modified_head);

    return 0;
}
