#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sched.h> 

#define PAGESIZE 4096

// calcula a diferença entre os tempos
long int time_diff(struct timeval *start, struct timeval *end) {
  return (end->tv_sec - start->tv_sec) * 1000000L + (end->tv_usec - start->tv_usec);
}

int main(int argc, char *argv[]) {
  cpu_set_t mask; 
  CPU_ZERO(&mask); 
  CPU_SET(0, &mask); 
  sched_setaffinity(0, sizeof(cpu_set_t), &mask); // faz com que o processo rode sempre no core 0

  int *v; 
  int salto; 
  int npags; 
  int iters; 
  struct timeval inicio, fim; 
  long int tempo; 
  float tempo_medio; 
  int i, j; 

  if (argc != 3) { 
    printf("Uso: %s <numero de paginas> <numero de iteracoes>\n", argv[0]);
    exit(1);
  }

  npags = atoi(argv[1]); 
  iters = atoi(argv[2]); 

  salto = PAGESIZE / sizeof(int); // calcula o número de inteiros por página
  v = malloc(npags * salto * sizeof(int)); 

  if (v == NULL) { 
    printf("Erro ao alocar memória\n");
    exit(2);
  }

  srand(time(NULL)); 

  for (i = 0; i < npags * salto; i++) { 
    v[i] = rand();
  }

  gettimeofday(&inicio, NULL); 

  for (i = 0; i < iters; i++) { 
    for (j = 0; j < npags * salto; j += salto) { // posição das página no vetor
      v[j] *= 2; 
    }
  }

  gettimeofday(&fim, NULL); 

  tempo = time_diff(&inicio, &fim); 
  tempo_medio = (float)tempo / (npags * iters); 

  printf("Tempo total: %ld us\n", tempo); 
  printf("Tempo médio por acesso: %.7f us\n", tempo_medio); 
  free(v); 

  return 0;
}
