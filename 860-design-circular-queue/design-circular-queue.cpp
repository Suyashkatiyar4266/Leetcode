class MyCircularQueue {
private:
    vector<int> queue;
    int rear;
    int front;
    int max_size;
public:
    MyCircularQueue(int k) {
        front=-1;
        rear=-1;
        max_size=k;
        queue.resize(k);
    }
    
    bool enQueue(int value) {
        if((rear+1)%max_size==front){
            return false;
        }
        else if(rear==-1){
            rear=front=0;
        }
        else{
            rear=(rear+1)%max_size;
        }
        queue[rear]=value;
        return true;
    }
    
    bool deQueue() {
        if(front==-1){
            return false;
        }
        else if(front==rear)//one element case
        {
            rear=front=-1;
        }
        else
        {
            front=(front+1)%max_size;
        }
        return true;
    }
    
    int Front() {
    if(front == -1)
        return -1;
    return queue[front];
}
    int Rear() {
    if(rear == -1)
        return -1;
    return queue[rear];
}
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
    return (rear + 1) % max_size == front;
}
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */