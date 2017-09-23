#ifndef _GAMEPAUSE_
#define _GAMEPAUSE_

#include"cocos2d.h"
#include"LoadLayer.h"
USING_NS_CC;

class GamePause :public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(GamePause);
	static Scene *scene(RenderTexture * sqr);
	void menuContinueCallBack(Ref * pSender);
	void menuMain(Ref * pSender);

	void setBG(void *p);

private:
	void *m_bg;
};
#endif // !_GAMEPAUSE_



