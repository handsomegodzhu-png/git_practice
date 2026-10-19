# 学生成绩管理系统

## 项目简介

这是一个使用 C++ 编写的学生成绩管理系统，用于练习 C++ 基础语法、面向对象编程、STL 容器以及文件读写操作。

## 已实现功能

- 学生信息录入
- 查询学生信息
- 修改学生成绩
- 按总成绩排序
- 学生数据文件读写
- 菜单循环操作

## 使用技术

- C++
- STL 容器与算法
- 文件输入输出
- Git 与 GitHub 版本管理

## 项目结构

```text
StudentManagementSystem/
├── StudentManagement.cpp
└── README.md
```

## 后续计划

- 完善输入校验与异常处理
- 优化代码结构
- 持续练习 Git 分支与版本管理
## 编译与运行

### 方法一：使用 g++ 编译

确保已经安装 MinGW-w64，并且 `g++` 已加入系统 PATH。

在 VS Code 终端中进入项目目录，执行：

```bash
g++ StudentManagement.cpp -o StudentManagement.exe
```

编译成功后运行：

```powershell
.\StudentManagement.exe
```

如果编译器不在 PATH 中，请先配置好 MinGW 的环境变量。

### 方法二：使用 VS Code 运行

1. 使用 VS Code 打开本项目所在文件夹。
2. 确保已安装并配置 C/C++ 扩展和编译器。
3. 打开 `StudentManagement.cpp`。
4. 使用自己配置好的构建或运行按钮进行编译和运行。

具体按钮和快捷键可能因 VS Code 配置而异。
---

本项目用于个人学习与实践。