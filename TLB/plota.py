#!/usr/bin/env python3

import sys
import matplotlib
matplotlib.use('TkAgg') 
import matplotlib.pyplot as plt
import numpy as np


#data = np.loadtxt(sys.argv[1], delimiter=' ', skiprows=1, converters={i: lambda s: float(s.strip()) if s.strip() else np.nan for i in range(2)}) # carrega os dados do arquivo usando '|' como delimitador, pulando a primeira linha e convertendo os valores ausentes para np.nan
data = np.loadtxt(sys.argv[1], delimiter=' ', skiprows=1)

x = data[:,0] 
y = data[:,1] 
plt.plot(x, y) 
plt.xlabel("Numero de Paginas") 
plt.ylabel("Tempo") 
plt.show() 
