#ifndef _Help_Layer_H__
#define _Help_Layer_H__

#include "cocos2d.h"


using namespace cocos2d;

class HelpLayer : public Layer
{
public:
	static Scene* createScene();
	CREATE_FUNC(HelpLayer);
	virtual bool init();
	void menuCallBack(Ref* pSender);




};

#endif // __About_Layer_H__


