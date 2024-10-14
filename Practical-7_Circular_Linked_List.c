#include <stdio.h>
#include <stdlib.h>
struct CLL{
    int data;
    struct CLL *next;
};
struct CLL *head=NULL;

void insertbeg(){
    struct CLL *new;
    new=(struct CLL*)malloc(sizeof(struct CLL));
    printf("Enter the value :");
    scanf("%d",&new->data);
    if(head==NULL){
        new->next=new;
        head=new;
        return;
    }
    struct CLL *temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    new->next=head;
    temp->next=new;
    head=new;
}
void insertend(){
    struct CLL *new;
    new=(struct CLL*)malloc(sizeof(struct CLL));
    printf("Enter the value :");
    scanf("%d",&new->data);
    if(head==NULL){
        new->next=new;
        head=new;
        return;
    }
    struct CLL *temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;
}
void deleteend(){
    if(head==NULL){
        printf("List is empty....");
        return;
    }
    struct CLL *temp=head;
    while(temp->next->next!=head){
        temp=temp->next;
    }
    temp->next=head;
}
void deletebeg(){
 if(head==NULL){
        printf("List is empty....");
        return;
    }
    struct CLL *temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    head=head->next;
    temp->next=head;
}
void display(){
    printf("Printing the nodes of linked list ...\n");
    struct CLL* temp=head;
    do{
        printf("%d ->",temp->data);
        temp=temp->next;
    }while(temp!=head);
}
int main()
{
    int ch;
    while(1){
            printf("\n1.Insert at begin\n2.Insert at end\n3.Delete at begin\n4.Delete at end\n5.Display\n");
            printf("Enter your choice: ");
            scanf("%d",&ch);
            switch(ch)
            {
                    case 1:insertbeg();
                        break;
                    case 2:insertend();
                        break;
                    case 3:deletebeg();
                        break;
                    case 4:deleteend();
                        break;
                    case 5:display();
                    break;
                    default:printf("Invalid choice");
                    break;
            }
    }
    return 0;
}