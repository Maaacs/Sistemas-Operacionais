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
maxsouza@laptop:~/Documents/SO/HW-CPU-Intro$ ./process-run.py -l 3:0,5:100,5:100,5:100 -S SWITCH_ON_IO -I IO_RUN_LATER -c -p
Time
   PID: 0
   PID: 1
   PID: 2
   PID: 3
       CPU
       IOs

  1 
    RUN:io
     READY
     READY
     READY
         1
          

  2 
   WAITING
   RUN:cpu
     READY
     READY
         1
         1

  3 
   WAITING
   RUN:cpu
     READY
     READY
         1
         1

  4 
   WAITING
   RUN:cpu
     READY
     READY
         1
         1

  5 
   WAITING
   RUN:cpu
     READY
     READY
         1
         1

  6*
     READY
   RUN:cpu
     READY
     READY
         1
          

  7 
     READY
      DONE
   RUN:cpu
     READY
         1
          

  8 
     READY
      DONE
   RUN:cpu
     READY
         1
          

  9 
     READY
      DONE
   RUN:cpu
     READY
         1
          

 10 
     READY
      DONE
   RUN:cpu
     READY
         1
          

 11 
     READY
      DONE
   RUN:cpu
     READY
         1
          

 12 
     READY
      DONE
      DONE
   RUN:cpu
         1
          

 13 
     READY
      DONE
      DONE
   RUN:cpu
         1
          

 14 
     READY
      DONE
      DONE
   RUN:cpu
         1
          

 15 
     READY
      DONE
      DONE
   RUN:cpu
         1
          

 16 
     READY
      DONE
      DONE
   RUN:cpu
         1
          

 17 
    RUN:io
      DONE
      DONE
      DONE
         1
          

 18 
   WAITING
      DONE
      DONE
      DONE
          
         1

 19 
   WAITING
      DONE
      DONE
      DONE
          
         1

 20 
   WAITING
      DONE
      DONE
      DONE
          
         1

 21 
   WAITING
      DONE
      DONE
      DONE
          
         1

 22*
    RUN:io
      DONE
      DONE
      DONE
         1
          

 23 
   WAITING
      DONE
      DONE
      DONE
          
         1

 24 
   WAITING
      DONE
      DONE
      DONE
          
         1

 25 
   WAITING
      DONE
      DONE
      DONE
          
         1

 26 
   WAITING
      DONE
      DONE
      DONE
          
         1

 27*
      DONE
      DONE
      DONE
      DONE
          
          


Stats: Total Time 27
Stats: CPU Busy 18 (66.67%)
Stats: IO Busy  12 (44.44%)

## QUESTÃO 7
maxsouza@laptop:~/Documents/SO/HW-CPU-Intro$ ./process-run.py -l 3:0,5:100,5:100,5:100 -S SWITCH_ON_IO -I IO_RUN_IMMEDIATE -c -p
Time
   PID: 0
   PID: 1
   PID: 2
   PID: 3
       CPU
       IOs

  1 
    RUN:io
     READY
     READY
     READY
         1
          

  2 
   WAITING
   RUN:cpu
     READY
     READY
         1
         1

  3 
   WAITING
   RUN:cpu
     READY
     READY
         1
         1

  4 
   WAITING
   RUN:cpu
     READY
     READY
         1
         1

  5 
   WAITING
   RUN:cpu
     READY
     READY
         1
         1

  6*
    RUN:io
     READY
     READY
     READY
         1
          

  7 
   WAITING
   RUN:cpu
     READY
     READY
         1
         1

  8 
   WAITING
      DONE
   RUN:cpu
     READY
         1
         1

  9 
   WAITING
      DONE
   RUN:cpu
     READY
         1
         1

 10 
   WAITING
      DONE
   RUN:cpu
     READY
         1
         1

 11*
    RUN:io
      DONE
     READY
     READY
         1
          

 12 
   WAITING
      DONE
   RUN:cpu
     READY
         1
         1

 13 
   WAITING
      DONE
   RUN:cpu
     READY
         1
         1

 14 
   WAITING
      DONE
      DONE
   RUN:cpu
         1
         1

 15 
   WAITING
      DONE
      DONE
   RUN:cpu
         1
         1

 16*
      DONE
      DONE
      DONE
   RUN:cpu
         1
          

 17 
      DONE
      DONE
      DONE
   RUN:cpu
         1
          

 18 
      DONE
      DONE
      DONE
   RUN:cpu
         1
          


Stats: Total Time 18
Stats: CPU Busy 18 (100.00%)
Stats: IO Busy  12 (66.67%)

## QUESTÃO 8
*O que acontece quando você roda com esses valores com -I IO_RUN_IMMEDIATE em comparação com -I IO_RUN_LATER?*

*-s 1 -l 3:50,3:50*
maxsouza@laptop:~/Documents/SO/HW-CPU-Intro$ ./process-run.py -s 1 -l 3:50,3:50 -I IO_RUN_IMMEDIATE -c -p
Time
   PID: 0
   PID: 1
       CPU
       IOs

  1 
   RUN:cpu
     READY
         1
          

  2 
    RUN:io
     READY
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

  6 
   WAITING
      DONE
          
         1

  7*
    RUN:io
      DONE
         1
          

  8 
   WAITING
      DONE
          
         1

  9 
   WAITING
      DONE
          
         1

 10 
   WAITING
      DONE
          
         1

 11 
   WAITING
      DONE
          
         1

 12*
      DONE
      DONE
          
          


Stats: Total Time 12
Stats: CPU Busy 6 (50.00%)
Stats: IO Busy  8 (66.67%)

*-s 2 -l 3:50,3:50*
maxsouza@laptop:~/Documents/SO/HW-CPU-Intro$ ./process-run.py -s 2 -l 3:50,3:50 -I IO_RUN_IMMEDIATE -c -p
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
    RUN:io
         1
         1

  4 
   WAITING
   WAITING
          
         2

  5 
   WAITING
   WAITING
          
         2

  6*
    RUN:io
   WAITING
         1
         1

  7 
   WAITING
   WAITING
          
         2

  8*
   WAITING
    RUN:io
         1
         1

  9 
   WAITING
   WAITING
          
         2

 10 
   WAITING
   WAITING
          
         2

 11*
   RUN:cpu
   WAITING
         1
         1

 12 
      DONE
   WAITING
          
         1

 13*
      DONE
      DONE
          
          


Stats: Total Time 13
Stats: CPU Busy 6 (46.15%)
Stats: IO Busy  11 (84.62%)

*-s 3 -l 3:50,3:50*
maxsouza@laptop:~/Documents/SO/HW-CPU-Intro$ ./process-run.py -s 3 -l 3:50,3:50 -I IO_RUN_IMMEDIATE -c -p
Time
   PID: 0
   PID: 1
       CPU
       IOs

  1 
   RUN:cpu
     READY
         1
          

  2 
    RUN:io
     READY
         1
          

  3 
   WAITING
    RUN:io
         1
         1

  4 
   WAITING
   WAITING
          
         2

  5 
   WAITING
   WAITING
          
         2

  6 
   WAITING
   WAITING
          
         2

  7*
   RUN:cpu
   WAITING
         1
         1

  8*
      DONE
    RUN:io
         1
          

  9 
      DONE
   WAITING
          
         1

 10 
      DONE
   WAITING
          
         1

 11 
      DONE
   WAITING
          
         1

 12 
      DONE
   WAITING
          
         1

 13*
      DONE
   RUN:cpu
         1
          


Stats: Total Time 13
Stats: CPU Busy 6 (46.15%)
Stats: IO Busy  9 (69.23%)


*-s 1 -l 3:50,3:50*
maxsouza@laptop:~/Documents/SO/HW-CPU-Intro$ ./process-run.py -s 1 -l 3:50,3:50 -I IO_RUN_LATER -c -p
Time
   PID: 0
   PID: 1
       CPU
       IOs

  1 
   RUN:cpu
     READY
         1
          

  2 
    RUN:io
     READY
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

  6 
   WAITING
      DONE
          
         1

  7*
    RUN:io
      DONE
         1
          

  8 
   WAITING
      DONE
          
         1

  9 
   WAITING
      DONE
          
         1

 10 
   WAITING
      DONE
          
         1

 11 
   WAITING
      DONE
          
         1

 12*
      DONE
      DONE
          
          
Stats: Total Time 12
Stats: CPU Busy 6 (50.00%)
Stats: IO Busy  8 (66.67%)


*-s 2 -l 3:50,3:50*
maxsouza@laptop:~/Documents/SO/HW-CPU-Intro$ ./process-run.py -s 2 -l 3:50,3:50 -I IO_RUN_LATER -c -p
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
    RUN:io
         1
         1

  4 
   WAITING
   WAITING
          
         2

  5 
   WAITING
   WAITING
          
         2

  6*
    RUN:io
   WAITING
         1
         1

  7 
   WAITING
   WAITING
          
         2

  8*
   WAITING
    RUN:io
         1
         1

  9 
   WAITING
   WAITING
          
         2

 10 
   WAITING
   WAITING
          
         2

 11*
   RUN:cpu
   WAITING
         1
         1

 12 
      DONE
   WAITING
          
         1

 13*
      DONE
      DONE
          
          
Stats: Total Time 13
Stats: CPU Busy 6 (46.15%)
Stats: IO Busy  11 (84.62%)


*-s 3 -l 3:50,3:50*
maxsouza@laptop:~/Documents/SO/HW-CPU-Intro$ ./process-run.py -s 3 -l 3:50,3:50 -I IO_RUN_LATER -c -p
Time
   PID: 0
   PID: 1
       CPU
       IOs

  1 
   RUN:cpu
     READY
         1
          

  2 
    RUN:io
     READY
         1
          

  3 
   WAITING
    RUN:io
         1
         1

  4 
   WAITING
   WAITING
          
         2

  5 
   WAITING
   WAITING
          
         2

  6 
   WAITING
   WAITING
          
         2

  7*
   RUN:cpu
   WAITING
         1
         1

  8*
      DONE
    RUN:io
         1
          

  9 
      DONE
   WAITING
          
         1

 10 
      DONE
   WAITING
          
         1

 11 
      DONE
   WAITING
          
         1

 12 
      DONE
   WAITING
          
         1

 13*
      DONE
   RUN:cpu
         1
          
Stats: Total Time 13
Stats: CPU Busy 6 (46.15%)
Stats: IO Busy  9 (69.23%)


*O que acontece quando você roda com esses valores com -S SWITCH_ON_IO em comparação com -I SWITCH_ON_END?*

*-s 1 -l 3:50,3:50*
maxsouza@laptop:~/Documents/SO/HW-CPU-Intro$ ./process-run.py s 1 -l 3:50,3:50 -S SWITCH_ON_IO -c -p
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
    RUN:io
         1
         1

  4 
   WAITING
   WAITING
          
         2

  5 
   WAITING
   WAITING
          
         2

  6*
    RUN:io
   WAITING
         1
         1

  7 
   WAITING
   WAITING
          
         2

  8*
   WAITING
   RUN:cpu
         1
         1

  9 
   WAITING
      DONE
          
         1

 10 
   WAITING
      DONE
          
         1

 11*
   RUN:cpu
      DONE
         1
          
Stats: Total Time 11
Stats: CPU Busy 6 (54.55%)
Stats: IO Busy  9 (81.82%)

*-s 2 -l 3:50,3:50*
maxsouza@laptop:~/Documents/SO/HW-CPU-Intro$ ./process-run.py s 2 -l 3:50,3:50 -S SWITCH_ON_IO -c -p
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
    RUN:io
         1
         1

  4 
   WAITING
   WAITING
          
         2

  5 
   WAITING
   WAITING
          
         2

  6*
    RUN:io
   WAITING
         1
         1

  7 
   WAITING
   WAITING
          
         2

  8*
   WAITING
   RUN:cpu
         1
         1

  9 
   WAITING
      DONE
          
         1

 10 
   WAITING
      DONE
          
         1

 11*
   RUN:cpu
      DONE
         1
        
Stats: Total Time 11
Stats: CPU Busy 6 (54.55%)
Stats: IO Busy  9 (81.82%)

*-s 1 -l 3:50,3:50*
maxsouza@laptop:~/Documents/SO/HW-CPU-Intro$ ./process-run.py s 3 -l 3:50,3:50 -S SWITCH_ON_IO -c -p
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
    RUN:io
         1
         1

  4 
   WAITING
   WAITING
          
         2

  5 
   WAITING
   WAITING
          
         2

  6*
    RUN:io
   WAITING
         1
         1

  7 
   WAITING
   WAITING
          
         2

  8*
   WAITING
   RUN:cpu
         1
         1

  9 
   WAITING
      DONE
          
         1

 10 
   WAITING
      DONE
          
         1

 11*
   RUN:cpu
      DONE
         1
          


Stats: Total Time 11
Stats: CPU Busy 6 (54.55%)
Stats: IO Busy  9 (81.82%)


*-s 1 -l 3:50,3:50*
maxsouza@laptop:~/Documents/SO/HW-CPU-Intro$ ./process-run.py -s 1 -l 3:50,3:50 -c -S SWITCH_ON_END
Time
   PID: 0
   PID: 1
       CPU
       IOs

  1 
   RUN:cpu
     READY
         1
          

  2 
    RUN:io
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

  6 
   WAITING
     READY
          
         1

  7*
    RUN:io
     READY
         1
          

  8 
   WAITING
     READY
          
         1

  9 
   WAITING
     READY
          
         1

 10 
   WAITING
     READY
          
         1

 11 
   WAITING
     READY
          
         1

 12*
      DONE
   RUN:cpu
         1
          

 13 
      DONE
   RUN:cpu
         1
          

 14 
      DONE
   RUN:cpu
         1


*-s 2 -l 3:50,3:50*
maxsouza@laptop:~/Documents/SO/HW-CPU-Intro$ ./process-run.py -s 2 -l 3:50,3:50 -c -S SWITCH_ON_END
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
    RUN:io
     READY
         1
          

  7 
   WAITING
     READY
          
         1

  8 
   WAITING
     READY
          
         1

  9 
   WAITING
     READY
          
         1

 10 
   WAITING
     READY
          
         1

 11*
   RUN:cpu
     READY
         1
          

 12 
      DONE
   RUN:cpu
         1
          

 13 
      DONE
    RUN:io
         1
          

 14 
      DONE
   WAITING
          
         1

 15 
      DONE
   WAITING
          
         1

 16 
      DONE
   WAITING
          
         1

 17 
      DONE
   WAITING
          
         1

 18*
      DONE
    RUN:io
         1
          

 19 
      DONE
   WAITING
          
         1

 20 
      DONE
   WAITING
          
         1

 21 
      DONE
   WAITING
          
         1

 22 
      DONE
   WAITING
          
         1

 23*
      DONE
      DONE


*-s 3 -l 3:50,3:50*
maxsouza@laptop:~/Documents/SO/HW-CPU-Intro$ ./process-run.py -s 3 -l 3:50,3:50 -c -S SWITCH_ON_END
Time
   PID: 0
   PID: 1
       CPU
       IOs

  1 
   RUN:cpu
     READY
         1
          

  2 
    RUN:io
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

  6 
   WAITING
     READY
          
         1

  7*
   RUN:cpu
     READY
         1
          

  8 
      DONE
    RUN:io
         1
          

  9 
      DONE
   WAITING
          
         1

 10 
      DONE
   WAITING
          
         1

 11 
      DONE
   WAITING
          
         1

 12 
      DONE
   WAITING
          
         1

 13*
      DONE
    RUN:io
         1
          

 14 
      DONE
   WAITING
          
         1

 15 
      DONE
   WAITING
          
         1

 16 
      DONE
   WAITING
          
         1

 17 
      DONE
   WAITING
          
         1

 18*
      DONE
   RUN:cpu
         1