#include <stdio.h>
#include <string.h>
#include "manager.h"

void listProduct(Product *p, int count){
    for(int i=0 ; i<count ; i++){
        if(p[i].price==-1) continue;
        readProduct(p[i]);
    }
}

int selectDataNo(Product *p, int count){
    int no;
    listProduct(p,count);
    printf("\n번호 (취소:0)? ");
    scanf("%d",&no);
    return no;
}

