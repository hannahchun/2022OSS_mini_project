#include <stdio.h>
#include "product.h"

int selectMenu(); // 메뉴 선택

void listProduct(Product *p, int count); //제품 목록 출력하기 
int selectDataNo(Product *p, int count); //수정, 삭제 위한 제품 선택

//File 저장 / File에서 데이터 불러오는 함수 정의
int loadData(Product *p); // 제품 목록 파일 읽어오기
void saveData(Product *p, int count); // 제품 목록을 파일에 저장

//검색기능(3개 이상 자율적으로 기능 정의)
void searchOrigin(Product *p, int count); // 제품 원산지로 검색
void searchName(Product *p, int count); // 제품 이름으로 검색
void searchPrice(Product *p, int count); // 제품 가격으로 검색 

