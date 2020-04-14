#include <iostream>

using namespace std;


struct node{
    int value;
    node *next;
};

void insert_element(node **queue, node *elem){
    node* aux = new node;

    if(queue == NULL){
        cout << "fila nula\n";
        return; 
    }

    if(elem == NULL){
        cout << "elemento nula\n";
        return; 
    }

    if(elem->next != NULL){
        cout << "elemento pertence a outra fila \n";
        return;
    }

    if((*queue)->next == NULL){
        (*queue)->next = elem;
        elem->next = NULL;
    }else{

        aux = (*queue)->next;
        while(aux->next != NULL){
            aux = aux->next;
        }

        aux->next = elem;
        elem->next = NULL;
    }

}

node* remove_first(node** queue){
    node* aux;
    node* elem;
    
    if(queue == NULL){
        cout << "fila vazia\n";
        return NULL; 
    }

    aux = (*queue)->next;
    elem = aux->next;
    (*queue)->next = elem;
    aux->next = NULL;
    return aux;
} 

void print_queue(node** queue){
    node *aux;
    aux = (*queue)->next;

    if(queue == NULL){
        cout << "fila nula\n";
        return; 
    }

    while(aux->next != NULL){
        cout << aux->value << endl;
        aux = aux->next;
    }  
}

int queue_size(node** queue){
    int i=0;
    node *aux;

    if(queue == NULL){
        cout << "fila vazia\n";
        return -1; 
    }

    aux = (*queue)->next;

    while(aux->next != NULL){
        i++;
        aux = aux->next;
    }

    cout << "Tamanho da fila " << i << endl;
    return i;  
}



int main(int argc, char const *argv[])
{
    node* head = new node;
    node* elem = new node;
    int i;

    elem->next = NULL;
    elem->value = 1;
    
    for(i=0;i<10;i++){
        node* elem = new node;
        elem->next = NULL;
        elem->value = i;
        insert_element(&head, elem);
    }

    print_queue(&head);
    queue_size(&head);

    remove_first(&head);

    queue_size(&head);

    delete head;

    return 0;
}
