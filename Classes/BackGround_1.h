#ifndef _BACKGROUND1_H_
#define _BACKGROUND1_H_

#include"cocos2d.h"
#define Map_1_1 1
#define Map_1_2 2
#define Map_1_3 3
#define Map_1_4 4
USING_NS_CC;

class BackGround_1 :public Layer
{
public:
	CREATE_FUNC(BackGround_1);
	virtual bool init();

public:
	void update(float time);
	virtual void onExit();
	virtual void menuPauseCallBack(Ref * pSender);

};

#endif 
