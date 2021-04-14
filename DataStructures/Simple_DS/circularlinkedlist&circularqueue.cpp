#include <iostream>

using namespace std;
struct Queue {
    static
        const int MAX = 100;
    int array[MAX];
    int Rear = 0;
    int Front = 0;
    int Count = 0;
    void Dequeue() {
        if (Count != 0) {
            array[Front] = NULL;
            Front += 1;
            Count -= 1;
        }
        else {
            cout << "Queue is Empty !!!!" << endl;
        }

    }
    void Enqueue(int value) {

        array[Rear] = value;

        Rear += 1;
        Count += 1;
    }
    void QueuePrinter() {
        int i = Rear - 1;
        for (i; i >= Front; i--) {
            cout << "|" << array[i] << "|";
        }
        cout << endl;
    }
    void ClearQueue() {
        Front = 0;
        Rear = 0;
        Count = 0;

    }
};

class Node {
public:
    int value = 0;
    Node* Next = 0;

};
class LinkedList {
public:
    Node* Front = NULL;
    Node* Rear = NULL;
    int count = 0;
    void Enqueue(int value) {

        Node* NewNode;
        NewNode = new Node();
        NewNode->value = value;
        NewNode->Next = NULL;
        if (Front == NULL && Rear == NULL) {
            Front = NewNode;
            Rear = NewNode;
            Rear->Next = Front;
        }
        else {
            Rear->Next = NewNode;
            Rear = NewNode;
            NewNode->Next = Front;

        }
        count += 1;

    }
    void Dequeue() {
        Node* n = Front;
        if (Front == NULL && Rear == NULL) {
            cout << "Queue is Empty!!!!!" << endl;
        }
        else if (Front == Rear) {
            Front = Rear = NULL;
            free(n);
        }
        else {
            Front = Front->Next;
            Rear->Next = Front;
            free(n);

        }

        count -= 1;
    }
    void LinkedList_Printer() {
        Node* n;
        n = Rear;
        if(Front==NULL&&Rear==NULL){
        }
        else{
            do {
                cout << "|" << n->value << "|";
                n = n->Next;
            } while (n != Rear);
            cout << endl;
        }
       
    }
    void Clear_Queue() {
        Rear = Front = NULL;
        count = 0;
    }

};
void array_handler(void);
void LinkedList_Handler(void);
int main() {
    cout << "Please Choose Your Method for Queue :\n" << "1-Using Arrays\n" << "2-Using LinkedLists : " << endl;
    int Desicion = 0;
    cin >> Desicion;
    switch (Desicion) {
    case 1: {
        array_handler();
        break;
    }
    case 2: {
        LinkedList_Handler();
        break;
    }
    case 3: {

    }
    default:
        break;
    }

}
void array_handler(void) {
    Queue myqueue;
    int Desicion = 0;
    int val;
    bool exit = false;
    while (!exit) {
        cout << "======================================\n";
        cout << "Please Choose : \n" << "1-ENQUEUE\n2-DEQUEUE\n3-CLEAR QUEUE\n0-EXIT\n";
        cout << "======================================\n";
        cin >> Desicion;
        switch (Desicion) {
        case 1: {
            cout << "Please enqueue : " << endl;
            cin >> val;
            myqueue.Enqueue(val);
            myqueue.QueuePrinter();
            break;
        }
        case 2: {
            myqueue.Dequeue();
            myqueue.QueuePrinter();

            break;
        }
        case 3: {
            myqueue.ClearQueue();
            cout << "Queue Cleared Completly !!!" << endl;
            break;
        }
        case 0: {
            exit = true;
            break;
        }
        default:
            break;
        }
    }
}
void LinkedList_Handler(void) {
    LinkedList mylinklist;
    int Desicion = 0;
    int val;
    bool exit = false;
    while (!exit) {
        cout << "======================================\n";
        cout << "Please Choose : \n" << "1-ENQUEUE\n2-DEQUEUE\n3-CLEAR QUEUE\n0-EXIT\n";
        cout << "======================================\n";
        cin >> Desicion;
        switch (Desicion) {
        case 1: {
            cout << "Please enqueue : " << endl;
            cin >> val;
            mylinklist.Enqueue(val);
            mylinklist.LinkedList_Printer();
            break;
        }
        case 2: {
            cout << "Dequeued !! Continue? : " << endl;
            mylinklist.Dequeue();
            mylinklist.LinkedList_Printer();

            break;
        }
        case 3: {
            mylinklist.Clear_Queue();
            cout << "Queue Cleared Completly !!!" << endl;
            break;
        }
        case 0: {
            exit = true;
            break;
        }
        default:
            break;
        }
    }
}