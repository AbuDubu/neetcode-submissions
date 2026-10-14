class LinkedList {
    struct Node {
        int val {0};
        Node* next {nullptr};
        Node(int v, Node* n) : val(v), next(n) {}
    };

    Node* mHead {nullptr};
    Node* mTail {nullptr};

public:
    LinkedList() {
        mHead = new Node(0, nullptr);
        mTail = mHead;
    }

    int get(int index) {
        Node* curr = mHead->next;
        int i = 0;

        while (curr != nullptr){
            if (i == index){
                return curr->val;
            }

            i++;
            curr = curr->next;
        }

        return -1;
    }

    void insertHead(int val) {
        mHead->next = new Node(val, mHead->next);

        if(mHead->next->next == nullptr){
            mTail = mHead->next;
        }
    }
    
    void insertTail(int val) {
        mTail->next = new Node(val, nullptr);
        mTail = mTail->next;

    }

    bool remove(int index) {
        int i = 0;
        Node* curr = mHead;
        
        while(curr != nullptr and curr->next != nullptr){
            if (i == index) {
                Node* nodeToDelete = curr->next;
                if (nodeToDelete == mTail) {
                    mTail = curr;
                }
                curr->next = curr->next->next;

                delete nodeToDelete;
                return true;
            }

            i++;
            curr = curr->next;
        }

        return false;
        
    }

    vector<int> getValues() {
        vector<int> vals {};

        Node* curr = mHead->next;

        while (curr != nullptr){
            vals.push_back(curr->val);
            curr = curr->next;
        }

        return vals;
        
    }
};