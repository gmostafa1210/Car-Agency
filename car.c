
#include <stdio.h>
#include <stdlib.h>

//This is the node of car agency
struct cNode{
    char car_name[20];
    int total_car;
    struct cNode *next;
}*cnode;

//This is the head of car agency
struct cHead{
    int count;
    struct cNode *p;
}*chead;

//This is the create head of car agency
void create_chead(){
    chead = (struct cHead*)malloc(sizeof(struct cHead));
    chead->count = 0;
    chead->p = NULL;
}

//This is the create node of car agency
void create_cnode(){
    cnode = (struct cNode*)malloc(sizeof(struct cNode));
    printf("Enter Car Model Name: ");
    scanf("%s",cnode->car_name);
    printf("Enter Total Number of cars: ");
    scanf("%d",&cnode->total_car);
    printf("\n");
    cnode->next = NULL;
}

//This is the the function to insert first car's information
void insert_first_car(){
    create_cnode();
    cnode->next = chead->p;
    chead->p = cnode;
    chead->count++;
}

//This is the the function to insert cars' information
void insert_car(){
    int i, n;

    printf("==== Welcome to the Global Car agency ====\n\n");
    printf("How many types of car you want to sell?\n");
    printf("Answer: ");
    scanf("%d", &n);
    printf("\n");

    for(i = 0; i < n; i ++){
        struct cNode *temp;
        if(chead->count==0){
            insert_first_car();
        }
        else{
            create_cnode();
            temp = chead->p;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = cnode;
            chead->count++;
        }
    }
    printf("Thank You.\n");
}

//This is the display function of car agency
void display_car(){
    struct cNode *temp;
    temp = chead->p;
    printf("\nWelcome to the Global Car Agency:\n");
    printf("==========================\n\n");
    while(temp != NULL){
        printf("Car Model Name: %s\n", temp->car_name);
        printf("Total Numbers of Cars: %d\n", temp->total_car);
        printf("\n");
        temp = temp->next;
    }
    printf("==========================\n\n");
}

// Stack Node
struct sNode{
    struct car_info {
        char car[20];
        int ncar;
    }ci;
    struct sNode *next;
}*snode;

//Stack Head
struct sHead{
    int count;
    struct Node *p;
}*shead;

//Create Stack Head
void create_shead(){
    shead = (struct sHead*)malloc(sizeof(struct sHead));
    shead->count = 0;
    shead->p = NULL;
}

//Create Stack Node
void create_snode(){
    snode = (struct sNode*)malloc(sizeof(struct sNode));
    printf("Car name: ");
    scanf("%s",snode->ci.car);
    printf("Number of car you want: ");
    scanf("%d",&snode->ci.ncar);
    snode->next = NULL;
}

//Push
void push(){
    create_snode();
    snode->next = shead->p;
    shead->p = snode;
    shead->count++;
}

//Pop
void pop(){
    if(shead->count == 0){
        printf("\n\nNo more order.\n");
    }
    else{
        struct sNode *temp;
        temp = shead->p;
        shead->p = temp->next;
        free(temp);
        shead->count--;
    }
}

//Display
void display_order(){
    struct sNode *temp;
    temp = shead->p;
    printf("\nDisplay:\n");
    printf("-------\n");
    while(temp != NULL){
        printf("Car name: ");
        printf("%s",temp->ci.car);
        printf("\n");
        printf("Number of car you want: ");
        printf("%d",temp->ci.ncar);
        temp = temp->next;
    }
    printf("\n-------\n\n");
}

//This is the node of buyer
struct bNode{
    char name[20];
    int id;
    struct bNode *next;
}*bnode;

//This is the head of buyer
struct bHead{
    int count;
    struct bNode *front;
    struct bNode *rear;
}*bhead;

//This is the create head of buyer
void create_bhead(){
    bhead = (struct bHead*)malloc(sizeof(struct bHead));
    bhead->count = 0;
    bhead->front = NULL;
    bhead->rear = NULL;
}

//This is the create node of car agency
void create_bnode(){
    bnode = (struct bNode*)malloc(sizeof(struct bNode));
    int i, n;
    printf("Buyer Name: ");
    scanf("%s",bnode->name);
    printf("ID: ");
    scanf("%d",&bnode->id);
    printf("\n");
    printf("You can't buy more than three(3) types of car.\n");
    printf("Number of car you want to buy: ");
    scanf("%d",&n);
    printf("\n");

    for(i = 0; i < n; i ++){
        push();
    }

    printf("\nOrder complete. Please wait.\n");
    bnode->next = NULL;
}

//Enqueue Buyer
void enqueue(){
    if(bhead->count == 0){
        create_bnode();
        bhead->front = bnode;
        bhead->rear = bnode;
    }
    else{
        create_bnode();
        bhead->rear->next = bnode;
        bhead->rear = bnode;
    }
    bhead->count++;
}

//dequeue Buyer
void dequeue(){
    struct bNode *temp;
    if(bhead->count > 0){
        temp = bhead->front;
        bhead->front = temp->next;
        bhead->count--;
        free(temp);
        printf("ID: %d. Complete.\n", temp->id);
    }
    else{
        printf("\nNo more buyer.\n");
    }
}

//Display of Buyer List
void display_buyer(){
    if(bhead->front == 0){
        printf("\nNo buyer.\n");
    }
    else{
        struct bNode *temp;
        temp = bhead->front;
        printf("\nBuyer List:\n");
        printf("===========\n\n");
        while(temp != NULL){
            printf("--------------\n");
            printf("Name: %s\n",temp->name);
            printf("ID: %d\n", temp->id);
            printf("--------------\n\n");
            temp = temp->next;
        }
        printf("===========\n\n");
    }
}

//Main Function
int main(){
    create_chead();
    create_bhead();
    insert_car();
    display_car();

    int option;
    while(1){
        printf("\n");
        printf("Press 1 For Enqueue Buyer.\n");
        printf("Press 2 For Dequeue Buyer.\n");
        printf("Press 3 For Display Buyer list.\n");
        printf("Press 4 For Close.\n");
        printf("\nYour Option: ");
        scanf("%d",&option);
        printf("\n");

        if(option == 1){
            create_shead();
            enqueue();
            display_car();
        }
        else if(option == 2){
            dequeue();
            display_car();
        }
        else if(option == 3){
            display_buyer();
            display_car();
        }
        else if(option == 4){
            printf("\nThank you.\n");
            break;
        }
        else{
            printf("\nInvalid Input! Try Again.\n");
        }
    }
    return 0;
}

