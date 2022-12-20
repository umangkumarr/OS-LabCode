#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex;
sem_t db;
int readerCount = 0;
pthread_t reader1, reader2, writer1, writer2;
void *reader(void *);
void *writer(void *);
int cnt = 50;
int main()
{
    sem_init(&mutex, 0, 1);
    sem_init(&db, 0, 1);
    while (cnt>0)
    {
        pthread_create(&reader1, NULL, reader, "1");
        pthread_create(&reader2, NULL, reader, "2");
        pthread_create(&writer1, NULL, writer, "1");
        pthread_create(&writer2, NULL, writer, "2");
    }
}
void *reader(void *p)
{
    cnt--;
    printf("prevoius value %d \n", mutex);
    sem_wait(&mutex);
    printf("Mutex acquired by reader %d \n", mutex);
    readerCount++;
    if (readerCount == 1)
        sem_wait(&db);
    sem_post(&mutex);
    printf("Mutex returned by reader %d \n", mutex);
    printf("Reader %s is Reading \n", p);
    
    sem_wait(&mutex);
    printf("Reader %s Completed Reading \n", p);
    readerCount--;
    if (readerCount == 0)
        sem_post(&db);
    sem_post(&mutex);
}

void *writer(void *p)
{
    cnt--;
    printf("Writer is Waiting \n");
    sem_wait(&db);
    printf("Writer %s is writing \n", p);
    sem_post(&db);
     
}

// Reader 1: read cnt as 1
// Reader -1248053576: read cnt as 1
// Reader 3: read cnt as 1
// Reader 2: read cnt as 1
// Reader 1: read cnt as 1
// Reader 4: read cnt as 1
// Reader 5: read cnt as 1
// Reader 32759: read cnt as 1
// Reader 209551360: read cnt as 1
// Reader 1: read cnt as 1
// Writer 1 modified cnt to 2
// Writer 2 modified cnt to 4
// Writer 5 modified cnt to 32
// Writer 3 modified cnt to 8
// Writer 4 modified cnt to 16