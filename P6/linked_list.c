typedef struct q{
        int data;
        struct q *prev;
        struct q *next;
}LINKED_LIST;


LINKED_LIST* Node_create(){
  LINKED_LIST *node;
  node = (LINKED_LIST*) malloc(sizeof(LINKED_LIST));
  node->next = NULL;
  node->prev = NULL;
  return node;
}

LINKED_LIST* Node_add_to_first(LINKED_LIST *head ,int number){
  LINKED_LIST *node;
  node = (LINKED_LIST*) malloc(sizeof(LINKED_LIST));
  node->data = number;
  node->next= head;
  head->prev = node;
  return node;
}

void Node_add(LINKED_LIST *head ,int number){
  LINKED_LIST *node;
  node = (LINKED_LIST*) malloc(sizeof(LINKED_LIST));
  node->data = number;
  node->next = NULL;

  LINKED_LIST *temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = node;
}

int Node_size(LINKED_LIST *head){
  int i = 0;
  LINKED_LIST *temp = head;
  while(temp->next != NULL){
    temp = temp->next;
    i++;
  }
  return i;
}

void Node_print(LINKED_LIST *node){
  LINKED_LIST *head = node;
  int i = 0;
  while( head != NULL){
         printf("Node nr %d : %d \n" , i++, head->data);
         head = head->next;
  }
}
