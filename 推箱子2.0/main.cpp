//==========================
//程序名称：推箱子
//版本号：2.1
//制作人：杨新瑞
//创建时间：2017.1.30 9:52
//完工时间：2017.2.11 20:59
//总制作天数：3
//
//更新日志：
//	2.0：
//	2017.5.20
//	更改图片音乐素材位置
//	优化音频函数
//	优化图片加载函数
//	更改退出动画
//	调整游戏构架
//
//==========================
#include"founction.h"

//窗口尺寸
#define Win_L 1000
#define Win_H 600

int main(void)
{
	ege::setinitmode(ege::INIT_ANIMATION);
	// 图形初始化
	ege::initgraph(Win_L, Win_H);
	setcaption("推箱子2.1"); //修改窗口名称
	// 随机数初始化，如果需要使用随机数的话
	ege::randomize();
	// 程序主循环
	mainloop();
	// 关闭绘图设备
	ege::closegraph();
	return 0;
}

