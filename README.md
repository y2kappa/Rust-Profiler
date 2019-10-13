# Rust Profiler

!Work in progress!

## Description

Attempting a util that gives you the information of the current process. That means current amount of memory used, cpu usage, etc. So far, toy example: reads a file of 30 MB and keeps it in memory. When it comes to comparing to it's C++ counterpart, the memory profile of RUST and of C++ are completely different.



## Build

```sh
g++ -o usage.tsk usage.cpp --std=c++14
cargo build
```

Optimized build (Set Cargo.toml to opt-level=3)
```
g++ -o usage.tsk usage.cpp --std=c++14 -O3
cargo build
```

## TODO:
    - add a recurring profiling log appear eveyr 5 minutes ot help with logging and make it configurable
    - make sure the numbers are right


## Outputs

### Memory

Take a look at the C++ logs usage vs Rust. Seems like rust is a lot more efficient
with memory usage, nicer to the kernel. However it seems like C++ asks for more memory upfront and holds on to the memory for longer, meaning in the long run, fewer system calls.

- C++:
    ```sh
    : ./usage.tsk
    [Sun Oct 13 12:05:19 2019] 1 pid=87186 rss=0.875MB
    [Sun Oct 13 12:05:24 2019] 2 pid=87186 rss=0.875MB
    [Sun Oct 13 12:05:29 2019] 3 pid=87186 rss=0.886719MB
    [Sun Oct 13 12:05:34 2019] 4 pid=87186 rss=0.886719MB
    [Sun Oct 13 12:05:42 2019] 5 pid=87186 rss=263.387MB     // << read 30 mb
    [Sun Oct 13 12:05:47 2019] 6 pid=87186 rss=263.387MB
    [Sun Oct 13 12:05:52 2019] 7 pid=87186 rss=263.387MB
    [Sun Oct 13 12:05:57 2019] 8 pid=87186 rss=263.402MB
    [Sun Oct 13 12:06:02 2019] 9 pid=87186 rss=263.402MB
    [Sun Oct 13 12:06:09 2019] 10 pid=87186 rss=541.809MB    // << read 30 mb
    [Sun Oct 13 12:06:14 2019] 11 pid=87186 rss=541.809MB
    [Sun Oct 13 12:06:19 2019] 12 pid=87186 rss=541.809MB
    [Sun Oct 13 12:06:24 2019] 13 pid=87186 rss=541.809MB
    [Sun Oct 13 12:06:29 2019] 14 pid=87186 rss=541.809MB
    [Sun Oct 13 12:06:37 2019] 15 pid=87186 rss=607.496MB    // << read 30 mb
    [Sun Oct 13 12:06:42 2019] 16 pid=87186 rss=607.496MB
    [Sun Oct 13 12:06:47 2019] 17 pid=87186 rss=607.496MB
    [Sun Oct 13 12:06:52 2019] 18 pid=87186 rss=607.504MB
    [Sun Oct 13 12:06:57 2019] 19 pid=87186 rss=607.504MB
    [Sun Oct 13 12:07:04 2019] 20 pid=87186 rss=791.164MB    // << read 30 mb
    [Sun Oct 13 12:07:09 2019] 21 pid=87186 rss=791.164MB
    [Sun Oct 13 12:07:14 2019] 22 pid=87186 rss=791.164MB
    [Sun Oct 13 12:07:19 2019] 23 pid=87186 rss=791.164MB
    [Sun Oct 13 12:07:24 2019] 24 pid=87186 rss=791.164MB
    [Sun Oct 13 12:07:33 2019] 25 pid=87186 rss=857.473MB    // << read 30 mb
    [Sun Oct 13 12:07:38 2019] 26 pid=87186 rss=857.473MB
    [Sun Oct 13 12:07:43 2019] 27 pid=87186 rss=857.473MB
    [Sun Oct 13 12:07:48 2019] 28 pid=87186 rss=857.473MB
    [Sun Oct 13 12:07:53 2019] 29 pid=87186 rss=857.473MB
    [Sun Oct 13 12:08:00 2019] 30 pid=87186 rss=988.609MB    // << read 30 mb
    [Sun Oct 13 12:08:05 2019] 31 pid=87186 rss=988.609MB

    ```

Take a look at Rust:

```sh
    Finished dev [unoptimized + debuginfo] target(s) in 0.79s
     Running `target/debug/profiler`
[11:13:03 AM] 1 pid=92015 | Name=profiler | CpuUsage=0.00001% | MemUsage=3MB
[11:13:08 AM] 2 pid=92015 | Name=profiler | CpuUsage=0.00002% | MemUsage=3MB
[11:13:13 AM] 3 pid=92015 | Name=profiler | CpuUsage=0.00002% | MemUsage=4MB
[11:13:18 AM] 4 pid=92015 | Name=profiler | CpuUsage=0.00003% | MemUsage=4MB
[11:13:23 AM] 5 pid=92015 | Name=profiler | CpuUsage=0.00004% | MemUsage=64MB  // << read 30 mb
[11:13:28 AM] 6 pid=92015 | Name=profiler | CpuUsage=0.00005% | MemUsage=64MB
[11:13:33 AM] 7 pid=92015 | Name=profiler | CpuUsage=0.00005% | MemUsage=64MB
[11:13:39 AM] 8 pid=92015 | Name=profiler | CpuUsage=0.00006% | MemUsage=64MB
[11:13:44 AM] 9 pid=92015 | Name=profiler | CpuUsage=0.00006% | MemUsage=65MB
[11:13:49 AM] 10 pid=92015 | Name=profiler | CpuUsage=0.00007% | MemUsage=125MB  // << read 30 mb
[11:13:54 AM] 11 pid=92015 | Name=profiler | CpuUsage=0.00008% | MemUsage=125MB
[11:13:59 AM] 12 pid=92015 | Name=profiler | CpuUsage=0.00009% | MemUsage=125MB
[11:14:04 AM] 13 pid=92015 | Name=profiler | CpuUsage=0.00009% | MemUsage=125MB
[11:14:09 AM] 14 pid=92015 | Name=profiler | CpuUsage=0.00010% | MemUsage=125MB
[11:14:15 AM] 15 pid=92015 | Name=profiler | CpuUsage=0.00011% | MemUsage=155MB  // << read 30 mb
[11:14:20 AM] 16 pid=92015 | Name=profiler | CpuUsage=0.00012% | MemUsage=155MB
[11:14:25 AM] 17 pid=92015 | Name=profiler | CpuUsage=0.00012% | MemUsage=155MB
[11:14:30 AM] 18 pid=92015 | Name=profiler | CpuUsage=0.00013% | MemUsage=155MB
[11:14:35 AM] 19 pid=92015 | Name=profiler | CpuUsage=0.00014% | MemUsage=155MB
[11:14:40 AM] 20 pid=92015 | Name=profiler | CpuUsage=0.00014% | MemUsage=215MB  // << read 30 mb
[11:14:45 AM] 21 pid=92015 | Name=profiler | CpuUsage=0.00015% | MemUsage=215MB
[11:14:51 AM] 22 pid=92015 | Name=profiler | CpuUsage=0.00016% | MemUsage=215MB
[11:14:56 AM] 23 pid=92015 | Name=profiler | CpuUsage=0.00016% | MemUsage=215MB
[11:15:01 AM] 24 pid=92015 | Name=profiler | CpuUsage=0.00017% | MemUsage=215MB
[11:15:06 AM] 25 pid=92015 | Name=profiler | CpuUsage=0.00018% | MemUsage=261MB  // << read 30 mb
[11:15:11 AM] 26 pid=92015 | Name=profiler | CpuUsage=0.00019% | MemUsage=261MB
[11:15:16 AM] 27 pid=92015 | Name=profiler | CpuUsage=0.00019% | MemUsage=262MB
[11:15:21 AM] 28 pid=92015 | Name=profiler | CpuUsage=0.00020% | MemUsage=262MB
[11:15:27 AM] 29 pid=92015 | Name=profiler | CpuUsage=0.00021% | MemUsage=262MB
[11:15:32 AM] 30 pid=92015 | Name=profiler | CpuUsage=0.00021% | MemUsage=292MB  // << read 30 mb
[11:15:37 AM] 31 pid=92015 | Name=profiler | CpuUsage=0.00022% | MemUsage=292MB

```


### Speed

Looks like Rust is much faster:
- C++ real	0m14.094s
- Rust real	0m0.603s

With optimization, C++ is faster:
- C++ with O3 level real	0m5.412s
- Rust with optimization 3 real	0m0.626s

Examples of outputs:

- C++:
```sh
: time ./usage.tsk
[Sun Oct 13 12:21:54 2019] 1 pid=4381 rss=0.882812MB
[Sun Oct 13 12:21:54 2019] 2 pid=4381 rss=0.882812MB
[Sun Oct 13 12:21:54 2019] 3 pid=4381 rss=0.882812MB
[Sun Oct 13 12:21:54 2019] 4 pid=4381 rss=0.882812MB
[Sun Oct 13 12:21:56 2019] 5 pid=4381 rss=312.93MB
[Sun Oct 13 12:21:56 2019] 6 pid=4381 rss=312.93MB
[Sun Oct 13 12:21:56 2019] 7 pid=4381 rss=312.93MB
[Sun Oct 13 12:21:56 2019] 8 pid=4381 rss=312.93MB
[Sun Oct 13 12:21:56 2019] 9 pid=4381 rss=312.93MB
[Sun Oct 13 12:21:58 2019] 10 pid=4381 rss=553.113MB
[Sun Oct 13 12:21:58 2019] 11 pid=4381 rss=553.113MB
[Sun Oct 13 12:21:58 2019] 12 pid=4381 rss=553.113MB
[Sun Oct 13 12:21:58 2019] 13 pid=4381 rss=553.113MB
[Sun Oct 13 12:21:58 2019] 14 pid=4381 rss=553.113MB
[Sun Oct 13 12:22:00 2019] 15 pid=4381 rss=673.117MB
[Sun Oct 13 12:22:00 2019] 16 pid=4381 rss=673.117MB
[Sun Oct 13 12:22:00 2019] 17 pid=4381 rss=673.117MB
[Sun Oct 13 12:22:00 2019] 18 pid=4381 rss=673.117MB
[Sun Oct 13 12:22:00 2019] 19 pid=4381 rss=673.117MB
[Sun Oct 13 12:22:02 2019] 20 pid=4381 rss=793.305MB
[Sun Oct 13 12:22:02 2019] 21 pid=4381 rss=793.305MB
[Sun Oct 13 12:22:02 2019] 22 pid=4381 rss=793.305MB
[Sun Oct 13 12:22:02 2019] 23 pid=4381 rss=793.305MB
[Sun Oct 13 12:22:02 2019] 24 pid=4381 rss=793.305MB
[Sun Oct 13 12:22:05 2019] 25 pid=4381 rss=889.641MB
[Sun Oct 13 12:22:05 2019] 26 pid=4381 rss=889.641MB
[Sun Oct 13 12:22:05 2019] 27 pid=4381 rss=889.641MB
[Sun Oct 13 12:22:05 2019] 28 pid=4381 rss=889.641MB
[Sun Oct 13 12:22:05 2019] 29 pid=4381 rss=889.641MB
[Sun Oct 13 12:22:07 2019] 30 pid=4381 rss=1033.44MB
[Sun Oct 13 12:22:07 2019] 31 pid=4381 rss=1033.44MB
[Sun Oct 13 12:22:07 2019] 32 pid=4381 rss=1033.44MB

real	0m14.094s
user	0m12.603s
sys	0m1.257s

```

- Rust:
```sh
: time ./target/debug/profiler
[11:21:45 AM] 1 pid=4215 | Name=profiler | CpuUsage=0.00001% | MemUsage=3MB
[11:21:45 AM] 2 pid=4215 | Name=profiler | CpuUsage=224.98647% | MemUsage=3MB
[11:21:45 AM] 3 pid=4215 | Name=profiler | CpuUsage=209.61998% | MemUsage=3MB
[11:21:45 AM] 4 pid=4215 | Name=profiler | CpuUsage=212.35553% | MemUsage=3MB
[11:21:45 AM] 5 pid=4215 | Name=profiler | CpuUsage=110.71659% | MemUsage=67MB
[11:21:45 AM] 6 pid=4215 | Name=profiler | CpuUsage=222.29643% | MemUsage=67MB
[11:21:45 AM] 7 pid=4215 | Name=profiler | CpuUsage=228.84810% | MemUsage=67MB
[11:21:45 AM] 8 pid=4215 | Name=profiler | CpuUsage=214.70100% | MemUsage=67MB
[11:21:45 AM] 9 pid=4215 | Name=profiler | CpuUsage=216.25291% | MemUsage=67MB
[11:21:45 AM] 10 pid=4215 | Name=profiler | CpuUsage=111.24561% | MemUsage=127MB
[11:21:45 AM] 11 pid=4215 | Name=profiler | CpuUsage=228.62427% | MemUsage=127MB
[11:21:45 AM] 12 pid=4215 | Name=profiler | CpuUsage=233.02287% | MemUsage=127MB
[11:21:45 AM] 13 pid=4215 | Name=profiler | CpuUsage=229.31335% | MemUsage=127MB
[11:21:45 AM] 14 pid=4215 | Name=profiler | CpuUsage=234.09641% | MemUsage=127MB
[11:21:45 AM] 15 pid=4215 | Name=profiler | CpuUsage=109.77831% | MemUsage=158MB
[11:21:45 AM] 16 pid=4215 | Name=profiler | CpuUsage=213.49052% | MemUsage=158MB
[11:21:45 AM] 17 pid=4215 | Name=profiler | CpuUsage=219.45084% | MemUsage=158MB
[11:21:45 AM] 18 pid=4215 | Name=profiler | CpuUsage=190.91754% | MemUsage=158MB
[11:21:45 AM] 19 pid=4215 | Name=profiler | CpuUsage=219.18817% | MemUsage=158MB
[11:21:46 AM] 20 pid=4215 | Name=profiler | CpuUsage=110.66813% | MemUsage=218MB
[11:21:46 AM] 21 pid=4215 | Name=profiler | CpuUsage=219.79631% | MemUsage=218MB
[11:21:46 AM] 22 pid=4215 | Name=profiler | CpuUsage=210.63423% | MemUsage=218MB
[11:21:46 AM] 23 pid=4215 | Name=profiler | CpuUsage=211.39572% | MemUsage=218MB
[11:21:46 AM] 24 pid=4215 | Name=profiler | CpuUsage=215.08838% | MemUsage=218MB
[11:21:46 AM] 25 pid=4215 | Name=profiler | CpuUsage=111.67028% | MemUsage=263MB
[11:21:46 AM] 26 pid=4215 | Name=profiler | CpuUsage=231.12474% | MemUsage=263MB
[11:21:46 AM] 27 pid=4215 | Name=profiler | CpuUsage=230.24364% | MemUsage=263MB
[11:21:46 AM] 28 pid=4215 | Name=profiler | CpuUsage=213.84993% | MemUsage=263MB
[11:21:46 AM] 29 pid=4215 | Name=profiler | CpuUsage=210.17484% | MemUsage=263MB
[11:21:46 AM] 30 pid=4215 | Name=profiler | CpuUsage=109.56078% | MemUsage=294MB
[11:21:46 AM] 31 pid=4215 | Name=profiler | CpuUsage=224.34790% | MemUsage=294MB
[11:21:46 AM] 32 pid=4215 | Name=profiler | CpuUsage=220.98370% | MemUsage=294MB

real	0m0.603s
user	0m0.487s
sys	0m0.622s
```