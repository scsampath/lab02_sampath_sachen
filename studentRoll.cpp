#include <string>
#include "studentRoll.h"
#include <sstream>

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
    Node* newNode = new Node;
    newNode->s = new Student(s.getName(), s.getPerm());
    newNode->next = NULL;
    if(!head || !tail) {
      head = tail = newNode;
    }
    else {
      tail->next = newNode;
      tail = newNode;
    }
}

std::string StudentRoll::toString() const {
    std::ostringstream oss;
    oss << "["; 
    Node* temp = head;
    while(temp){
        oss << temp->s->toString();
        if(temp != tail){
            oss << ",";
        }
        temp = temp->next;
    }
    oss << "]";
    return oss.str();
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  if(!orig.head){
    return;
  }
  Node* temp = orig.head;
  while(temp){
    Node *newNode = new Node;
    newNode->s = new Student(temp->s->getName(), temp->s->getPerm());
    if(!head || !tail){
      head = tail = newNode;
    }
    else {
      tail = newNode;
    }
    newNode = newNode->next;
    temp = temp -> next;
  }
  //   for (Node*i = orig.head; i != NULL; i = i->next){
  //   iter = new Node;
  //   iter->s = new Student(i->s->getName(), i->s->getPerm());
  //   tail = iter;
  //   iter = iter->next;
  // }
}


StudentRoll::~StudentRoll() {
  while(head != NULL){
      Node *temp = head;
      head = head->next;
      delete temp;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  
  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
}




