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

void searchName(Product *p, int count){
    int scnt=0;
    char searchname[20];
    ClearReadBuffer();
    printf("\n검색할 과일 이름? ");
    fgets(searchname,sizeof(searchname),stdin);
    searchname[strlen(searchname)-1]='\0';

    for(int i=0 ; i<count ; i++){
        if(p[i].price==-1) continue;
        if(strstr(p[i].name, searchname)){
            printf("\n");
            readProduct(p[i]);
            scnt++;
        }
    }
    if(scnt==0) printf("\n=>검색된 데이터 없음!\n");
}

void searchOrigin(Product *p, int count){
    int scnt=0;
    char searchorigin[20];
    ClearReadBuffer();
    printf("검색할 과일 원산지? ");
    scanf("%s",searchorigin);

    for(int i=0 ; i<count ; i++){
        if(p[i].price==-1) continue;
        if(strstr(p[i].origin, searchorigin)){
            readProduct(p[i]);
            scnt++;
        }
    }
    if(scnt==0) printf("\n=>검색된 데이터 없음!\n");
}

