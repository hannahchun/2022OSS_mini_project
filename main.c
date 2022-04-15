#include <stdio.h>
#include <string.h>
#include "manager.h"

int main(){
    #ifdef DEBUG 
        printf("\nDeveloper: 전혜선(HyeSun Chun)\n");
        printf("\nLocation: 한동대학교(Handong Global University)\n");
        printf("DEBUG : %s %s %s %d\n\n",__DATE__, __TIME__,__FILE__,__LINE__);

    #endif
    Product slist[20];
    int index=0;
    int count = 0, menu;
    count=loadData(slist);
    if(count==0)
        printf("\n=>파일 없음!\n");
    index=count;
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if(menu==1 || menu==3 || menu==4 || menu==5 || menu==6)
            if(count==0) continue;
        if (menu == 1)
            listProduct(slist, index);
        else if (menu == 2)
            count+=createProduct(&slist[index++]);
        else if (menu == 3){
            int no=selectDataNo(slist,index);
            if(no==0){
                printf("=>취소됨!\n");
                continue;
            }
            updateProduct(&slist[no-1]);
        }
        else if (menu == 4){
            int no=selectDataNo(slist,index);
            if(no==0){
                printf("=>취소됨!\n");
                continue;
            }
            if(deleteProduct(&slist[no-1])) count--;
        }
        else if (menu == 5)
            saveData(slist,index);
        else if(menu==6)
            searchName(slist,index);
        else if(menu==7)
            searchPrice(slist,index);
        else if(menu==8)
            searchOrigin(slist,index);
    }
    printf("종료됨!\n");
    return 0;

}

