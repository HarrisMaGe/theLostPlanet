#include"cocos2d.h"
#define Map_2_1 1
#define Map_2_2 2
#define Map_2_3 3
#define Map_2_4 4
USING_NS_CC;

class BackGround_2 :public Layer
{
public:
	CREATE_FUNC(BackGround_2);
	virtual bool init();

public:
	void update(float time);
	virtual void menuPauseCallBack(Ref * pSender);
	virtual void onExit();
	
};