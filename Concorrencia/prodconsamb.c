#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <pthread.h>
#include <stdlib.h>

int max;
int loops;
int *buffer1, *buffer2;

int consome1 = 0;
int produz1 = 0;
int consome2 = 0;
int produz2 = 0;

#define MAX (10)
int consumidores = 1;
int produtores = 1;
int nambos = 1;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex3 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond3 = PTHREAD_COND_INITIALIZER;
int controle = 0;
int fim = 0;

void produz(int valor, int buf) {
   if (buf == 1) {
      buffer1[produz1] = valor;
      produz1 = (produz1 + 1) % max;
   } else {
      buffer2[produz2] = valor;
      produz2 = (produz2 + 1) % max;
   }
}

int consome(int buf) {
   int tmp;
   if (buf == 1) {
      tmp = buffer1[consome1];
      consome1 = (consome1 + 1) % max;
   } else {
      tmp = buffer2[consome2];
      consome2 = (consome2 + 1) % max;
   }

   return tmp;
}

void *produtor(void *arg) {
   int i;
   for (i = 0; i < loops; i++) {
      pthread_mutex_lock(&mutex1);
      while ((produz1 + 1) % max == consome1) {
         pthread_cond_wait(&cond1, &mutex1);
      }
      produz(i, 1);
      printf("Produtor %lld produziu %d em 1\n", (long long int)arg, i);
      pthread_mutex_unlock(&mutex1);
      pthread_cond_signal(&cond1);
   }
   printf("Produtor %d finalizado\n", *((int *)arg));
   return NULL;
}

void *consumidor(void *arg) {
   int tmp = 0;
   while (1) {
      pthread_mutex_lock(&mutex2);
      while (produz2 == consome2) {
         pthread_cond_wait(&cond2, &mutex2);
      }
      tmp = consome(2);
      printf("Consumidor %lld consumiu %d de 2\n", (long long int)arg, tmp);
      pthread_mutex_unlock(&mutex2);
      pthread_cond_signal(&cond2);
      pthread_mutex_lock(&mutex3);
      controle++;
      if (controle == loops * produtores) {
         pthread_cond_broadcast(&cond3);
         fim = 1;
      }
      pthread_mutex_unlock(&mutex3);
      if (fim == 1) {
         printf("Consumidor %lld finalizado\n", (long long int)arg);
         pthread_exit(NULL);
      }
   }
   return NULL;
}

void *ambos(void *arg) {
   int tmp = 0;
   while (1) {
      pthread_mutex_lock(&mutex1);
      while (produz1 == consome1) {
         pthread_cond_wait(&cond1, &mutex1);
      }
      tmp = consome(1);
      printf("Ambos %lld consumiu %d em 1\n", (long long int)arg, tmp);
      pthread_mutex_unlock(&mutex1);
      pthread_cond_signal(&cond1);
      pthread_mutex_lock(&mutex2);
      while ((produz2 + 1) % max == consome2) {
         pthread_cond_wait(&cond2, &mutex2);
      }
      produz(tmp, 2);
      printf("Ambos %lld produziu %d em 2\n", (long long int)arg, tmp);
      pthread_mutex_unlock(&mutex2);
      pthread_cond_signal(&cond2);
      if (fim == 1) {
         printf("Ambos %lld finalizado\n", (long long int)arg);
         pthread_exit(NULL);
      }
   }
   return NULL;
}

int main(int argc, char *argv[]) {
   if (argc != 6) {
      fprintf(stderr, "uso: %s <tambuffer> <loops> <produtores> <consumidores> <ambos>\n", argv[0]);
      exit(1);
   }
   max = atoi(argv[1]);
   loops = atoi(argv[2]);
   produtores = atoi(argv[3]);
   consumidores = atoi(argv[4]);
   nambos = atoi(argv[5]);
   assert(consumidores <= MAX);

   buffer1 = (int *)malloc(max * sizeof(int));
   buffer2 = (int *)malloc(max * sizeof(int));
   int i;
   for (i = 0; i < max; i++) {
      buffer1[i] = 0;
      buffer2[i] = 0;
   }

   int *args = (int *)calloc(produtores + consumidores + nambos, sizeof(int));
   for (i = 0; i < produtores + consumidores + nambos; i++) {
      args[i] = i;
   }

   pthread_t pid[MAX], cid[MAX], aid[MAX];
   for (i = 0; i < consumidores; i++) {
      pthread_create(&cid[i], NULL, consumidor, (void *)&args[i]);
   }
   for (i = 0; i < nambos; i++) {
      pthread_create(&aid[i], NULL, ambos, (void *)&args[i + consumidores]);
   }

   for (i = 0; i < produtores; i++) {
      if (i + consumidores + nambos >= produtores + consumidores + nambos) {
         args = realloc(args, (i + consumidores + nambos + 1) * sizeof(int));
         if (args == NULL) {
            printf("Erro ao alocar memória\n");
            exit(1);
         }
      }
      pthread_create(&pid[i], NULL, produtor, (void *)&args[i + consumidores + nambos]);
   }

   pthread_mutex_lock(&mutex3);
   while (controle < loops * produtores) {
      pthread_cond_wait(&cond3, &mutex3);
   }
   pthread_mutex_unlock(&mutex3);

   for (i = 0; i < nambos; i++) {
      pthread_cancel(cid[i]);
      pthread_cancel(aid[i]);
   }

   free(args);
   return 0;
}
