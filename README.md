pyConvert
=========

pyConvert writed by convert command lib(use boost-python,imagemagick-devel)

功能：
把convert的源码直接编译为python的扩展
说明:
ImageMagick-devel>6.5.4.7-6新版本的对指令的解析进行了重写，会不兼容
编译前依赖
yum install boost.python ImageMagick-devel-6.5.4.7-6

编译:
python setup.py build

安装:
python setup.py install

测试:
python ./test.py

问题：
1.convert毕竟是console指令对于内存的使用与释放有些浪费
2.应用使用的是固定的几种方法，可以直接封装使用，没必要让console递归去解析参数