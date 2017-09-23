#ifndef _Start_Layer_H__
#define _Start_Layer_H__

#include "GameLayer.h"

#include "HelpLayer.h"
#include "ChooseLayer.h"
#include "cocos2d.h"


using namespace cocos2d;

class StartLayer : public Layer
{
public:
	static Scene* createScene();
	CREATE_FUNC(StartLayer);
	virtual bool init();
	void menuCallBack(Ref* pSender);
public:
	MenuItemToggle * musicItem;
};

#endif // _Start_Layer_H__
