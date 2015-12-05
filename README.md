# LeapMotion_Slicer
将从LeapMotion采集到的方位信息通过openIGTLink协议与3D Slicer中的三维对象进行交互。


## Qt LeapMotion
将作为与Slicer进行数据交互但一个Daemon，遵循OpenIGTLink协议。依赖OpenIGTLink: www.openigtlink.org.LeapMotion: www.leapmotion.org.
由于LeapMotion运行时依赖多个第三方库，直接在Slicer环境下启动LM存在不小困难，可通过如下方法暂时解决：
1. 利用Slicer中的OpenIGTLink IF模块，进入该模块，新建一个节点，将其设为Server。
2. 独立地打开LeapMotion，它将LM采集到的数据传送给Slicer。

## other
最终将用cmake来管理整个项目。
目前还存在bug。
待有时间时，再解决上述bug。


