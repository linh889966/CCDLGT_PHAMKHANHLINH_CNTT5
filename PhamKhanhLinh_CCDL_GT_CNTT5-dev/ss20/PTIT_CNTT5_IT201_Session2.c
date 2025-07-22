#include <stdio.h>
#include <stdlib.h>

// Khai báo node của cây nhị phân
typedef struct nut {
    int duLieu;
    struct nut* trai;
    struct nut* phai;
} Nut;

// Tạo node mới
Nut* taoNut(int x) {
    Nut* p = (Nut*)malloc(sizeof(Nut));
    p->duLieu = x;
    p->trai = NULL;
    p->phai = NULL;
    return p;
}

// Duyệt tiền tự
void duyetTienTu(Nut* goc) {
    if (goc != NULL) {
        printf("%d ", goc->duLieu);
        duyetTienTu(goc->trai);
        duyetTienTu(goc->phai);
    }
}

int main() {
    // Tạo cây: 2, 3, 4, 5
    Nut* goc = taoNut(2);
    goc->trai = taoNut(3);
    goc->phai = taoNut(4);
    goc->trai->trai = taoNut(5);

    printf("Duyet tien tu: ");
    duyetTienTu(goc);

    return 0;
}
