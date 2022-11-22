<h1 align="center">Assignment 7</h1>

#### **_7a - Write Read_**

###### **Code**

`7a_writer.c`

```c
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
```

`7a_reader.c`

```c
// C program to implement one side of FIFO
// This side reads first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd1, sen, wor;

    // FIFO file path
    char *myfifo = "/tmp/myfifo";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    mkfifo(myfifo, 0666);
    printf("----------------\nUser 2 Area\n----------------\n\n");

    char str1[180], str2[180];
    while (1)
    {
        // First open in read only and read
        printf("-----------------\nWaiting for User 1...\n");
        fd1 = open(myfifo, O_RDONLY);
        read(fd1, str1, 180);

        // Print the read string and close
        printf("\tUser 1 sent : %s\n", str1);
        close(fd1);

        // Counting sentences and words
        sen = 0;
        wor = 0;

        for (int i = 0; str1[i] != '\0'; i++)
        {
            if (str1[i] == ' ')
                wor++;
            if (str1[i] == '.')
                sen++;
        }

        sprintf(str2, "Words : %d Sentences : %d", ++wor, sen);

        // Now open in write mode and write
        // string taken from user.
        fd1 = open(myfifo, O_WRONLY);
        printf("\n\t>>>> Sending stats to User 1");
        write(fd1, str2, strlen(str2) + 1);
        printf("\n\t>>>> Sent!\n---------------------\n\n");
        close(fd1);
    }

    return 0;
}
```

###### **Output**

```text
Terminal 1 (7a_writer.c) - 
abhishek-jadhav@abhishek-jadhav-ubuntu:~/Codes/TE-SEM5-Assignments/OSL/Assignment 7/7a$ ./pipe1
----------------
User 1 Area
----------------

----------------
User 1 -
	Enter message (press enter to stop): Hey User 2 :)

	>>>> User 1 waiting for User 2 to write stats in pipe
	Stats received from User 2 : Words : 4 Sentences : 0
-----------------

----------------
User 1 -
	Enter message (press enter to stop): My first sentence. And, this is my second sentence.

	>>>> User 1 waiting for User 2 to write stats in pipe
	Stats received from User 2 : Words : 9 Sentences : 2
-----------------

----------------
User 1 -
	Enter message (press enter to stop): ^C
```
```text
Terminal 2 (7a_reader.c) -
abhishek-jadhav@abhishek-jadhav-ubuntu:~/Codes/TE-SEM5-Assignments/OSL/Assignment 7/7a$ ./pipe2
----------------
User 2 Area
----------------

-----------------
Waiting for User 1...
	User 1 sent : 'Hey User 2 :)
'

	>>>> Sending stats to User 1
	>>>> Sent!
---------------------

-----------------
Waiting for User 1...
	User 1 sent : 'My first sentence. And, this is my second sentence.
'

	>>>> Sending stats to User 1
	>>>> Sent!
---------------------

-----------------
Waiting for User 1...
^C
```

---

#### **_7b - Shared Memory_**

###### **Code**

`7b_client.c`

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
int main()
{
	int i;
	void *shared_memory;
	char buff[100];
	int shmid;
	shmid = shmget((key_t)2345, 1024, 0666);
	printf("Key: %d\n", shmid);
	shared_memory = shmat(shmid, NULL, 0);
	printf("Process attached at %p\n", shared_memory);
	printf("Data read from shared memory is : %s\n", (char *)shared_memory);
}
```

`7b_server.c`

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
int main()
{
    int i;
    void *shared_memory;
    char buff[100];
    int shmid;
    shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT);

    printf("Key of shared memory is %d\n", shmid);
    shared_memory = shmat(shmid, NULL, 0);
    printf("Process attached at %p\n", shared_memory);
    printf("Enter some data to write to shared memory\n");
    read(0, buff, 100);
    strcpy(shared_memory, buff);
    printf("You wrote : %s\n", (char *)shared_memory);
}
```

###### **Output**

```text
abhishek-jadhav@abhishek-jadhav-ubuntu:~/Codes/OS Assignments/33232$ ./b.out
Key of shared memory is 10
Process attached at 0x7fd268b74000
Enter some data to write to shared memory
Data shared with a
You wrote : Data shared with a


abhishek-jadhav@abhishek-jadhav-ubuntu:~/Codes/OS Assignments/33232$ ./a.out
Key: 10
Process attached at 0x7f3795a0c000
Data read from shared memory is : Data shared with a
```
