class MyLinkedList {
    public:
        struct ListNode
        {
            int val;
            ListNode* next;
            ListNode(int val):val(val), next(nullptr){}
        };

        MyLinkedList() {
            fakeHead = new ListNode(0);
            size = 0;
        }
        
        int get(int index) {
            
        }
        
        void addAtHead(int val) {
            
        }
        
        void addAtTail(int val) {
            
        }
        
        void addAtIndex(int index, int val) {
            
        }
        
        void deleteAtIndex(int index) {
            
        }
    private:
        int size;
        ListNode * fakeHead;
};