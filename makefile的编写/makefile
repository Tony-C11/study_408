# 类似于写了函数，可以在makefile文件中重复使用 -> $(XX)
OBJS = main.o tool1.o tool2.o
CC = gcc
CFLAG += -c -Wall -g
RMRF = rm -rf

# mytool 的实现依赖于main.o, tool1.o, tool2.o
mytool: $(OBJS)
	# $^ ：上一行中出现的依赖文件，$@ ：上一行中需要的目标文件
	$(CC) $^ -o $@

# .o 的实现依赖于与他同名的 .c 文件
%.o: %.c
	$(CC) $^ $(CFLAG) -o $@

clean: 
	$(RMRF) *.o mytool

