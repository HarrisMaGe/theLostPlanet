#ifndef __Load_Layer_H__
#define _Load_Layer_H__

#include "cocos2d.h"

using namespace cocos2d;

class LoadLayer : public Layer
{
public:
	static Scene* createScene();
	CREATE_FUNC(LoadLayer);
	virtual bool init();
	//键盘响应事件
	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
	//单次调度器
	void skipAnimation(float dt);
	void goStartScene();
	void secondLoading();
	void thirdLoading();
	void fourthLoading();
	void fifthLoading();
	void sixthLoading();

};

#endif // _Load_Layer_H__
