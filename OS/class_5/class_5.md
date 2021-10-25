# 内核级线程

```C
user-level_thread_1    - user_stack_1
kernel-level_thread_1   - kernel_stack_1
user-level_thread_2    - user_stack_2
kernel-level_thread_2   - kernel_stack_2

kernel-level_thread_1的内核栈关联user-level_thread_1

kernel-level_thread_2的内核栈关联user-level_thread_2


```

五段论：

1. user-level_thread_1进行系统调用，进入kernel-level_thread_1，kernel-level_thread_1的内核栈保存user-level_thread_1的返回地址。接下来，如果发生磁盘读写等情况，kernel-level_thread_1阻塞，通过TCB表来进行寄存器等的设置，切换到kernel-level_thread_2，kernel-level_thread_2执行完毕后，借助kernel_stack_2来跳转到user-level_thread_2

> 在用户的角度上，只是进行了用户级线程间的跳转。

