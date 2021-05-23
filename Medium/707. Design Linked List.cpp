// https://leetcode.com/problems/design-linked-list/

class LinkedListNode
{
public:
    int val;
    LinkedListNode *next;

    LinkedListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }

    LinkedListNode(int val, LinkedListNode *next)
    {
        this->val = val;
        this->next = next;
    }
};

class MyLinkedList
{
    LinkedListNode *head;
    LinkedListNode *tail;
    int size;

public:
    MyLinkedList()
    {
        head = tail = nullptr;
        size = 0;
    }

    int get(int index)
    {
        if (size <= index)
            return -1;

        LinkedListNode *current = head;

        while (index--)
            current = current->next;

        return current->val;
    }

    void addAtHead(int val)
    {
        LinkedListNode *node = new LinkedListNode(val);

        if (size == 0)
        {
            head = tail = node;
        }

        else
        {
            node->next = head;
            head = node;
        }

        size++;
    }

    void addAtTail(int val)
    {
        LinkedListNode *node = new LinkedListNode(val);

        if (size == 0)
        {
            head = tail = node;
        }

        else
        {
            tail->next = node;
            tail = node;
        }

        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (size < index)
            return;

        LinkedListNode *node = new LinkedListNode(val);
        LinkedListNode *current = head;

        if (size == index)
            addAtTail(val);

        else if (index == 0)
            addAtHead(val);

        else
        {
            index -= 1;
            while (index--)
                current = current->next;

            LinkedListNode *temp = current->next;
            current->next = node;
            node->next = temp;
            size++;
        }
    }

    void deleteAtIndex(int index)
    {
        if (size <= index)
            return;

        LinkedListNode *current = head;

        if (index == 0)
        {
            LinkedListNode *temp = head->next;
            tail = (tail == head) ? temp : tail;
            delete head;

            head = temp;
        }

        else
        {
            index -= 1;

            while (index--)
                current = current->next;

            LinkedListNode *deletedNode = current->next;
            current->next = deletedNode->next;

            if (tail == deletedNode)
                tail = current;

            delete deletedNode;
        }

        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */