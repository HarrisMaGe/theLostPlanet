#ifndef __ChooseLoad_Layer_H__
#define _ChooseLoad_Layer_H__

#include "cocos2d.h"
#include "ui/UIVideoPlayer.h"  
#include "ui/CocosGUI.h" 


using namespace cocos2d;

class ChooseLoadLayer : public Layer
{
public:
	static Scene* createScene();
	CREATE_FUNC(ChooseLoadLayer);
	virtual bool init();

	void goGameScene();
	

 	int choose=1;


};

#endif // _ChooseLoad_Layer_H__
