[![CI](https://github.com/QQxiaoming/rg35xx-app-template/actions/workflows/ci.yml/badge.svg?branch=main)](https://github.com/QQxiaoming/rg35xx-app-template/actions/workflows/ci.yml)
[![License](https://img.shields.io/github/license/qqxiaoming/rg35xx-app-template.svg?colorB=f48041&style=flat-square)](https://github.com/QQxiaoming/rg35xx-app-template)

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

3. 输出目录

编译输出位于./out目录下*.elf文件

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
| SDLK_p     | POWER    |

## 在pc上调试模拟运行

在ubuntu上安装libsdl

```shell
sudo apt install libsdl1.2-dev libsdl-image1.2-dev libsdl-mixer1.2-dev libvorbisidec-dev  libsdl-sound1.2-dev libsdl-ttf2.0-dev
```

编译

```shell
./make_native.sh
```

输出目录

编译输出位于./out_native目录下*.elf文件，可以直接在pc上运行，并通过键盘模拟运行，方便将程序调试到可运行状态，再上板子测试和发布。

