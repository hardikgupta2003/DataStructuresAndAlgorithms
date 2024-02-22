//implementaion using array

#include<iostream>
using namespace std;

class CQueues{
    int front;
    int rear;
    int *arr;
    int size;

    public:
    CQueues(int size){
        this->size=size;
        arr=new int[size];
        rear=-1;
        front=-1;
    }

    void push(int data){
        if(rear==size-1 && front==0 || (rear==front-1)){
            cout<<"overflow hogaya jii"<<endl;
            return;
        }
        else if(front==-1 && rear==-1){
            //queue empty hai
            front++;
            rear++;
            arr[rear]=data;
        }
        else if(rear==size-1 && front!=0){
            rear=0;
            arr[rear]=data;
        
        }
        else{
            rear++;
            arr[rear]=data;
        }
    }

    void pop(){
        if(front==-1 && rear==-1){
            cout<<"UnderFlow hogaya jii"<<endl;
            return;
        }
        else if(front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
        }
        else if(front==size-1 ){
            arr[front]=-1;
            front=0;
        }
        else {
            arr[front]=-1;
            front++;
        }
    }

    int getSize(){
        if(front==-1 && rear==-1){
            return 0;
        }
        else{
            return rear-front+1;
        }
    }
    int getRear(){
       if(rear==-1){
        cout<<"Queue is Empty!"<<endl;
        return -1;
       }
       return arr[rear];
    }
    int getFront(){
        if(front==-1){
            cout<<"No element in theQueues "<<endl;
        }
        else
            return arr[front];
    }
    void print(){
        cout<<"printing : ";
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};



int main(){
    CQueues q(5);
    q.push(2);
    q.push(12);
    q.push(98);
    q.push(6);
    q.push(5);
    q.print();
    q.pop();
    q.print();
    cout<<"Size of the Queue is : "<<q.getSize()<<endl;
    q.push(89);
    // cout<<"Size of the Queue is : "<<q.getSize()<<endl;
    q.print();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.print();
    // // q.push(45);
    cout<<"The front element of queue is: "<<q.getFront()<<endl;
    cout<<"The rear element of queue is: "<<q.getRear()<<endl;


    return 0;
}