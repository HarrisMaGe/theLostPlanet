#ifndef _Choose_Layer_H__
#define _Choose_Layer_H__

#include "cocos2d.h"


using namespace cocos2d;

class ChooseLayer : public Layer
{
public:
	static Scene* createScene();
	CREATE_FUNC(ChooseLayer);
	virtual bool init();
	void menuCallBack(Ref* pSender);

};

#endif // _Choose_Layer_H__
