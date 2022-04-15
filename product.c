#include <stdio.h>
#include <string.h>
#include "product.h"

void ClearReadBuffer(void) {
    while (getchar() != '\n');
}

void readProduct(Product p){
    printf("*****************\n");
    if(p.price==-1)
        return;
    printf("[%6s] %s \n",p.origin,p.name);
    printf("%s \n",p.des);
    printf("%s\n",p.weight);
    printf("%d원\n",p.price);
    if(p.dil==1)
        printf("새벽 배송\n");
    if(p.dil==2)
        printf("택배 배송\n");
}

int createProduct(Product *p){
    ClearReadBuffer();
    printf("과일 이름은? ");
    fgets(p->name,sizeof(p->name),stdin);
    p->name[strlen(p->name)-1]='\0';
    printf("과일 원산지는? ");
    scanf("%s",p->origin);
    ClearReadBuffer();
    printf("과일 설명은? ");
    fgets(p->des,sizeof(p->des),stdin);
    p->des[strlen(p->des)-1]='\0';
    printf("과일 중량은? ");
    scanf("%s",p->weight);
    printf("과일 가격은? ");
    scanf("%d",&p->price);
    printf("과일 배송방법은?(1:새벽배송 /2:택배배송)");
    scanf("%d",&p->dil);
    printf("\n=>추가 성공\n");
    return 1;
}

void updateProduct(Product *p){
    ClearReadBuffer();
    printf("새 과일 이름은? ");
    fgets(p->name,sizeof(p->name),stdin);
    p->name[strlen(p->name)-1]='\0';
    printf("새 과일 원산지는? ");
    scanf("%s",p->origin);
    ClearReadBuffer();
    printf("새 과일 설명은? ");
    fgets(p->des,sizeof(p->des),stdin);
    p->des[strlen(p->des)-1]='\0';
    printf("새 과일 중량은? ");
    scanf("%s",p->weight);
    printf("새 과일 가격은? ");
    scanf("%d",&p->price);
    printf("새 과일 배송방법은?(1:새벽배송 /2:택배배송)");
    scanf("%d",&p->dil);
    printf("\n=>수정 성공\n");
}

int deleteProduct(Product *p){
    p->price=-1;
    printf("\n=>삭제 성공\n");
    return 1;
}

