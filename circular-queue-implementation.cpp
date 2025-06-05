#include<iostream>
#include<limits>
class circularQueue{
    private:
        int rear;
        int front;
        int count;
        int size = 5;
        int* arr = new int[size];
    public:
        circularQueue(){
            rear = -1;
            front = -1;
            count = 0;
            for(int i=0;i<size;i++){
                arr[i] = 0;
            }
        }
        ~circularQueue(){
            delete[] arr;
        }
        bool isEmpty(){
            if(rear == -1 && front == -1){
                return true;
            }
            return false;
        }
        bool isFull(){
            if((rear + 1)%size ==  front){
                return true;
            }
            return false;
        }
        void enqueue(int value){
            if(isFull()){
                std::cout<< "The queue is full"<<std::endl;
                return;
            }
            else if(isEmpty()){
                rear = 0;
                front = 0;
            }
            else{
                rear = (rear + 1)%size;
            }
            arr[rear] = value;
            count++;
        }
        int dequeue(){
            int temp;
            if(isEmpty()){
                std::cout<< "The queue is empty"<<std::endl;
                return -1;
            }
            else if(rear == front){
                temp  = arr[front];
                front = -1;
                rear = -1;
            }
            else{
                temp = arr[front];
                front = (front + 1)%size;
            }
            count--;
            return temp;
        }
        int Count(){
            return count;
        }
        void display(){
            std::cout<< "Queue: ";
            int i = front;
            while(i != rear){
                std::cout<< arr[i] << "\t";
                i = (i+1)%size;
            }
            std::cout<< arr[rear]<<std::endl;
        }
        void resize(){
            int newSize = size * 2;
            int* newArr = new int[newSize];
            for(int i=0;i<size;i++){
                newArr[i] = arr[i];
            }
            for(int i=size;i<newSize;i++){
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            size = newSize;
        }
        int peek(){
            return arr[front];
        }
        void reverse(){
            if(isEmpty()){
                std::cout<< "the queue is empty "<<std::endl;
                return;
            }
            int start = front;
            int end = rear;
            int temp;
            if(rear>front){
                while(start<end){
                    temp  = arr[start];
                    arr[start] = arr[end];
                    arr[end] = temp;
                    start++;
                    end--;
                }
            }
            else{
                if(count%2==0){
                    while((start+1)%size != end){
                        temp = arr[end];
                        arr[end]= arr[start];
                        arr[start] = temp;
                        end = ((size - 1) +  end)%size;
                        start = (start + 1)%size;
                    }
                }
                else if(count%2 == 1){
                    while(start!=end){
                        temp = arr[end];
                        arr[end]= arr[start];
                        arr[start] = temp;
                        end = ((size - 1) +  end)%size;
                        start = (start + 1)%size;
                    }
                }
            }
        }
};
void reverseQueue(circularQueue* q1){
    circularQueue* q3 = new circularQueue;
    int count= q1->Count();
    int size= q1->Count();
    int temp;
    while(count>0){
        for(int i=1;i<size;i++){
            q1->enqueue(q1->dequeue());
        }
        q3->enqueue(q1->peek());
        count--;
    }
    while(!q1->isEmpty()){
        q1->dequeue();
    }
    while(!q3->isEmpty()){
        q1->enqueue(q3->dequeue());
    }
    delete q3;
}
int valid(int num){
    while(true){
        std::cin>>num;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<< "Invalid input! Please try again"<<std::endl;
        }
        else{
            return num;
        }
    }
}
int main(){
    circularQueue q1;
    int op,value;
    bool leave = false;
    while(leave == false){
        std::cout<< "#############################operations###########################"<<std::endl;
        std::cout<< "1.is the queue Empty?\n2.Is the queue full?\n3.Enqueue\n4.Dequeue\n5.Element count\n6.Display the queue\n7.Resize the queue\n8.Peek the front value\n9.Reverse\n10.Reverse using temporary Queue\n11.Exit"<<std::endl;
        std::cout<< "Enetr the numebr of opertion"<<std::endl;
        op = valid(op);
        while(op>11 || op<1){
            std::cout<< "Invalid numebr of opeartion! please try again"<<std::endl;
            op = valid(op);
        }
        switch(op){
            case 1:
                std::cout<< "Is the queue empty? "<<q1.isEmpty()<<std::endl;
                break;
            case 2:
                std::cout<< "Is the queue Full? "<<q1.isFull()<<std::endl;
                break;
            case 3:
                std::cout<< "Enter the value you want to enqueue"<<std::endl;
                value = valid(value);
                q1.enqueue(value);
                break;
            case 4:
                value = q1.dequeue();
                if(value!= -1){
                    std::cout<< "You have dequeued the value "<< value <<std::endl;
                }
                break;
            case 5:
                std::cout<< "The number of elements in the queue is "<<q1.Count()<<std::endl;
                break;
            case 6:
                q1.display();
                break;
            case 7:
                q1.resize();
                std::cout<< "You have successfully  resized the queue"<<std::endl;
                break;
            case 8:
                std::cout<< "The value you have peeked for is  "<<q1.peek()<<std::endl;
                break;
            case 9:
                q1.reverse();
                break;
            case 10:
                reverseQueue(&q1);
                break;
            case 11:
                leave = true;
                std::cout<< "Bye!"<<std::endl;
                break;
        }
    }
    return 0;
}