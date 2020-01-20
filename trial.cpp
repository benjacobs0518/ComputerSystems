#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <iostream>
#include <limits.h>
using namespace std;

struct Node{
  int data;
  Node* prev;
  Node* next;
}

int main( ){
Node head;
Node temp;
Node temp1;
Node temp2;
Node tail;

head.data = 12;
head->next = temp;
head->prev = temp;

temp.data = 16;
temp->next = temp1;
temp->prev = head;

temp1.data = 17;
temp1->next = temp2;
temp1->prev = temp;

temp2.data = 7;
temp2->next = tail;
temp2->prev = temp1;

tail.data = 20;
tail->next = temp2;
tail->prev = temp2;

Node temp = head;

while(temp && temp.data > temp->prev.data)
{
  temp = temp->next;
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  temp->next = NULL;
  temp->prev = temp->next;
}

Node test = head;
for (int i = 0; i < 5; i++)
{
  cout << test->data << " " << endl;
  temp = test->next;
}




}
