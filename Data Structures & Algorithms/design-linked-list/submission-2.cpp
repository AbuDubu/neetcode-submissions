class MyLinkedList {

    struct ListNode {
        int val {};
        ListNode* prev {nullptr};
        ListNode* next {nullptr};

        ListNode(int val = 0, ListNode* prev = nullptr, ListNode* next = nullptr) : val(val), prev(prev), next(next) {}

    };

    ListNode* head {nullptr};
    ListNode* tail {nullptr};
    int size {0};

public:
    MyLinkedList() {
        
    }
    
    int get(int index) {
        if (index >= size or index < 0) {
            return -1;
        }

        ListNode* curr = head;
        for (int i {0}; i < index; i++) {
            curr = curr->next;
        }

        return curr->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode {new ListNode(val)};
        if (size == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
        
    }
    
    void addAtTail(int val) {
        ListNode* newNode {new ListNode(val)};
        if (size == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size or index < 0) {
            return;
        }
        
        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == size) {
            addAtTail(val);
            return;
        }

        ListNode* curr = head;
        for (int i {0}; i < index; i++) {
            curr = curr->next;
        }

        ListNode* newNode {new ListNode(val)};
        newNode->prev = curr->prev;
        newNode->next = curr;

        curr->prev->next = newNode;
        curr->prev = newNode;

        size++;

    }
    
    void deleteAtIndex(int index) {
        if (index >= size or index < 0) {
            return;
        }

        ListNode* curr = head;
        for (int i {0}; i < index; i++) {
            curr = curr->next;
        }

        ListNode* prev {curr->prev};
        ListNode* next {curr->next};

        if (prev) {
            prev->next = next;
        } else {
            head = next;
        }

        if (next) {
            next->prev = prev;
        } else {
            tail = prev;
        }

        delete curr;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */