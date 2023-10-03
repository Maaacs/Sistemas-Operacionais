#!/bin/bash

I=10000 # número de iterações
MAX=2000 # limite máximo de paginas

echo "Tamanho da página | Tempo médio por acesso" > resultado.txt 

for ((P=1; P<=MAX; P++)) 
do
    ./tlb_c $P $I | grep "Tempo médio por acesso" | awk -v P=$P '{print P " " $5}' >> resultado.txt 
done

cat resultado.txt 
