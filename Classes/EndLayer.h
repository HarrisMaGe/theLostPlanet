#ifndef __End_Layer_H__
#define _End_Layer_H__

#include "cocos2d.h"

using namespace cocos2d;

class EndLayer : public Layer
{
public:
	static Scene* createScene();
	CREATE_FUNC(EndLayer);
	virtual bool init();
	void goStartScene();
};

#endif // __End_Layer_H__
