#源程序与编译
permutation.cpp:递归
g++ permutation.cpp -o permutation
permutation2.cpp:进制递增
g++ permutation2.cpp -o p2
permutation3.cpp:多线程进制递增
g++ permutation3.cpp -o p3 -lpthread
permutation4.cpp:字典序法
g++ permutation4.cpp -o p4
permutation5.cpp:邻位对换
g++ permutation5.cpp -o p5

#运行方式
运行后，输入数n，输出n的全排列，如

$./p2
3
0 1 2
0 2 1
1 0 2
1 2 0
2 0 1
2 1 0
