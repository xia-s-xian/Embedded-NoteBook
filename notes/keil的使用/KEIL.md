# KEIL

## 对输出目标文件处理

### keil编译输出文件

(%L) 工程名.axf文件

### hex，bin，axf，elf格式文件小节

参考连接：https://blog.csdn.net/grow_mature/article/details/8553542



### MDK工具参数

va9635.bat $K\ARM\ARMCC\bin @L .\output\release %L

这个命令包含5个参数:

参数0：va9635.bat 

参数1：C:\Keil_v5\\ARM\ARMCC\bin 

参数2： va9635_release

参数3： .\output\release 

参数4： va9635_release.axf

## 批处理文件如何对输出文件处理

### 举例1：cmd对时间的处理

例如：set CurDate=%date:~0,4%%date:~5,2%%date:~8,2%

%date:~0,4%  表示从左向右指针向右偏0位，然后从指针偏移到的位置开始提取4位字符，结果是2014（年的值）  %date:~5,2%  表示指针从左向右偏移5位，然后从偏移处开始提取2位字符，结果是03（月的值）
%date:~8,2%  表示指针从左向右偏移8位，然后从偏移处开始提取2位字符，结果是01（日的值)
%date:~5%    表示指针从左向右偏移5位，然后提取所有的值 
%date:~-5%   表示指针反方向偏移，从最右端开始，偏移5位，然后从指针处提取左边的所有数值

[参考地址](https://blog.csdn.net/jinhoward/article/details/20213213)

### cmd查看变量

```cmd
echo %变量%
```





### va9635.bat原文件

```cmd
::@echo off
set exepath=%3
set rppath=.\output\%2
set CurDate=%date:~0,4%%date:~5,2%%date:~8,2%
set CurTime=%time:~0,2%%time:~3,2%%time:~6,2%
set CurTime=%CurTime: =0%
set rpath=%rppath%\%2%CurDate%%CurTime%
set binpath=%rpath%\binary
set debugpath=%rpath%\debuginfo
set splitpath=%rpath%\split
if exist %rppath% del /F /S /Q %rppath%
if exist %rppath% rd     /S /Q %rppath%
if not exist %rppath% mkdir %rppath%
if not exist %rpath% mkdir %rpath%   
if not exist %binpath% mkdir %binpath%
if not exist %debugpath% mkdir %debugpath%
if not exist %splitpath% mkdir %splitpath%
if exist %exepath%\%4 xcopy  %exepath%\%4 %debugpath%\
if exist %exepath%\%2.map xcopy  %exepath%\%2.map %debugpath%\
if exist %exepath%\%4 %1\fromelf --bin --output %binpath%\%2.bin %exepath%\%4
if exist %exepath%\%4 %1\fromelf --text -c -s --output %debugpath%\%2.txt %exepath%\%4
if exist %binpath%\%2.bin binsplit %binpath%\%2.bin %splitpath%\ 0x00 512k 256k
.\BootEncode.exe e 0 %binpath%\%2.bin %binpath%\%2_mp_tool.bin 0x00400000

```

