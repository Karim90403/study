#include <iostream>

using namespace std;

class Node
{
  int field;
  class Node *ptr;
  friend class List;
};
class List
{
  Node *head;
  int count = 0;
  Node* previous(Node* node)
    {
      if (isEmpty()) return NULL;
      if (node == head) return NULL;
      Node *p = head;
      while (p->ptr != node)
        p = p->ptr;
      return p;
    }
public:
    List() { head = NULL; }
    int getCount() { return count; }
    bool isEmpty() { return head == NULL; }
    int getValue(Node* p) { return p->field; }
    void setValue(Node *p, int val) { p->field = val; }
    Node* first() { return head; }
    Node* last()
    {
      Node* p = head;
      while (move(p) != NULL)
        p = move(p);
      return p;
    }
    void clear()
    {
      class Node *p = head;
      if (p == NULL) return;
      do {
        Node *d = p;
        p = move(p);
        delete d;
      } while (p != NULL);
      count = 0;
      head = NULL;
    }
    Node* move(Node* node)
    {
      if (isEmpty()) return NULL;
      return node->ptr;
    }
    Node* add(int num, Node* node = NULL)
    {
      Node *elem = new Node();
      elem->field = num;
      count++;
      if (node == NULL) // Добавление нового корня
      {
        if (head == NULL) {
          elem->ptr = NULL;
          head = elem;
        }
        else {
          elem->ptr = head;
          head = elem;
        }
        return elem;
      }
      elem->ptr = node->ptr;
      node->ptr = elem;
      return elem;
    }
    Node* deleteElement(Node* node)
    {
      if (node == NULL) { return NULL; }
      count--;
      if (node == head)
      {
        head = node->ptr;
        delete node;
        return head;
      }
      Node* prev = previous(node);
      prev->ptr = node->ptr;
      delete node;
      return prev;
    }

    void printList()
    {
      if (isEmpty()) { cout << "Список пуст" << endl; return; }
      Node *p = head;
      do {
        cout << getValue(p) << " ";
        p = move(p);
      } while (p != NULL);
      cout << endl;
    }
    void swap(Node* node1, Node* node2)
    {
      if (node1 == NULL || node2 == NULL) return;
      if (node1 == node2) return;
      if (node2->ptr == node1)
      {
        Node *p = node1;
        node1 = node2;
        node2 = p;
      }
      Node *prev1 = previous(node1);
      Node *prev2 = previous(node2);
      Node *next1 = move(node1);
      Node *next2 = move(node2);
      if (next1 == node2)
      {
        if (prev1 != NULL)
          prev1->ptr = node2;
        else
          head = node2;
        node2->ptr = node1;
        node1->ptr = next2;
        return;
      }
      if (prev1 != NULL)
        prev1->ptr = node2;
      else
        head = node2;
      if (prev2 != NULL)
        prev2->ptr = node1;
      else
        head = node1;
      node2->ptr = next1;
      node1->ptr = next2;
    }
};

int main()
{
    system("chcp 1251");
    system("cls");
    List list;
    list.printList();
    cout << "Введите элемент в список(число):\n";
    for (int i = 0; i < 10; i++)
    {
        int z;
        cout << "-> ";
        cin >> z;
        list.add(z);
    }
    list.printList();
    cout << "Последний элемент: " << list.getValue(list.last()) << endl;
    Node *p = list.first();
    do {
        if (list.getValue(p) == 0)
            p = list.deleteElement(p);
        else
            p = list.move(p);
    }
    while (p != NULL);
        list.printList();
    cout << "В списке " << list.getCount() << " элементов" << endl;
    list.swap(list.first(), list.last());
    list.printList();
    list.clear();
    list.printList();
    cout << "В списке " << list.getCount() << " элементов" << endl;
    cin.get();
    cin.get();
  return 0;
}
