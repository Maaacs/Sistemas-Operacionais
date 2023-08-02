## Questão 1
maxsouza@laptop:~/Documents/SO/HW-CPU-Intro$ ./process-run.py -l 5:100,5:100.
Produce a trace of what would happen when you run these processes:
Process 0
  cpu
  cpu
  cpu
  cpu
  cpu

Process 1
  cpu
  cpu
  cpu
  cpu
  cpu

Important behaviors:
  System will switch when
the current process is FINISHED or ISSUES AN IO
  After IOs, the process issuing the IO will
run LATER (when it is its turn)


## Questão 2
maxsouza@laptop:~/Documents/SO/HW-CPU-Intro$ ./process-run.py -l 4:100,1:0
Produce a trace of what would happen when you run these processes:
Process 0
  cpu
  cpu
  cpu
  cpu

Process 1
  io

Important behaviors:
  System will switch when
the current process is FINISHED or ISSUES AN IO
  After IOs, the process issuing the IO will
run LATER (when it is its turn)


## Questão 3
./process-run.py -l 1:0,4:100.
Produce a trace of what would happen when you run these processes:
Process 0
  io

Process 1
  cpu
  cpu
  cpu
  cpu

Important behaviors:
  System will switch when
the current process is FINISHED or ISSUES AN IO
  After IOs, the process issuing the IO will
run LATER (when it is its turn)

## Questão 4
maxsouza@laptop:~/Documents/SO/HW-CPU-Intro$ ./process-run.py -l 1:0,4:100 -c -S SWITCH_ON_END
Time
   PID: 0
   PID: 1
       CPU
       IOs

  1 
    RUN:io
     READY
         1
          

  2 
   WAITING
     READY
          
         1

  3 
   WAITING
     READY
          
         1

  4 
   WAITING
     READY
          
         1

  5 
   WAITING
     READY
          
         1

  6*
      DONE
   RUN:cpu
         1
          

  7 
      DONE
   RUN:cpu
         1
          

  8 
      DONE
   RUN:cpu
         1
          

  9 
      DONE
   RUN:cpu
         1


## QUESTÃO 5
maxsouza@laptop:~/Documents/SO/HW-CPU-Intro$ ./process-run.py -l 1:0,4:100 -c -S SWITCH_ON_IO
Time
   PID: 0
   PID: 1
       CPU
       IOs

  1 
    RUN:io
     READY
         1
          

  2 
   WAITING
   RUN:cpu
         1
         1

  3 
   WAITING
   RUN:cpu
         1
         1

  4 
   WAITING
   RUN:cpu
         1
         1

  5 
   WAITING
   RUN:cpu
         1
         1

  6*
      DONE
      DONE


## QUESTÃO 6

## QUESTÃO 7

## QUESTÃO 8
