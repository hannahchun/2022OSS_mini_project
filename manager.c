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

int loadData(Product *p){
    int i=0;
    char tmp[20];
    FILE *fp;
    fp=fopen("fruit.txt","rt");
    if(fp==NULL)
        return 0;

    for(i=0 ; i<100 ; i++){
        //origin
        int ret=fscanf(fp,"%s ",p[i].origin);
        if(ret==EOF)
            break;
        //name
        fgets(p[i].name,sizeof(p[i].name),fp);
        p[i].name[strlen(p[i].name)-1]='\0';
        //description
        fgets(p[i].des, sizeof(p[i].des),fp);
        p[i].des[strlen(p[i].des)-1]='\0';
        //weight, price
        fscanf(fp,"%s %d ",p[i].weight, &p[i].price);
        //size
        fgets(tmp, sizeof(tmp),fp);
        if(strcmp(tmp,"새벽 배송"))
            p[i].dil=1;
        if(strcmp(tmp,"택배 배송"))
            p[i].dil=2;
    }
    fclose(fp);
    printf("\n=>로딩 성공!\n");
    return i;
}

