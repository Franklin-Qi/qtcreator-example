# 利用绘图和定时器实现简单小动画
> 人类具有“视觉暂留”的特性，人的眼睛看到一幅画或者一个物体后，
> 在0.34秒以内不会消失。利用这一特性，我们可以将定时器调到恰当的时间，
> 再结合QPixmap类就可以使一组图流畅地展示在人们面前，形成一个小动画。

## arg() 用法
```
arg()函数的用法：用%1—%99来填充字符串中的给定的参数
(填充式应按1—99从小到大的顺序来填充，且变量应为int型)；

参数：arg(int a,int fieldwidth,base，QLatin1Char(char c))
对应变量的具体意思：
int a：指定的变量
int fieldwidth：变量最小宽度
base：变量的进制
QLatin1Char(char c)：当原始数字长度不足最小宽度时用于填充的字符

注, 1-9则 filedwidth=1 base=10
```

## 参考
[绘图和定时器][1] [Qt 绘图和定时器][2] [Qt 制作动图][3]

[1](https://blog.csdn.net/weixin_46176782/article/details/106382699)
[2](https://blog.csdn.net/xcccc233/article/details/106435362)
[3](https://www.mscto.com/c/640737.html)
