#include <string>
#include "studentRoll.h"
#include <sstream>

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
    Node* newNode = new Node;
    newNode -> s = new Student(s);
    newNode -> next = NULL;
    if (head == NULL){
        head = newNode;
    }
    if(tail != NULL){
        tail -> next = newNode;
    }
    tail = newNode;
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
  Node *temp = orig.head;
  while(temp != NULL){
      insertAtTail(*temp->s);
      temp = temp->next;
  }
  head = tail = NULL;
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




