#include <stdio.h>
  
typedef struct{
    char name[50]; //제품 이름
    char origin[20]; //제품 원산지
    char des[100]; //제품 설명
    char weight[10]; //제품 중량
    int price; //판매 가격
    int dil; //배송방법(1:새벽배송 /2:택배배송)  
} Product;

void ClearReadBuffer(void); //입력버퍼 비우는 함수

//CRUD에 필요한 함수 정의
int createProduct(Product *p); // 제품 1개 추가 
void readProduct(Product p); // 제품 1개 출력 
void updateProduct(Product *p); // 제품 1개 업데이트
int deleteProduct(Product *p); // 제품 1개 삭제

