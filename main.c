#include <stdio.h>
#include <windows.h>

int main() {
    int ch;
    char a[100], b[100],c[100];
    int sex[1000];
    printf("EasyDISM\n");
    printf("Please Run To Administrator!!!\n");

    for (;;) {
        printf("Choose Options\n");
        printf("1:Capture-Image, 2:Apply-Image, 3:ImageIndex, 4:Exit\n");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("ImageFile\n");
            printf(">");
            scanf("%s", a);
            printf("CaptureDir\n");
            printf(">");
            scanf("%s", b);
            printf("Name\n");
            printf(">");
            scanf("%s", c);
            sprintf(sex, "dism /Capture-Image /ImageFile:%s /CaptureDir:%s /Name:%s\n", a, b ,c);
            printf(system(sex) + "Exited...\n");
        } else if (ch == 2) {
            printf("ImageFile\n");
            printf(">");
            scanf("%s", a);
            printf("ApplyDir\n");
            printf(">");
            scanf("%s", b);
            printf("Index\n");
            printf(">");
            scanf("%s", c);
            sprintf(sex ,"dism /Apply-Image /ImageFile:%s /ApplyDir:%s /Index:%s\n", a, b, c);
            printf(system(sex) + "Exited...\n");
        } else if (ch == 3) {
            printf("ImageFile\n");
            printf(">");
            scanf("%s", a);
            sprintf(sex ,"Dism /Get-ImageInfo /ImageFile:%s\n", a);
            printf(system(sex) + "Exited...\n");
        } else if (ch == 4) {
            break;
        } else {
            printf("Error, Please Choose Options..\n");
        }
    }
    return 0;
}
