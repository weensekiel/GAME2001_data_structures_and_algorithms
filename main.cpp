#include <iostream>

template <class T>
class Node 
{
public:
    int priority;
    T data;
    Node* next;

    Node(int p, T val) : priority(p), data(val), next(nullptr) {}
};

template <class T>
class LinkedList 
{
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    void insertNode(int priority, T data) 
    {
        Node<T>* newNode = new Node<T>(priority, data);

        if (!head || priority < head->priority) 
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node<T>* current = head;
        while (current->next && priority >= current->next->priority) 
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    T pop() 
    {
        if (!head) 
        {
            std::cerr << "Error: Pop() called on an empty list\n";
            exit(EXIT_FAILURE);
        }

        Node<T>* temp = head;
        head = head->next;
        T poppedData = temp->data;
        delete temp;

        return poppedData;
    }

    T front() 
    {
        if (!head)
        {
            std::cerr << "Error: Front() called on an empty list\n";
            exit(EXIT_FAILURE);
        }

        return head->data;
    }
};

template <class T>
class PriorityQueue 
{
private:
    LinkedList<T> list;

public:
    void push(int priority, T data) 
    {
        list.insertNode(priority, data);
    }

    T pop() 
    {
        return list.pop();
    }

    T front() 
    {
        return list.front();
    }
};

int main() 
{
    PriorityQueue<std::string> priorityQueue;

    priorityQueue.push(3, "Prio 3");
    priorityQueue.push(1, "Prio 1");
    priorityQueue.push(4, "Prio 4");
    priorityQueue.push(2, "Prio 2");

    std::cout << "Front: " << priorityQueue.front() << std::endl;

    std::cout << "Pop: " << priorityQueue.pop() << std::endl;
    std::cout << "Pop: " << priorityQueue.pop() << std::endl;

    std::cout << "Front: " << priorityQueue.front() << std::endl;

    return 0;
}
