#include <iostream>
using namespace std;
#define max_size 4
int cqueue[max_size];

class circular_queue
{
    int front;
    int rear;

public:
    circular_queue()
    {
        front = -1;
        rear = -1;
    }

    void insert(int x)
    {
        if ((rear + 1) % max_size == front)
        {
            cout << "overflow" << endl;
        }
        else
        {
            rear++;
            if (rear == max_size)
            {
                rear = 0;
            }

            cqueue[rear] = x;
        }
        if (front == -1)
        {
            front = 0;
        }
    }
    void cqdelete()
    {
        int temp = front;
        if (front == -1)
        {
            cout << "Queue Underflow" << endl;
            return; // if true so further will check no more condition
        }

        if (front == rear) // if only one Element exist in cir. queue
        {
            front = -1;
            rear = -1;
        }
        else
        {
            if (front == max_size)
            {
                front = 0;
            }
            else
                front++;
        }
        cout << "Element deleted from queue is : " << cqueue[temp] << endl;
    }

    void display()
    {
        int f = front, r = rear; // better use f and r so even if further maniuplated it does not effect our front and rear
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return; // if true so further will check no more conditon
        }
        cout << "Queue elements are :\n";

        if (f <= r)
        {
            while (f <= r)
            {
                cout << cqueue[f] << " ";
                f++;
            }
        }
        else
        {
            int temp = f; // as we need to display left elements first than right elements
            f = 0;        // so front can now point to start and print elements till rear
            while (f <= r)
            {
                cout << cqueue[f] << " ";
                f++;
            }
            while (temp <= max_size - 1) // or < max_size
            {
                cout << cqueue[temp] << " ";
                temp++;
            }
        }
    }

    void search(int target)
    {
        int f = front, r = rear;
        int count = 1; // taking count from 1 and whenever inc. front++ we inc. count++ so if even after traverse through whole queue we could'nt able to find element than count will be more than max size so we can conclude at end if count > max_size than element not exist
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        if (f <= r)
        {
            while (f <= r)
            {
                if (cqueue[f] == target)
                {
                    cout << "position of your target element is : " << f << endl;
                    break;
                }
                f++;
                count++;
            }
        }

        else
        {
            int temp = f;
            f = 0;
            while (f <= r)
            {
                if (cqueue[f] == target)
                {
                    cout << "position of your target element is : " << f << endl;
                    break;
                }
                f++;
                count++;
            }
            while (temp <= max_size - 1) // or < max_size
            {
                if (cqueue[temp] == target)
                {
                    cout << "position of your target element is : " << temp << endl;
                    break;
                }
                temp++;
                count++;
            }
            if (count > max_size) // count > no. of elements
            {
                cout << "that element not exists in circular queue" << endl;
                return;
            }
        }
    }

    void change(int target_positon, int new_val)
    {
        int f = front, r = rear;
        if (front == -1)
        {
            cout << "empty queue" << endl;
            return;
        }
        if (f <= r)
        {
            while (f <= r)
            {
                if (f == target_positon)
                {
                    cqueue[f] = new_val;
                    cout << "new value " << new_val << " is inserted at " << f << " position" << endl;
                    return;
                }
                f++;
            }
        }
        else
        {
            int temp = f;
            f = 0;
            while (f <= r)
            {
                if (f == target_positon)
                {
                    cqueue[f] = new_val;
                    cout << "new value " << new_val << " is inserted at " << f << " position" << endl;
                    return;
                }
                f++;
            }
            while (temp <= max_size - 1)
            {
                if (temp == target_positon)
                {
                    cqueue[temp] = new_val;
                    cout << "new value " << new_val << " is inserted at " << temp << " position" << endl;
                    return;
                }
                temp++;
            }
        }
    }
};

int main()
{
    circular_queue obj;
    int n, x, target, z, new_val;
    do
    {
        cout << "enter 1 to insert" << endl;
        cout << "enter 2 to delete" << endl;
        cout << "enter 3 to search" << endl;
        cout << "enter 4 to change" << endl;
        cout << "enter 5 to display" << endl;
        cout << "enter 6 to exit" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "enter value to be inserted" << endl;
            cin >> x;
            obj.insert(x);
            break;
        case 2:
            cout << "element is deleted" << endl;
            obj.cqdelete();
            break;
        case 3:
            cout << "enter positon of element to search " << endl;
            cin >> target;
            obj.search(target);
            break;
        case 4:
            cout << "enter positon to change " << endl;
            cin >> z;
            cout << "enter new value to be changed at that positon" << endl;
            cin >> new_val;
            obj.change(z, new_val);
            break;
        case 5:
            obj.display();
            break;

        default:
            break;
        }

    } while (n < 6);
}