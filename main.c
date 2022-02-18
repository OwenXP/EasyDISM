#include <stdio.h>
#include <windows.h>

int main() {
    int ch, save;
    char a[100], b[100],c[100], d[100];
    int sex[1000];
    printf("EasyDISM\n");
    printf("Please Run To Administrator!!!\n");

    for (;;) {
        printf("Choose Options\n");
        printf("1:Capture-Image, 2:Apply-Image, 3:ImageIndex, 4:Mount-Image, 5:Unmount-Image, 6:Split-Image, 7:Exit\n");
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
            printf("Do you have SWM Files?(y,n)\n");
            printf(">");
            scanf("%d", &save);
            if (save == 1) {
                printf("SWMFile\n");
                printf(">");
                scanf("%s", d);
                printf("ApplyDir\n");
                printf(">");
                scanf("%s", b);
                printf("Index\n");
                printf(">");
                scanf("%s", c);
                sprintf(sex ,"dism /Apply-Image /ImageFile:%s /swmfile:%s /ApplyDir:%s /Index:%s\n", a, d, b, c);
                printf(system(sex) + "Exited...\n");
            } else if (save == 2) {
                printf("ApplyDir\n");
                printf(">");
                scanf("%s", b);
                printf("Index\n");
                printf(">");
                scanf("%s", c);
                sprintf(sex ,"dism /Apply-Image /ImageFile:%s /ApplyDir:%s /Index:%s\n", a, b, c);
                printf(system(sex) + "Exited...\n");
            } else {
                printf("Error..\n");
                break;
            }

        } else if (ch == 3) {
            printf("ImageFile\n");
            printf(">");
            scanf("%s", a);
            sprintf(sex ,"Dism /Get-ImageInfo /ImageFile:%s\n", a);
            printf(system(sex) + "Exited...\n");
        } else if (ch == 4) {
            printf("ImageFile\n");
            printf(">");
            scanf("%s", a);
            printf("Index\n");
            printf(">");
            scanf("%s", b);
            printf("MountDir\n");
            printf(">");
            scanf("%s", c);
            sprintf(sex ,"dism /Mount-Image /ImageFile:%s /Index:%s /MountDir:%s\n", a, b, c);
            printf(system(sex) + "Exited...\n");
        } else if (ch == 5) {
            printf("MountDir\n");
            printf(">");
            scanf("%s", a);
            printf("Do you want to save the changed?\n");
            printf("1:Yes\n");
            printf("2:No\n");
            printf(">");
            scanf("%d", &save);
            if (save == 1) {
                sprintf(sex ,"dism /Unmount-Image /MountDir:%s /Commit\n", a);
                printf(system(sex) + "Exited...\n");
            } else if (save == 2) {
                sprintf(sex ,"dism /Unmount-Image /MountDir:%s /Discard\n", a);
                printf(system(sex) + "Exited...\n");
            } else {
                printf("Error.. Please Choose Yes or No\n");
            }
        } else if (ch == 6) {
            printf("ImageFlie\n");
            printf(">");
            scanf("%s", a);
            printf("SWMFile\n");
            printf(">");
            scanf("%s", b);
            printf("FileSize\n");
            printf(">");
            scanf("%d", &save);
            sprintf(sex, "Dism /Split-Image /ImageFile:%s /SWMFile:%s /FileSize:%d\n", a, b, save);
            printf(system(sex) + "Exited...\n");
        } else if (ch == 7) {
            break;
        } else {
            printf("Error, Please Choose Options..\n");
        }
    }
    return 0;
}
