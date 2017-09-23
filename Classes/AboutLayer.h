#ifndef __About_Layer_H__
#define _About_Layer_H__

#include "cocos2d.h"
#include "StartLayer.h"

using namespace cocos2d;

class AboutLayer : public Layer
{
public:
	static Scene* createScene();
	CREATE_FUNC(AboutLayer);
	virtual bool init();
	void menuCallBack(Ref* pSender);
};

#endif // __About_Layer_H__
