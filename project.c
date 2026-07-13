#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define MAX 100
// QUEUE

int queue[MAX];
int front = 0, rear = 0;

int isEmpty(){
    if (front == rear)
        return 1;
    return 0;
}
int dequeue(){
    if (isEmpty()){
        printf("Queue Underflow!!");
        return INT_MIN;
    }
    front = (front + 1) % MAX;
    return queue[front];
}
void enqueue(int val){
    if ((rear + 1) % MAX == front){
        printf("Queue Overflow!!");
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = val;
}

// END QUEUE
struct Node{
    int data;
    struct Node *next;
};
struct Node *head[100] = {NULL};
int sol[100] = {-1};
int solSet[100] = {0};
int inDegree[100] = {0};
char courseCode[100][50];
int n = 0, s = 0;
struct Node *create(int val){
    struct Node *curr = (struct Node *)malloc(sizeof (struct Node));
    if(curr == NULL){
        printf("Memory Allocation failed!!\n");
        return curr;
    }
    curr->data = val;
    curr->next = NULL;
    return curr;
}

void addEnd(struct Node **head, int val){
    if(*head == NULL){
        *head = create(val);
        return;
    }
    struct Node *temp = *head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = create(val);
}

void displayList(struct Node* temp){
    while(temp != NULL){
        printf("%s -> ", courseCode[temp->data]);
        temp = temp->next;
    }
    printf("NULL\n");
}

void calculateIndegree(){
    for (int i = 0; i < n; i++)
        inDegree[i] = 0;
    for (int i = 0; i < n;i++){
        struct Node *temp = head[i];
        while(temp != NULL){
            inDegree[temp->data]++;
            temp = temp->next;
        }
    }
}
void printTopologicalOrder(){
    printf("\nValid Course Completion Order:\n");

    for (int i = 1; i <= s; i++){
        printf("%s", courseCode[sol[i]]);

        if (i != s)
            printf(" -> ");
    }

    printf("\n");
}
void TopologicalSort(){
    front = rear = 0;
    s = 0;
    for (int i = 0; i < n; i++){
        inDegree[i] = 0;
        solSet[i] = 0;
        sol[i] = -1;
    }
    calculateIndegree();
    for (int i = 0; i < n; i++){
        if(inDegree[i] == 0)
            enqueue(i);
    }
    while(!isEmpty()){
        int u = dequeue();
        sol[++s] = u;
        solSet[u] = 1;
        struct Node *temp = head[u];
        while(temp != NULL){
            if (solSet[temp->data] == 0){
                inDegree[temp->data]--;
                if(inDegree[temp->data] == 0)
                    enqueue(temp->data);
            }
            temp = temp->next;
        }
    }
    if (s != n){
        printf("There is cycle present in the graph!!\n");
        return;
    }
    printTopologicalOrder();
}

int main(){
    int choice;
    int u, v;

    printf("Enter total number of courses: ");
    scanf("%d", &n);

    printf("\nEnter Course Codes:\n");
    for(int i = 0; i < n; i++){
        printf("Course %d : ", i);
        scanf("%s", courseCode[i]);
    }

    while(1){
        printf("\n=====================================\n");
        printf(" COURSE PREREQUISITE MANAGEMENT SYSTEM\n");
        printf("=====================================\n");
        printf("1. Add Prerequisite\n");
        printf("2. Display Graph\n");
        printf("3. Find Course Order (Topological Sort)\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nAvailable Courses:\n");
                for(int i = 0; i < n; i++)
                    printf("%d. %s\n", i, courseCode[i]);

                printf("\nEnter prerequisite course index : ");
                scanf("%d", &u);

                printf("Enter dependent course index : ");
                scanf("%d", &v);

                if (u == v){
                    printf("A course cannot be prerequisite of itself.\n");
                }
                else if(u < 0 || u >= n || v < 0 || v >= n){
                    printf("Invalid Course Index!\n");
                }
                else{
                    addEnd(&head[u], v);
                    printf("Prerequisite Added Successfully!\n");
                }
                break;

            case 2:
                printf("\nCourse Prerequisite Graph:\n");
                for(int i = 0; i < n; i++){
                    printf("%s --> ", courseCode[i]);
                    displayList(head[i]);
                }
                break;

            case 3:
                printf("\nChecking for cycles...\n");
                TopologicalSort();

                if(s == n){
                    printf("\nNo cycle detected.\n");
                    printf("Valid Course Completion Order Generated.\n");
                }
                else{
                    printf("\nCycle detected!\n");
                    printf("Course registration order cannot be generated.\n");
                }

                break;

            case 4:
                printf("Exiting Program...\n");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}