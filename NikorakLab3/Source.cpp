#include <iostream>

using namespace std;

class ListController {
public:class List {
public: struct Data {
public:int data;
}record;
	  List* next = nullptr;
};
	  List* head;
	  int maxSize = 0;
public: int Size = 0;
	  ListController(int size) {
		  maxSize = size;
		  head = nullptr;
	  }
	  int operator[](int index) {
		  List* temp = head;
		  for (int i = 0; i < index; i++)
		  {
			  temp = temp->next;
		  }
		  return temp->record.data;
	  }
	  void Add(int add) {
		  if (Size < maxSize) {
			  Size++;
			  List* temp = head;
			  if (head == nullptr) {
				  head = new List();
				  head->record.data = add;
			  }
			  else {
				  while (temp->next != nullptr)
				  {
					  temp = temp->next;
				  }
				  temp->next = new List();
				  temp->next->record.data = add;
			  }
		  }
	  };
	  void MakeNull() {
		  Size = 0;
		  head = nullptr;
	  }
	  void Insert(int pos, int insert) {
		  if (Size < maxSize) {
			  List* previous = head;
			  List* current = head;
			  if (pos == 0) {
				  head = new List();
				  head->record.data = insert;
				  head->next = current;
			  }
			  else {
				  for (int i = 0; i < pos; i++)
				  {
					  current = current->next;
				  }
				  for (int i = 0; i < pos - 1; i++)
				  {
					  previous = previous->next;
				  }
				  previous->next = new List();
				  previous->next->record.data = insert;
				  previous->next->next = current;
			  }
			  Size++;
		  }
	  }
	  void Delete(int pos) {
		  List* prevoius = head;
		  List* current = head;
		  if (pos == 0) {
			  if (Size != 0) {
				  head = head->next;
			  }
		  }
		  else {
			  for (int i = 0; i < pos; i++)
			  {
				  current = current->next;
			  }
			  for (int i = 0; i < pos - 1; i++)
			  {
				  prevoius = prevoius->next;
			  }
			  prevoius->next = current->next;
		  }
		  if (Size != 0) {
			  Size--;
		  }
	  }
	  void Display() {
		  ListController temp = *this;
		  for (int i = 0; i < Size; i++)
		  {
			  cout << temp[i] << endl;
		  }
		  cout << "Size= " << Size << endl;
	  }
	  bool isEmpty() {
		  if (Size == 0) { return true; }
		  else return false;
	  }
	  bool isFull() {
		  if (Size == maxSize) { return true; }
		  else return false;
	  }
	  bool isValid(int pos) {
		  if (pos <= Size - 1&&pos>=0) { return true; }
		  else return false;
	  }
};


int main() {
	ListController contr(3);
	contr.Insert(0, 67);
	contr.Add(9);
	contr.Add(4);
	contr.Add(5);
	contr.Display();
	cout<<contr.isFull();
	cout<<contr.isEmpty();
	cout<<contr.isValid(0);
	system("pause");
}
