# shell脚本

# 概念

## shell脚本

一种为shell编写的脚本程序

### shell环境

shell编程只要，一个能编写代码的文本编辑器核一个能解释脚本的解释器就可以

Linux下的shell环境

- Bourne Shell(/user/bin/sh或/bin/sh)

- Bourne  Again Shell(/bin/bash)

- C shell (/user/bin/csh)

- k shell(/user/bin/ksh)

- shell for Root(/sbin/sh)

  

本次使用的Bourne  Again shell 

**#!**告诉系统其后路径所制定的程序j即是解释此脚本文件的shell程序

## windows下运行Bourne  Again Shell

git 的windows客户端自带MINGW的linux的命令行，可以执行简单shell命令，与cygwin功能类似。

运行git bash 输入命令：

```shell
mintty
```

## 例程

```shell
#!/bin/bash
echo "Hello World !" 
```

# 自动发布工程-使用shell

