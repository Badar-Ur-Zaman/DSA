/*
Description:
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.
*/ 

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode * ptr = head;
        while(ptr){
            ptr = ptr->next;
            count++;
        }
        double middle;
        if(count %2 == 0){
            middle = ceil(static_cast<double>(count)/2);
        }else{
            middle = floor(static_cast<double>(count)/2);
        }
        count = 0;
        ptr = head;
        ListNode * newNode = nullptr;
        while(ptr){
            if(count == middle){
                newNode = ptr;
                break;
            }
            ptr = ptr->next;
            count ++;
        }
        return newNode;
    }
};
