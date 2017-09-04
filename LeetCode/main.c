//
//  main.c
//  LeetCode
//
//  Created by 杨敏 on 2017/9/1.
//  Copyright © 2017年 com.tentiy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct LINode *Linkde;

struct LINode{
    int data;
    
    Linkde Next;
};







int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

  //  add two numbers
Linkde addTwoNumbers(Linkde l1,Linkde l2){
    
    int sum = 0;
    
    Linkde l3Head = (Linkde)malloc(sizeof(struct LINode));
    
    l3Head->data = -1;
    
    while (l1 || l2  || sum != 0) {
        
       Linkde l3 = (Linkde)malloc(sizeof(struct LINode));
        
        sum = l1->data + l2->data+ sum;
        
        l3->data = sum %10;
        
        l3Head->Next = l3;
        
        l1 = l1->Next;
        
        l2 = l2->Next;
        
        sum = sum/10;
    }
    
    return l3Head->Next;
    
}

Linkde reverseBeteen(Linkde link,int m, int n){
    
    Linkde head = (Linkde)malloc(sizeof(struct LINode));
    
    head->data = -1;
    
    head->Next = link;
    
    Linkde p ,q,linkN;
    
    for (int i = 0; i<m; i++) {
        
        if (i == m-1) {
            
            linkN = head;
        }
        
        if (i>m-1 && i<=n-1) {
            
            p = head->Next;
            q = p->Next;
            
            
            
        }
        
        head = head->Next;
    }
    
    return NULL;
}

Linkde PartitionList(Linkde link,int k){
    
    Linkde head = (Linkde)malloc(sizeof(struct LINode));
    Linkde newLink = (Linkde)malloc(sizeof(struct LINode));
    
    head->data = -1;
    newLink->data = -1;
    
    head->Next = link;
    
    Linkde curr= head;
    
    Linkde p = newLink;
    
    
    while (curr->Next) {
        
        if (curr->Next->data < k) {
            
            p->Next = head->Next;
            
            p = p->Next;
            
            curr->Next = curr->Next->Next;
            
        }else{
            
            curr = curr ->Next;
        }
        
    }
    
    p->Next = head->Next;
    
    return newLink->Next;
}



Linkde PartitionList2(Linkde link,int k){
    
    Linkde head =(Linkde)malloc(sizeof(struct LINode));
    
    head->data = -1;
    
    head->Next = link;
    
    Linkde curr  = head;
    
    Linkde p = link;
    
    while (curr->Next && curr->Next->data <k) {
        
        curr= curr->Next;
    }
    
    p = curr;
    
    while (p->Next ) {
        
        if (p->Next->data < k) {
            
            Linkde temp = p->Next;
            
            p->Next = temp->Next;
            
            temp->Next = curr->Next;
            
            curr->Next = temp;
            
            curr = curr->Next;
            
        }else{
            
            p= p->Next;
        }
        
    }
    
    return head->Next;
}

Linkde RemoveDuplicates(Linkde head){
    
    if(!head->Next->Next) return head;
    
    Linkde p = head->Next;
    
    Linkde q = p->Next;
    
    while (p && q) {
        
        if(p->data == q->data){
            
            p->Next = q->Next;
            
            q->Next = NULL;
            
            q = p->Next;
            
        }else{
            
            p = p->Next;
            
            q= q->Next;
        }
    }
    
    
    
    return head->Next;
}

Linkde RemoveDuplicates2(Linkde head){
    
    if (head || head ->Next) return head;
    
    Linkde curr = head;
    
    Linkde p = head->Next;
    
    while (p) {

        if (curr->data < p->data) {
            
            curr = p;
            
            p = p->Next;
            
        }else{
            
            curr = curr->Next;
            
            p = p->Next;
        }
    }
    
    
    
    return head;
}


Linkde rotateRight(Linkde link,int k){
    
    if(link || k == 0) return link;
    
    Linkde p = link;
    
    int lent = 1;
    
    while (p->Next) {
        
        lent++;
        
        p = p->Next;
    }
    
    k = lent - k%lent;
    
    p ->Next= link;
    
    for (int step =0; step<k; step ++) {
        
        p = p->Next;
        
    }
    
    link = p ->Next;
    
    p ->Next = NULL;
    
    return link;
}

//2.2.7 Remove Nth Node From End of List

Linkde RemoveNth(Linkde link,int k){
    
    Linkde head = (Linkde)malloc(sizeof(struct LINode));
    
    head->data = -1;
    
    head->Next = link;
    
    Linkde p = head,q = head;
    
    for (int i= 0; i<k; i++) {
        
        p = p->Next;
    }
    
    while (p->Next) {
        
        p= p->Next;
        
        q= q->Next;
        
    }
    
    Linkde temp = q->Next;
    
    q->Next = q->Next->Next;
    
    
    free(temp);
    
    return head->Next;
}

//2.2.8 Swap Nodes in Pairs

Linkde swapNodesInPairs(Linkde link){
    
    Linkde head = (Linkde)malloc(sizeof(struct LINode));
    
    head ->data = -1;
    
    head ->Next = link;
    
    Linkde p = head->Next;
    
    while (p && p->Next) {
        
        int temp = p->data;
        
        p->data = p->Next->data;
        
        p->Next->data = temp;
        
        p=p->Next->Next;
    }
    return head->Next;
}

Linkde swapNodesInPairs2(Linkde link){
    
    Linkde curr = link;
    
    while (curr->Next) {
        
        Linkde p = curr->Next;
        
        Linkde q = p->Next;
        
        curr->Next = q;
        
        p->Next = curr;
        
        curr = q;
        
    }
    
    
    return link;
}


//2.2.9 Reverse Nodes in k-Group
//需要仔细看  不太明白
Linkde reverseNodeInK(Linkde link,int k){
    
    if(link ==NULL || link->Next == NULL) return link;
    
    Linkde stop = link;
    
    for (int i = 0; i<k; i++) {
        
        if(stop) stop = stop->Next;
        
        else return link;
    }
    
    Linkde nest_stop = reverseNodeInK(stop, k);
    
    Linkde curr = link;
    Linkde prev = NULL;
    
    while (curr !=nest_stop) {
    
        Linkde p = curr ->Next;
        
        curr->Next = prev?prev:nest_stop;
        
        prev = curr;
        
        curr = p;
    }
    
    return prev;
}


//2.2.10 Copy List with Random Pointer 待解决


//2.2.11 Linked List Cycle

#define int_flase 0

#define int_ture 1

int LinkedIsCycle(Linkde link){
    
    Linkde slow = link,fast = link;
    
    while (slow && fast->Next) {
        
        slow = slow->Next;
        
        fast = fast->Next->Next;
        
        if (slow == fast) return int_ture;
    }
    
    return int_flase;
}












