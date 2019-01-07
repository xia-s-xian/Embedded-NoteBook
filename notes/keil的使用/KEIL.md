# KEIL

## 对输出目标文件处理

### keil编译输出文件

(%L) 工程名.axf文件

### hex，bin，axf，elf格式文件小节

参考连接：https://blog.csdn.net/grow_mature/article/details/8553542



### MDK工具参数

va9635.bat $K\ARM\ARMCC\bin @L .\output\release %L

这个命令包含5个参数:

参数1：va9635.bat 

参数2：C:\Keil_v5\\ARM\ARMCC\bin 

参数3： va9635_release

参数4： .\output\release 

参数5： va9635_release.axf

### 批处理文件如何对输出文件处理