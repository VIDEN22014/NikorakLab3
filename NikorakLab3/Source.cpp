#include <iostream>

using namespace std;

class ListController {
public:class List {
public: struct Data {
public:int data;
}record;
	  List* next = nullptr;
};
	  List* head=nullptr;
	  int maxSize = 0;
public: int Size = 0;
	  ListController(int size) {
		  maxSize = size;
		  head = nullptr;
	  }
	  ListController::List::Data operator[](int index) {
		  List* temp = head;
		  for (int i = 0; i < index; i++)
		  {
			  temp = temp->next;
		  }
		  return temp->record;
	  }
	  void Add(int data) {
		  if (Size < maxSize) {
			  Size++;
			  if (head == nullptr) {
				  head = new List();
				  head->record.data = data;
			  }
			  else {
				  List* temp = head;
				  while (temp->next != nullptr)
				  {
					  temp = temp->next;
				  }
				  temp->next = new List();
				  temp->next->record.data = data;
			  }
		  }
	  };
	  void MakeNull() {
		  Size = 0;
		  head = nullptr;
	  }
	  void Insert(int pos, int data) {
		  if (Size < maxSize) {
			  List* previous = head;
			  List* current = head;
			  if (pos == 0) {
				  head = new List();
				  head->record.data = data;
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
				  previous->next->record.data = data;
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
			  cout << temp[i].data << endl;
		  }
		  cout << "Size= " << Size << endl<<endl;
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
		  if (pos <= Size - 1 && pos >= 0) { return true; }
		  else return false;
	  }
};


int main() {
	ListController contr(3);
	contr.Add(700);
	contr.Add(900);
	contr.Insert(2,654);
	contr.Display();
	cout << "isFull = " << contr.isFull() << endl;
	cout << "isEmpty = " << contr.isEmpty() << endl;
	cout << "isValid = " << contr.isValid(0) << endl;
	system("pause");
}
