// gcc getK_ll.c; .\a q w e r t y

#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
    char* data;
    struct ListNode *next;
} ListNode;

ListNode* buildList(int n, char* dataEntries[]) {
    ListNode temp = {0};

    int i;
    ListNode *itr;
    for (itr=&temp, i = 1; i != n; itr = itr->next, i++) {
        ListNode *nextNode = malloc(sizeof(ListNode));
        nextNode->data = dataEntries[i];
        nextNode->next=NULL;

        itr->next = nextNode;
    }

    return temp.next;
}

ListNode* getK(ListNode *head, int k) {
    /* Four standard ways to get to the k-th element in a linked list (1-indexed).
     * i++,i-- --> increase towards K
     * k++,k-- --> decrease towards 0
     */

    printf("l1--\t--l2\t\ti1++\t++i2\t\ttemp\n");

    int l1 = k, l2 = k;
    int i1 = 0, i2 = 0;
    ListNode* temp = head;
    
    printf("%d\t%d\t\t%d\t%d\t\t%s\n", l1, l2, i1, i2, temp->data);
    while (temp != NULL 
        && (i1++ != k-1 && ++i2 != k)
        && (l1-- != 1 && --l2 != 0)) {  // all 4 are simultaneously met
            printf("%d\t%d\t\t%d\t%d\t\t%s\n", l1+1, l2, i1-1, i2, temp->data);
            temp = temp->next;
        }
    
    printf("\n");
    
    return temp;
}

void printList(ListNode* head) {
    printf("List: ");
    for (ListNode* temp=head; temp != NULL; temp = temp->next)
        printf("%s ", temp->data);
    printf("\n");
}

int main(int argc, char* argv[]) {
    ListNode* head = buildList(argc, argv);
    printList(head);

    int position = 3;
    printf("%s\n", getK(head, position)->data);

    return 0;
}