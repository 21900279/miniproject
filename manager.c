#include "manager.h"
void listProduct(Product *p[], int count) {
    #ifdef DEBUG
    printf("-제품 조회-\n");
    #endif
    for(int i=0; i<count; i++) {
        if(p[i]->price != -1) {
            printf("%d\n", i+1);
            readProduct(p[i]);
        }
    }
    if(count == 0) printf("데이터가 없습니다.\n\n");
}

void createProduct(Product *p[], int count) { 
    #ifdef DEBUG
    printf("-제품 추가-\n");
    #endif
    p[count]=(Product*)malloc(sizeof(Product));
    createProduct1(p[count]);
}

void searchProduct(Product *p[], int count) {
    #ifdef DEBUG
    printf("-제품 검색-\n");
    #endif
    printf("검색 메뉴\n");
    printf("1 : 제품명으로 검색\n");
    printf("2 : 원산지로 검색\n");
    printf("3 : 배송 방법으로 검색\n");
    printf("=> 원하는 메뉴는? ");
    int menu;
    scanf("%d", &menu);
    if(menu == 1) {
        char name[40];
        printf("제품명은? ");
        while(getchar()!='\n');
        scanf("%[^\n]", name);
        for(int i=0; i<count; i++) {
            searchProduct1(p[i], name);
        }
    }
    else if(menu == 2) {
        char origin[10];
        printf("원산지는? ");
        while(getchar()!='\n');
        scanf("%s", origin);
        for(int i=0; i<count; i++) {
            searchProduct2(p[i], origin);
        }
    }
    else {
        int way;
        printf("배송 방법은? (1:새벽배송 / 2:택배배송) ");
        scanf("%d", &way);
        for(int i=0; i<count; i++) {
            searchProduct3(p[i], way);
        }
    }
}

void updateProduct(Product *p[], int count) {
    #ifdef DEBUG
    printf("-제품 수정-\n");
    #endif
    int k;
    printf("수정할 제품 번호는? ");
    scanf("%d", &k);
    k--;
    if(k >= count || k<0) {
        printf("잘못된 번호 또는 데이터가 없습니다.\n\n");
    }
    else {
        updateProduct1(p[k]);
    }
}

int loadFile(Product *p[]) {
    FILE *fp;
    int count=0;
    if (fopen("product.txt", "rt")) {
        fp=fopen("product.txt", "rt");
        for(int i=0; i<100 ; i++) {
            if(feof(fp)!=0) break;
            p[count]=(Product*)malloc(sizeof(Product));
            fgets(p[count]->name, 40, fp);
            p[count]->name[strlen(p[count]->name)-1] = '\0';
            fscanf(fp, "%s %s", p[count]->origin2, p[count]->origin);
            fscanf(fp, "%s %d %d\n", p[i]->weight, &p[i]->price, &p[i]->way);
            fgets(p[count]->expl, 100, fp);
            if(p[i]->way == 1 || p[i]->way == 2)count ++;
            else free(p[count]);
        }
        fclose(fp);
        printf("불러오기 성공\n");
    }
    else printf("파일이 없음\n");
    return count;
}

void saveFile(Product *p[], int count) {
    FILE *fp;
    if(count == 0) {
        printf("데이터가 없음\n");
        return;
    }
    fp=fopen("product.txt", "wt");
    for(int i=0; i<count; i++) {
        if(p[i]->price != -1) {
            fprintf(fp, "%s\n%s %s\n", p[i]->name, p[i]->origin2, p[i]->origin);
            fprintf(fp, "%s %d %d\n", p[i]->weight, p[i]->price, p[i]->way);
            fprintf(fp, "%s\n", p[i]->expl);
        }
        
    }
    fclose(fp);
    printf("저장됨\n");
}

void deleteProduct(Product *p[], int count) {
    printf("삭제할 제품 번호는? ");
    int del;
    scanf("%d", &del);
    del --;
    if(del >= count || p[del]->price == -1) {
        printf("데이터가 없음\n");
        return;
    }
    p[del]->price = -1;
    printf("삭제됨\n");
}
