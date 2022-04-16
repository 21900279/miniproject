#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    int price, way;
    char name[40], expl[100], weight[10], origin[10], origin2[10];
} Product;
void createProduct1(Product *p);
void readProduct(Product *p);
void searchProduct1(Product *p, char name[40]);
void searchProduct2(Product *p, char origin[10]);
void searchProduct3(Product *p, int way);
void updateProduct1(Product *p);
int selectMenu();
