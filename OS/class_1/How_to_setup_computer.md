参考：

> 1. https://www.ruanyifeng.com/blog/2013/02/booting.html
>
> 2. [为什么要把主引导记录载入到0x7c00处](http://www.ruanyifeng.com/blog/2015/09/0x7c00.html)


# 计算机是如何启动的？


1. 先将BIOS写入ROM
2. 开机后，运行BIOS，进行硬件自检（power-on self-check）
3. BIOS将CPU的控制权交给启动顺序第一位的存储设备，这时，计算机读取该设备的第一个扇区，也就是读取最前面的512个字节（将主引导记录boot载入内存0x07c00处）。如果这512个字节的最后两个字节是0x55和0xAA，表明这个设备可以用于启动；如果不是，表明设备不能用于启动，控制权于是被转交给"启动顺序"中的下一个设备。这最前面的512个字节，就叫做"主引导记录"（Master boot record，缩写为MBR）。这512Byte告诉CPU去哪找OS（第1-446字节：调用操作系统的机器码）。主引导记录由三个部分组成：
    1. 第1-446字节：调用操作系统的机器码。
    2. 第447-510字节：分区表（Partition table）。
    3. 第511-512字节：主引导记录签名（0x55和0xAA）。
4. 从分区找OS 或者 在计算机读取主引导记录前446个字节后，运行“启动管理器（例如：grub”），让用户选择操作系统
5. CPU的控制权被交给OS，OS_kernel被载入内核。

> 
> ```shell
> 以Linux系统为例，先载入/boot目录下面的kernel。
> 
> 内核加载成功后，第一个运行的程序是/sbin/init。它根据配置文件（Debian系统是/etc/initab）产生init进程。这是Linux启动后的第一个进程，pid进程编号为1，其他进程都是它的后代。
> 
> 然后，init线程加载系统的各个模块，比如窗口程序和网络程序，直至执行/bin/login程序，跳出登录界面，等待用户输入用户名和密码。
> 
> 至此，全部启动过程完成。
> ```

```shell
+-------------------------------------------------------------------------------------
|
+-------------------------------------------------------------------------------------
|
+-------------------------------------------------------------------------------------
|
+-------------------------------------------------------------------------------------
```



简单说，计算机启动是这样一个过程：

- 通电
- 读取ROM里面的BIOS，用来检查硬件
- 硬件检查通过
- BIOS根据指定的顺序，检查引导设备的第一个扇区（即主引导记录），加载在内存地址 0x7C00
- 主引导记录把操作权交给操作系统