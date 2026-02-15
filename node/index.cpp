template <typename T>
class Node {
    private:
        T data;
        Node* next;
        
    public:
        Node(T data) {
            this->data = data;
            next = nullptr;
        }
        
        T* getData() {
            return &data;
        }
        
        Node* getNext() {
            return next;
        }
        
        void setNext(Node* n) {
            next = n;
        }
};
