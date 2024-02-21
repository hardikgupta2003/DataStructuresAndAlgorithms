#include<iostream>
using namespace std;

class Queues{
    public:
    int front;
    int rear;
    int *arr;
    int size;

    Queues(int size){
        this->size=size;
        arr=new int[size];
        rear=-1;
        front=-1;
    }

    void push(int data){
        if(rear==size-1){
            cout<<"overflow hogaya jii"<<endl;
        }
        else if(front==-1 && rear==-1){
            //queue empty hai
            front++;
            rear++;
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
        }
        else if(front==rear){
            arr[front]=-1;
            front--;
            rear--;
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
    void getRear(){
        if(rear!=-1 && arr[rear]!=-1){
            cout<<"rear : "<<arr[rear]<<endl;
        }
        else{
            cout<<"UnderFlow conditons"<<endl;
        }
    }
    void printQ(){
        cout<<"printing : ";
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};



int main(){
    Queues q(5);
    q.printQ();
    q.push(7);
    q.push(8);
    q.push(8);
    q.push(8);
    q.push(8);
    q.printQ();
    q.getRear();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.printQ();


    return 0;
}