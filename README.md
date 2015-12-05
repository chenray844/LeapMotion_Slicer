# LeapMotion_Slicer
将从LeapMotion采集到的方位信息通过openIGTLink协议与3D Slicer中的三维对象进行交互。

## StartMotion.py
将作为服务进程，先于Slicer启动。

## Qt LeapMotion
将作为与Slicer进行数据交互但一个Daemon，遵循OpenIGTLink协议。依赖OpenIGTLink: www.openigtlink.org.

## other
最终将用cmake来管理整个项目。
目前还存在bug。


