#include "list.h"
// релизации для списка

// Конструкторы, деструктор	
template <typename TData>
List<TData>::List()
{ head = new Node<TData>;
  head->data = NULL;
  head->next = head;
  current = head;
}
template <typename TData> // конструктор копирования
List<TData>::List(const List<TData>& L2)
{ Node<TData>* TempCurr = ListToCopy.head;
  head = new Node<TData>(TempCurr->data);
  head->next = head;
  current = head;
  while (TempCurr->next != ListToCopy.head)
  { TempCurr = TempCurr->next;
	current->next = new Node<TData>(TempCurr->data);
	SetNext();
  }
  current->next = head;
}
template <class TData>
List<TData>::~List()
{ Clean();
  delete head;
}
// Перегрузка операций
template <class TData>
List<TData>& List<TData>::operator=(const List<TData>& L)
{ Clean();
  Node<TData>* TempCurr1 = ListToCopy.head;
  Node<TData>* TempCurr2 = head;
  while (TempCurr1->next != ListToCopy.head)
  { TempCurr1 = TempCurr1->next;
	TempCurr2->next = new Node<TData>(TempCurr1->data);
	TempCurr2 = TempCurr2->next;
  }
  TempCurr2->next = head;
  current = head;
  return *this;
}
template<class TData>
bool List<TData>::operator==(const List<TData>& L) const
{
	bool flag = true;
	if (this != &L)
	{
		Node<TData>* temp1 = head->next;
		Node<TData>* temp2 = RLst.head->next;

		while (temp1 != head && temp2 != RLst.head && temp1->data == temp2->data)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		if (temp1 != head || temp2 != RLst.head)
			flag = false;
	}
	return flag;
}
// Методы 
template <class TData>
void List<TData>::InsertAfter(Node<TData>* N, TData Data)
{
	Node<TData>* temp = N->next;
	N->next = new Node<TData>(Data);
	N->next->next = temp;
}
template <class TData>
void List<TData>::OrderedInsert(TData Data)
{
	Node<TData>* Temp;
	current = head;

	while ((current->next->data > Data) && current->next != head)
		SetNext();

	Temp = current->next;
	current->next = new Node<TData>(Data);
	current->next->next = Temp;
}
template <class TData>
void List<TData>::Clean()
{
	Node<TData>* TempCurr = head->next;
	Node<TData>* Temp;
	while (TempCurr != head)
	{
		Temp = TempCurr->next;
		delete TempCurr;
		TempCurr = Temp;
	}
	head->next = head;
}
