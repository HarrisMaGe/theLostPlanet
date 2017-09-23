#include"cocos2d.h"
#define Map_3_1 1
#define Map_3_2 2
#define Map_3_3 3
#define Map_3_4 4
USING_NS_CC;

class BackGround_3 :public Layer
{
public:
	CREATE_FUNC(BackGround_3);
	virtual bool init();

public:
	void update(float time);
	virtual void menuPauseCallBack(Ref * pSender);
	virtual void onExit();

};