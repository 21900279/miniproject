#include "product.h"

void createProduct1(Product *p) {
    printf("제품명은? ");
    while(getchar()!='\n');
    scanf("%[^\n]", p->name);
    printf("원산지는? ");
    while(getchar()!='\n');
    scanf("%s %s", p->origin2, p->origin);
    printf("중량은? ");
    scanf("%s", p->weight);
    printf("가격은? ");
    scanf("%d", &p->price);
    printf("배송 방법은? (1:새벽배송 / 2:택배배송) ");
    scanf("%d", &p->way);
    printf("제품 설명? ");
    while(getchar()!='\n');
    scanf("%[^\n]", p->expl);
    while(getchar()!='\n');
    printf("추가됨!\n\n");
}
void readProduct(Product *p) {
    printf("[%s] %s %s\n%s\n%d원\n", p->origin, p->name, p->weight, p->expl, p->price);
    printf("구매혜택\t회원 적립금:+%d원(상품:%d원)\n", p->price/100, p->price/100);
    printf("원산지\t\t%s %s\n", p->origin2, p->origin);
    printf("배송방법\t");
    if(p->way == 1) printf("새벽배송\n\n");
    else if(p->way == 2) printf("택배배송\n\n");
}

void searchProduct1(Product *p, char name[40]) {
    if(strstr(p->name, name) != NULL) {
        if (p->price != -1) readProduct(p);
    }
}
void searchProduct2(Product *p, char origin[10]) {
    if(strcmp(p->origin, origin) == 0 || strcmp(p->origin2, origin) == 0) {
        if (p->price != -1) readProduct(p);
    }
}
void searchProduct3(Product *p, int way) {
    if(p->way == way) {
        if (p->price != -1) readProduct(p);
    }
}
void updateProduct1(Product *p) {
    printf("제품 명은? ");
    while(getchar()!='\n');
    scanf("%[^\n]", p->name);
    printf("원산지는? ");
    while(getchar()!='\n');
    scanf("%s %s", p->origin2, p->origin);
    printf("중량은? ");
    scanf("%s", p->weight);
    printf("가격은? ");
    scanf("%d", &p->price);
    printf("배송 방법은? (1:새벽배송 / 2:택배배송)");
    scanf("%d", &p->way);
    printf("제품 설명? ");
    while(getchar()!='\n');
    scanf("%[^\n]", p->expl);
    while(getchar()!='\n');
    printf("수정됨!\n\n");
}

int selectMenu() {
    int menu;
    printf("1. 조회\n");
    printf("2. 전체조회\n");
    printf("3. 추가\n");
    printf("4. 수정\n");
    printf("5. 검색\n");
    printf("6. 삭제\n");
    printf("7. 파일 저장\n");
    printf("8. 파일 불러오기\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}


