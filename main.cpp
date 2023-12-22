#include <iostream>
#include <string>
using namespace std;

class Container
{
public:
    Container() {}
    virtual ~Container() {}
    virtual void push(int) = 0;
    void abc() {cout << "hello" << endl; }
    virtual void pop() = 0;
    virtual void show() = 0;
};

class Stack : public Container
{
    int *tab;
    int nb;
    int index;

public:
    Stack() : tab(NULL), nb(0), index(0) {}
    Stack(int nb)
    {
        this->nb = nb;
        tab = new int[nb];
        index = 0;
    }
    ~Stack()
    {
        this->abc();
        delete[] tab;
    }
    bool isFull()
    {
        return (index == nb);
    }
    bool isEmpty()
    {
        this->abc();
        return (index == 0);
    }
    virtual void push(int n)
    {
        if (isFull())
        {
            cout << "Stiva este plina !!" << endl;
            return;
        }
        tab[index++] = n;
        cout << "Success !!" << endl;
    }
    virtual void pop()
    {
        if (isEmpty())
        {
            cout << "Stiva este goala !!" << endl;
            return;
        }
        // Modificare aici pentru a decrementa index în loc de a-l incrementa
        cout << "Elementul extras: " << tab[--index] << endl;
        cout << "Success !!" << endl;
    }
    virtual void show()
    {
        int i = -1;
        if (isEmpty())
        {
            cout << "Stiva este goala !!" << endl;
            return;
        }
        while (++i < index)
            cout << tab[i] << " ";
        cout << endl;
    }
};

class Queue : public Container
{
    int *tab;
    int index;
    int max_elem;
    int first_elem;

public:
    Queue() : tab(NULL), index(0), max_elem(0), first_elem(0) {}
    Queue(int n)
    {
        tab = new int[n];
        max_elem = n;
        index = 0;
        first_elem = 0;
    }
    ~Queue()
    {
        delete[] tab;
    }
    bool isFull()
    {
        return (index >= max_elem);
    }
    bool isEmpty()
    {
        return (first_elem == index);
    }
    virtual void push(int n)
    {
        if (isFull())
        {
            cout << "Coada este plina !!" << endl;
            return;
        }
        tab[index++] = n;
        cout << "Success !!" << endl;
    }
    virtual void pop()
    {
        if (isEmpty())
        {
            cout << "Coada este goala !!" << endl;
            return;
        }
        // Modificare aici pentru a utiliza first_elem pentru a extrage elementul corect
        cout << "Elementul extras: " << tab[first_elem++] << endl;
        cout << "Success !!" << endl;
    }
    virtual void show()
    {
        int i = first_elem;
        if (isEmpty())
        {
            cout << "Coada este goala !!" << endl;
            return;
        }
        while (i < index)
        {
            cout << tab[i] << " ";
            i++;
        }
        cout << endl;
    }
};

int main()
{
    Container *cont;
    Container *cc1;
    Container **cc2 = new Container *[4];


    int ch;
    int n;
    cout << "[1]. Crearea unei Stive." << endl;
    cout << "[2]. Crearea unei Cozi." << endl;
    cout << "[0]. Exit." << endl;
    cin >> ch;
    if (ch == 0)
        return (0);
    if (ch == 1)
    {
        cout << "Cite elemente?" << endl;
        cin >> n;
        cont = new Stack(n);
    }
    if (ch == 2)
    {
        cout << "Cite elemente?" << endl;
        cin >> n;
        cont = new Queue(n);
    }
    while (1)
    {
        system("cls");
        cout << "[1]. Push." << endl;
        cout << "[2]. Pop." << endl;
        cout << "[3]. Show." << endl;
        cout << "[0]. Exit" << endl;
        cin >> ch;
        if (ch == 0)
            return (0);
        if (ch == 1)
        {
            cout << "Input >> ";
            cin >> n;
            cont->push(n);
        }
        if (ch == 2)
            cont->pop();
        if (ch == 3)
            cont->show();
    }
    return (0);
}
