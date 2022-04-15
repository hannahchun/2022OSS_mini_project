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

void searchPrice(Product *p, int count){
    int scnt=0;
    int searchprice=0;
    ClearReadBuffer();
    printf("검색할 과일 가격? ");
    scanf("%d",&searchprice);

    for(int i=0 ; i<count ; i++){
        if(p[i].price==-1) continue;
        if(p[i].price==searchprice){
            readProduct(p[i]);
            scnt++;
        }
    }
    if(scnt==0) printf("\n=>검색된 데이터 없음!\n");
}

void saveData(Product *p, int count){
    FILE *fp;
    fp=fopen("fruit.txt","wt");

    for(int i=0 ; i<count ; i++){
        if(p[i].price==-1) continue;
        fprintf(fp,"%s ",p[i].origin);
        fputs(p[i].name,fp);
        fputs("\n",fp);
        fputs(p[i].des,fp);
        fputs("\n",fp);
        fprintf(fp,"%s %d ",p[i].weight,p[i].price);
        if(p[i].dil==1)
            fputs("새벽 배송\n",fp);
        if(p[i].dil==2)
            fputs("택배 배송\n",fp);
    }
    fclose(fp);
    printf("\n저장됨!\n");
}

