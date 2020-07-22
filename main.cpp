#include <iostream>
#include <stdio.h>

using namespace std;

//train car node
struct node
{
	int id;
	char typeOfCar;
	int numberOfStops;
	node* next;
};

node* head = NULL;

//AddToFront function
void insert(int id, char typeOfCar, int numberOfStops)
{
	node* temp = new node();
	temp->id = id;
	temp->typeOfCar = typeOfCar;
	temp->numberOfStops = numberOfStops;
	temp->next = NULL;

	if (head != NULL)
	{
		temp->next = head;
	}

	head = temp;
}

//AddToEnd function
void insertAtEnd(int id, char typeOfCar, int numberOfStops)
{
	node* temp = new node();
	temp->id = id;
	temp->typeOfCar = typeOfCar;
	temp->numberOfStops = numberOfStops;
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
	}

    else if (head != NULL)	
	{
		head->next = temp;
		head = temp;
	}
	
}

//AddAtIndex function
void insertAtIndex(int id, char typeOfChar, int numberOfStops, int index)
{
	node* temp1 = new node();
	temp1->id = id;
	temp1->typeOfCar = typeOfChar;
	temp1->numberOfStops = numberOfStops;
	temp1->next = NULL;

	if (index == 1)
	{
		temp1->next = head;
		head = temp1;
		return; //can not execute any further
	}

	node* temp2 = head;

	//get to the n-1th node by stopping at n-2. n-1 in this case is NULL as it is the last spot in the linked list
	for (int i = 0; i < index - 2; i++)
	{
		temp2 = temp2->next;
	}

	temp1->next = temp2->next;
	temp2->next = temp1;

}

//RemoveFromFront function
void deleteHeadNode()
{
	node* temp = head;
	head = temp->next;
	if (temp != NULL)
	{
		cout << "The node that is deleted is: " << temp->id << " " << temp->typeOfCar << " " << temp->numberOfStops << endl;
		delete temp;
	}	
}

//RemoveFromEnd function
void deleteEndNode()
{
	node* temp1 = head;
	while (temp1 != NULL && temp1->next->next != NULL)
	{
		temp1 = temp1->next;
	}
	delete temp1->next;
	temp1->next = NULL;
}

//deleting at n-th position
void deleteAtIndex(int index)
{
	node* temp1 = head;
	for (int i = 0; i < index - 2; i++)
	{
		temp1 = temp1->next;
	}

	node* temp2 = temp1->next;
	
	temp1->next = temp2->next;
	delete temp2;
}

//count how many nodes are in the list
void counter()
{
	node* temp = head;
	int counter = 0;
	while (temp != NULL)
	{
		counter++;
		temp = temp->next;
	}
	cout << "The number of elements in the linked list are: " << counter << endl;
}

//check if an element exists in a list
bool elementExists(int id, char typeOfCar, int numberOfStops)
{
	node* temp = head;
	while (temp != NULL)
	{
		if (temp->id == id && temp->typeOfCar == typeOfCar && temp->numberOfStops == numberOfStops)
		{
			cout << "The element exists!" << endl;
			return true;
		}

		temp = temp->next;
	}

	cout << "The element does not exist..." << endl;
	return false;
	
}

//find first instance and remove it
void removeFirst(char typeOfCar)
{
	node* temp = head;
	while (temp != NULL)
	{
		if (temp->typeOfCar == typeOfCar)
		{
			head = temp->next;
			delete temp;
			cout << "First instance has been removed\n" << endl;
			return;
		}
		temp = temp->next;
	}
}

//remove all cars of a certain type
void removeAll(char typeOfCar)
{
	node* temp1 = head;
	node* temp2 = temp1->next;


	while (temp1 != NULL)
	{
		if (temp1->typeOfCar == typeOfCar && temp1 == head)
		{
			head = temp2;
			delete temp1;
		}

		else if (temp1->typeOfCar == typeOfCar)
		{
			delete temp1;
		}

		temp1 = temp1->next;
	}
}

int indexOf(int id, char typeOfCar, int numberOfStops)
{
	node* temp = head;
	int counter = 0;
	while (temp != NULL)
	{
		counter++;
		if (temp->id == id && temp->typeOfCar == typeOfCar && temp->numberOfStops == numberOfStops)
		{
			cout << "Index of " << temp->id << " " << temp->typeOfCar << " " << temp->numberOfStops << " is index " << counter << endl;
			return counter;
		}
		temp = temp->next;
	}
}

//look for data and return pointer to node
node* find(int id, char typeOfCar, int numberOfStops)
{
	node* temp = head;
	while (temp != NULL)
	{
		if (temp->id == id && temp->typeOfCar == typeOfCar && temp->numberOfStops == numberOfStops)
		{
			cout << "NODE FOUND!!!" << endl;
			return temp;
		}
		temp = temp->next;
	}

	cout << "No such node in the Linked List" << endl;
	return NULL;
}

//return data in the first node
node* retrieveFront()
{
	node* temp = head;
	if (temp != NULL)
	{
		cout << "Head node found and content returned" << endl;
		return temp;
	}
	cout << "List is empty" << endl;
	return NULL;
}

//return content within the last node
node* retrieveEnd()
{
	node* temp1 = head;
	while (temp1 != NULL && temp1->next != NULL)
	{
		temp1 = temp1->next;
	}
	cout << "End node retrieved: " << temp1->id << " " << temp1->typeOfCar << " " << temp1->numberOfStops << endl;
	return temp1;
}

//retrieves data based on index
node* retrieve(int index)
{
	node* temp = head;
	int counter = 0;
	while (temp != NULL)
	{
		if (counter == index)
		{
			cout << "Index found: " << temp->id << " " << temp->typeOfCar << " " << temp->numberOfStops << endl;
			return temp;
		}
		counter++;
		temp = temp->next;
	}

	return NULL;
}

//delete the entire linked list
void empty()
{
	node* temp1 = head;
	node* temp2;
	
	while (temp1 != NULL)
	{	
		//delete each node one by one
		temp2 = temp1->next;
		delete temp1;
		temp1 = temp2;
	}
	cout << "Linked list is now empty" << endl;
}

void print()
{
	node* temp = head;
	cout << "List is: " << endl;
	while (temp != NULL)
	{
		cout << "ID: " << temp->id << " type of car: " << temp->typeOfCar << " number of stops: " << temp->numberOfStops << endl;
		temp = temp->next;
	}
}


int main()
{
	
	insertAtIndex(1, 'P', 3, 1);
	insertAtIndex(2, 'C', 6, 2);
	insertAtIndex(3, 'M', 9, 3);
	insertAtIndex(4, 'C', 12, 1);
	print();
	removeFirst('C');
	print();
	

	/*
	cout << "Linked List after deletion: " << endl;
	deleteAtIndex(1);
	print();
	counter();
	*/

}