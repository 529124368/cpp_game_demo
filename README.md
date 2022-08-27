# cpp_game_demo
use raylib make game demo

编译成功后将exe放到asset文件同级目录运行游戏。

# How to build
>- 安装 vscode
>- 安装 cmake 
>- 安装 vcpkg 


cmakeList.txt目录执行下面的两条编译命令

1. 
```cmake
cmake --no-warn-unused-cli -DCMAKE_TOOLCHAIN_FILE:STRING=E:/vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET:STRING=x86-windows-static -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -S . -B build -G "Visual Studio 17 2022" -T host=x86 -A win32
```

2.
```cmake
cmake --build build --config Release --target ALL_BUILD -j 10 --
```
