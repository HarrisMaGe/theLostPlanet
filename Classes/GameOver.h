#ifndef _GameOver_
#define _GameOver_

#include"cocos2d.h"
USING_NS_CC;

class GameOver :public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(GameOver);
	static Scene *scene(RenderTexture * sqr);
	void menuContinueCallBack(Ref * pSender);
	void menuMain(Ref * pSender);

	void setBG(void *p);
	int choose = 1;
private:
	void *m_bg;
};
#endif // !_GAMEOver_



