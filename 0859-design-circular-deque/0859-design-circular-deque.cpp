class MyCircularDeque {
public:
    int *arr;
    int size;
    int front;
    int rear;
    MyCircularDeque(int k) {
        size=k;
        arr=new int[size];
        front=rear=-1;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        else if(isEmpty()) rear=front=0;
        else if(front==0 && rear!=size-1) front=size-1;
        else front--;
        arr[front]=value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        else if(isEmpty()) rear=front=0;
        else if(rear==size-1 && front!=0) rear=0;
        else rear++;
        arr[rear]=value;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        int ans=arr[front];
        arr[front]=-1;
        if(front==rear) front=rear=-1;
        else if(front==size-1) front=0;
        else front++;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        int ans=arr[rear];
        arr[rear]=-1;
        if(front==rear) front=rear=-1;
        else if(rear==0) rear=size-1;
        else rear--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        if(front==-1) return true;
        else return false;
    }
    
    bool isFull() {
        if (size == 0) return false;
        return (front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */