#include <iostream>

using namespace std;

class ListController {
public:class List {
public: struct Data {
public:string markName;
	  bool isGood;
	  double price;
}record;
	  List* next = nullptr;
};
	  List* head = nullptr;
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
	  void Add(string markName, bool isGood, double price) {
		  if (Size < maxSize) {
			  Size++;
			  if (head == nullptr) {
				  head = new List();
				  head->record.markName = markName;
				  head->record.isGood = isGood;
				  head->record.price = price;
			  }
			  else {
				  List* temp = head;
				  while (temp->next != nullptr)
				  {
					  temp = temp->next;
				  }
				  temp->next = new List();
				  temp->next->record.markName = markName;
				  temp->next->record.isGood = isGood;
				  temp->next->record.price = price;
			  }
		  }
	  };
	  void MakeNull() {
		  Size = 0;
		  head = nullptr;
	  }
	  void Insert(int pos, string markName, bool isGood, double price) {
		  if (Size < maxSize) {
			  List* previous = head;
			  List* current = head;
			  if (pos == 0) {
				  head = new List();
				  head->record.markName = markName;
				  head->record.isGood = isGood;
				  head->record.price = price;
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
				  previous->next->record.markName = markName;
				  previous->next->record.isGood = isGood;
				  previous->next->record.price = price;
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
			  cout << temp[i].markName << " " << temp[i].isGood << " " << temp[i].price << endl;
		  }
		  cout << "Size= " << Size << endl << endl;
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
	  void DeleteByPrice(double price) {
		  ListController temp = *this;
		  for (int i = 0; i < temp.Size; i++)
		  {
			  if (temp[i].price<price) {
				  Delete(i);
				  DeleteByPrice(price);
				  break;
			  }
		  }
	  }
};

int main() {
	ListController contr(6);
	contr.Add("Xiaomi", 0, 799);
	contr.Add("Apple", 1, 999);
	contr.Add("Samsung", 1, 780);
	contr.Insert(0,"Nokia", 1, 900);
	contr.Display();
	contr.DeleteByPrice(800);
	contr.Display();
	system("pause");
}
