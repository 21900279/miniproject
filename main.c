#include "manager.h"
int main() {
    #ifdef DEBUG
    printf("Debug_Mode\n");
    #endif
    Product *p[20];
    int count = 0, menu;
    while(1) {
        
        menu = selectMenu();
        if (menu == 0) break;
        else if(menu == 1) {
            int a;
            printf("조회할 제품 번호는? ");
            scanf("%d", &a);
            if(a < count+1 && a>0 && p[a]->price != -1) readProduct(p[a-1]);
            else printf("잘못된 번호 또는 데이터가 없습니다.\n\n");
        }
        else if(menu == 2) {
            listProduct(p, count);
        }
        else if(menu == 3) {
            createProduct(p, count);
            count++;
        }
        else if(menu == 4) {
            updateProduct(p, count);
        }
        else if(menu == 5) {
            searchProduct(p, count);
        }
        else if(menu == 6) {
            deleteProduct(p, count);
        }
        else if(menu == 7) {
            saveFile(p, count);
        }
        else if(menu == 8) {
            count = loadFile(p);
        }
    }
    printf("종료됨!\n");
    for(int i=0; i<count; i++) {
        free(p[i]);
    }
    return 0;
}
