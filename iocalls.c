#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
int main()
{
    int c = 99, fd, sz;
    char *c1 = (char *)calloc(100, sizeof(char));
    while (c != 0)
    {
        printf("CHOOSE OPERATION\n");
        printf("1. Create\n");
        printf("2. Open\n");
        printf("3. Close\n");
        printf("4. Write\n");
        printf("5. Read\n");
        printf("6. Exit\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            fd = creat("f1.txt", 0777);
            printf("fd=%d\n", fd);
            close(fd);
            break;
        case 2:
            fd = open("f1.txt", O_RDONLY | O_CREAT, 0777);
            printf("Opened the file with fd=%d\n", fd);
            close(fd);
            break;
        case 3:
            close(fd);
            printf("Closed the file with fd=%d\n", fd);
            break;
        case 4:
            fd = open("f1.txt", O_WRONLY | O_CREAT, 0777);
            sz = write(fd, "hi,hello\n", strlen("hi,hello\n"));
            close(fd);
            break;
        case 5:
            fd = open("f1.txt", O_RDONLY);
            sz = read(fd, c1, 10);
            printf("Size of character string sz=%d\n", sz);
            printf("fd=%d\n", fd);
            c1[sz] = '\0';
            printf("Content in the file is %s\n", c1);
            close(fd);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid option, please choose again.\n");
        }
    }
    free(c1);
    return 0;
}
