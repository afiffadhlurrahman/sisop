# Semangat sisop

![GitHub Logo](/images/logo.png)

## Soal 2

## Penyelesaian no 2
### Server
```c
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define MAXCHAR 1000
#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    
    FILE *file; 
    char *fname;
    char c;
    fname = "akun.txt";

    int flag = 0;

    char str[MAXCHAR];    
    // char *hello = "Hello from server";
      
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
      
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
      
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    valread = read( new_socket , buffer, 1024);
    printf("%s\n",buffer);
    if(strcmp(buffer,"login")==0){
        file = fopen(fname, "r");
        valread = read( new_socket , buffer, 1024);
        while (fgets(str, MAXCHAR, file) != NULL){
            if(strcmp(str,buffer) == 0){
                printf("Auth success\n");
                flag = 1;
            }
        }
        if(flag == 0){
            printf("Auth Failed\n");
        }
        send(new_socket , &flag , sizeof(flag) , 0 );
    }
    else if(strcmp(buffer,"register")==0){
        file = fopen(fname, "r+");
        valread = read( new_socket , buffer, 1024);
        c = fgetc(file); 
        while (c != EOF) 
        { 
            printf ("%c", c); 
            c = fgetc(file); 
        }

        printf("%s",buffer);
        fprintf(file,"%s\n",buffer);
    }
    
    fclose(file);
    return 0;
}

```
### Client
```c
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8080
#define MAXCHAR 1000 

int main(int argc, char const *argv[]) {
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
  
    memset(&serv_addr, '0', sizeof(serv_addr));
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
      
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
  
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    FILE *file; 
    char *fname;
    int flag,reg = 0;
    int cek = 0;
    
    char user[30],pass[30],choice[20];
    char str[MAXCHAR],hello[1000];
    char cekUser[30],cekPass[30];
    
    printf("1. login\n");
    printf("2. register\n");
    printf("choice:");
    scanf("%s",choice);
    send(sock , choice , strlen(choice) , 0 );

    if(strcmp(choice,"login")==0){
        cek = 2;
    }
    else if(strcmp(choice,"register")==0){
        cek = 1;
    }
    
    if(cek==2){
        printf("username: ");
        scanf("\n%[^\n]%*c",cekUser);
        printf("password: ");
        scanf("\n%[^\n]%*c",cekPass);

        sprintf(hello, "username: %s password: %s\n", cekUser, cekPass);
        send(sock , &hello , strlen(hello) , 0 );
        valread = read( sock , &flag, sizeof(flag));
        if(flag == 1){
            printf("login success\n");
        }
        
        if(flag == 0){
            printf("login failed\n");
        }
    }
    else if(cek == 1){
        printf("username: ");
        scanf("\n%[^\n]%*c",user);
        printf("password: ");
        scanf("\n%[^\n]%*c",pass);

        sprintf(hello, "username: %s password: %s\n", user, pass);
        send(sock , &hello , strlen(hello) , 0 );

        printf("register success\n");
        reg = 1;
        send(sock , &reg , sizeof(reg) , 0 );
    }
    
    return 0;
}
```

## Soal 4

## Penyelesaian no 4
### 4.A
```C
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <pthread.h>

#define M 4
#define K 2
#define N 5
#define NUM_THREADS M * N

/* Global variables for threads to share */
int A[M][K] = {{1, 4}, {2, 5}, {3, 5}, {2,3}};
int B[K][N] = {{8, 7, 6, 1, 2}, {5, 4, 3, 2, 1}};
int C[M][N];

/* Structure for passing data to threads */
struct v
{
    int i; /* row */
    int j; /* column */
};

void *runner(void *ptr); /* the thread */

void main()
{   
    int i, j;
    int thread_counter = 0;
    
    pthread_t workers[NUM_THREADS];
    
    /* create M * N worker threads */
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++) 
        {
            struct v *data = (struct v *) malloc(sizeof(struct v));
            data->i = i;
            data->j = j;
            /* create the thread passing it data as a paramater*/
            pthread_create(&workers[thread_counter], NULL, runner, data);
            pthread_join(workers[thread_counter], NULL);
            thread_counter++;
        }
    }
    
    /* Waiting for threads to complete */
    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(workers[i], NULL);
    }

    //shared memory
    key_t key = 1234;
    int *share[M][N];
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            share[i][j] = shmat(shmid, NULL, 0);
        }
    }

    for(i = 0; i < M; i++)
    { 
        for(j = 0; j < N; j++)
        { 
            *share[i][j] = C[i][j];
            printf("%d\t", *share[i][j]);\
            sleep(2);
        }
        printf("\n");
    }

    for(int i = 0;i < M;i++){
        for(int j = 0;j < N;j++){
            shmdt(share[i][j]);
        }
    }
    shmctl(shmid, IPC_RMID, NULL);  
}

void *runner(void *ptr)
{    
    /* Casting paramater to struct v pointer */
    struct v *data = ptr;
    int i, sum = 0;
    
    for(i = 0; i < K; i++)
    {    
        sum += A[data->i][i] * B[i][data->j];
    }
    
    C[data->i][data->j] = sum;
    pthread_exit(0);
}
```
### 4.B
```C
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <pthread.h>

#define M 4
#define N 5
#define NUM_THREADS M * N

int hasil[M][N];

struct v
{
    int i; /* row */
    int j; /* column */
};

void *runner1(void *ptr);

void main()
{
    int i, j;
    int thread_counter = 0;
    pthread_t workers[NUM_THREADS];

    key_t key = 1234;
    int *A[M][N];
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            A[i][j] = shmat(shmid, NULL, 0);
        }
    }

    for(int i = 0;i<M;i++){
        for(int j=0;j<N;j++){
            hasil[i][j]=*A[i][j];
            sleep(2);
        }
    }

    for(int i = 0;i<M;i++){
        for(int j=0;j<N;j++){
            struct v *data = (struct v *) malloc(sizeof(struct v));
            data->i = i;
            data->j = j;
            /* create the thread passing it data as a paramater*/
            pthread_create(&workers[thread_counter], NULL, runner1, data);
            pthread_join(workers[thread_counter], NULL);
            thread_counter++;
        }
    }

    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(workers[i], NULL);
    }

    for(int i = 0;i < M;i++){
        for(int j = 0;j < N;j++){
            printf("%d\t",hasil[i][j]);
        }
        printf("\n");
    }

    for(int i = 0;i < M;i++){
        for(int j = 0;j < N;j++){
            shmdt(A[i][j]);   
        }
    } 
    shmctl(shmid, IPC_RMID, NULL);
}

void *runner1(void *ptr)
{    
    /* Casting paramater to struct v pointer */
    struct v *data = ptr;
    int i, sum = 0;
    
    for(i = 1; i <= hasil[data->i][data->j]; i++)
    {    
        sum += i;
    }
    
    hasil[data->i][data->j] = sum;
    pthread_exit(0);
}
```
### 4.C
```C
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t child_id;
    int status;
    int pip[2];
    int pip2[2];

    if (pipe(pip) < 0) {
        fprintf(stderr, "Pipe Failed");
        exit(1);
    }

    if (pipe(pip2) < 0) {
        fprintf(stderr, "Pipe Failed");
        exit(1);
    }

    child_id = fork();
    if (child_id < 0) {
    exit(EXIT_FAILURE);
    }

    if (child_id == 0) {
        // this is child
        close(pip[0]);
        dup2(pip[1], STDOUT_FILENO);
    
        char *argv[] = {"ls", NULL};
        execv("/bin/ls", argv);
    } else {
        // this is parent
        while ((wait(&status)) > 0);
        close(pip[1]);
        dup2(pip[0], STDIN_FILENO);
        
        char *argv[] = {"wc", "-l", NULL};
        execv("/usr/bin/wc", argv);
    }
}
```
