# 自己开发rg35xx应用程序模版工程 （用于GarlicOS）

本项目为rg35xx应用程序模版工程，用于开发rg35xx简单的应用程序。

![img](./doc/img.png)

## 如何编译

1. 使用docker获取编译环境

```shell
docker pull miyoocfw/toolchain-shared-uclibc:latest
```

2. 编译

```shell
./make.sh
```

## 如何添加自己的源文件

1. 在src目录下添加自己的源文件，例如test.c

2. 修改src/Makefile，添加自己的源文件，主要修改以下三个变量

```makefile
TARGET = main
C_SOURCES =  \
	${wildcard $(SRCS_DIR)/*.c}
CPP_SOURCES =  \
	${wildcard $(SRCS_DIR)/*.cpp}
```

## keymap

通过LD_PRELOAD加载j2k.so，源码位于utils/j2k.c, 可以将键盘映射为rg35XX的按键。

```shell
LD_PRELOAD=./j2k.so ./main
```

按键映射如下：

| key        | function |
| ---------- | -------- |
| SDLK_w     | Up       |
| SDLK_d     | Right    |
| SDLK_s     | Down     |
| SDLK_q     | Left     |
| SDLK_x     | X        |
| SDLK_y     | Y        |
| SDLK_a     | A        |
| SDLK_b     | B        |
| SDLK_h     | L1       |
| SDLK_l     | R1       |
| SDLK_j     | L2       |
| SDLK_k     | R2	    |
| SDLK_n     | SELECT   |
| SDLK_m     | START    |
| SDLK_u     | MENU     |
| SDLK_r     | VOL+     |
| SDLK_t     | VOL-     |
| SDLK_POWER | POWER    |
