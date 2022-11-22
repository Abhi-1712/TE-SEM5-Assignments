// C program to implement one side of FIFO
// This side writes first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;

    // FIFO file path
    char *myfifo = "/tmp/myfifo";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    mkfifo(myfifo, 0666);
    printf("----------------\nUser 1 Area\n----------------\n\n");

    char arr1[180], arr2[180];
    while (1)
    {
        // Open FIFO for write only
        fd = open(myfifo, O_WRONLY);

        // Take an input arr2ing from user.
        // 80 is maximum length
        printf("----------------\nUser 1 -\n\tEnter message (press enter to stop): ");
        fgets(arr2, 180, stdin);

        // Write the input arr2ing on FIFO
        // and close it
        write(fd, arr2, strlen(arr2) + 1);
        close(fd);
        printf("\n\t>>>> User 1 waiting for User 2 to write stats in pipe\n");
	sleep(5);
        // Open FIFO for Read only
        fd = open(myfifo, O_RDONLY);

        // Read from FIFO
        read(fd, arr1, sizeof(arr1));

        // Print the read message
        printf("\tStats received from User 2 : %s\n-----------------\n\n", arr1);
        close(fd);
    }
    return 0;
}
