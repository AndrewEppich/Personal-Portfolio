Andrew Eppich
eppich@chapman.edu
2417630
Compile: gcc sshell.c -o sshell
Run: ./sshell

Sample Input

osh> ps (or ps -ael on non mac)
  PID TTY           TIME CMD
88081 ttys001    0:00.07 /bin/zsh -il
92058 ttys004    0:00.03 /bin/zsh -il
94131 ttys020    0:00.02 /bin/zsh -il
94147 ttys020    0:00.00 ./sshell
osh> ls
README.txt      sshell          sshell.c
osh> du
8       ./.vscode
96      .
osh> vm_stat (or free on other systems)
Mach Virtual Memory Statistics: (page size of 16384 bytes)
Pages free:                                8971.
Pages active:                            382383.
Pages inactive:                          370208.
Pages speculative:                         7655.
Pages throttled:                              0.
Pages wired down:                        104982.
Pages purgeable:                           4093.
"Translation faults":                 583999941.
Pages copy-on-write:                   18145444.
Pages zero filled:                    275227750.
Pages reactivated:                      9937917.
Pages purged:                           3867088.
File-backed pages:                       235052.
Anonymous pages:                         525194.
Pages stored in compressor:              298507.
Pages occupied by compressor:            125555.
Decompressions:                         3405159.
Compressions:                           5119861.
Pageins:                               11151719.
Pageouts:                                111600.
Swapins:                                      0.
Swapouts:                                     0.
osh> sleep 60 &
Background process ID 95164
osh> ps (or ps -ael)
  PID TTY           TIME CMD
88081 ttys001    0:00.07 /bin/zsh -il
92058 ttys004    0:00.03 /bin/zsh -il
95134 ttys033    0:00.02 /bin/zsh -il
95157 ttys033    0:00.01 ./sshell
95164 ttys033    0:00.00 sleep 60
