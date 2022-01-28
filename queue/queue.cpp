#include <iostream>

using namespace std;

class Queue{
    public:
        int count;
        int rear;
        int front;
        int capacity;
        int* arr;

        Queue(int n){
            arr = new int[n];
            capacity = n;
            count = 0;
            rear = -1;
            front = 0;
        }

        void enqueue(int n){
            if(isFull()){
                cout<<"Queue is full !\n";
                exit(EXIT_FAILURE);
            }

            rear = (rear + 1) % capacity;
            arr[rear] = n;
            count++;
        }   

        void dequeue(){
            
            isEmpty();

            front = (front + 1) % capacity;
            count--;
        }


        void describe(){

            checkEmpty();

            cout<<"Count = "<<count<<" / Rear = "<<rear<<" / Front = "<<front<<endl;
            if(front <= rear){

                for(int i = front ; i <= rear ; i++){
                    cout<<arr[i]<<"\n";
                }

            }

            else {

                for(int i = front ; i < capacity ; i++){
                    cout<<arr[i]<<endl;
                }

                for(int j = 0 ; j <= rear ; j++){
                    cout<<arr[j]<<endl;
                }

            }
        }

        void checkEmpty(){
            if(isEmpty()){
                cout<<"Queue is Empty !\n";
                exit(EXIT_FAILURE);
            }
        }

        bool isFull(){
            return count == capacity;
        }

        bool isEmpty(){
            return count == 0;
        }
};

int main(){
    Queue queue(5);

    queue.enqueue(5);    
    queue.enqueue(3);    
    queue.enqueue(5);
    queue.dequeue();
    queue.enqueue(7);
    queue.dequeue();
    queue.enqueue(8);
    queue.enqueue(9);
    queue.enqueue(10);

    // queue.enqueue(5);    
    // queue.dequeue();      

 
    // queue.enqueue(11);




    queue.describe();

    return 0;
}

