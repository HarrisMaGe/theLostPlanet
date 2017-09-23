#include"GamePause.h"
#include"BackGround_1.h"
#include "SimpleAudioEngine.h"
#include "StartLayer.h"

using namespace CocosDenshion;
Scene *GamePause::scene(RenderTexture * sqr)
{
	Scene * scene = Scene::create();
	GamePause * layer = GamePause::create();
	scene->addChild(layer,1);
	layer->setTag(123);

	Size winSize = Director::getInstance()->getWinSize();
	Sprite * back = Sprite::createWithTexture(sqr->getSprite()->getTexture());
	

	back->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	back->setFlipY(true);
	//back->setColor(ccGRAY);
	scene->addChild(back);
	return scene;
}

bool GamePause::init() 
{
	if (!Layer::init()) 
	{
		return false;
	}
	Size winSize = Director::getInstance()->getWinSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	
	MenuItemImage * continueItem = MenuItemImage::create("UI/continue_1.png","UI/continue_2.png",this,menu_selector(GamePause::menuContinueCallBack));
	

	MenuItemImage * backItem = MenuItemImage::create("UI/return_1.png", "UI/return_2.png", this, menu_selector(GamePause::menuMain));
	

	Menu * pmenu = Menu::create(continueItem, backItem,NULL);
	pmenu->alignItemsHorizontallyWithPadding(15);
		pmenu->setPosition(Vec2(winSize.width/2,winSize.height/2-30));
	Sprite * pause = Sprite::create("UI/pause.png");
	pause->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	this->addChild(pause);
	this->addChild(pmenu,2);
	return true;
}

void GamePause::menuContinueCallBack(Ref * pSender) 
{
	SimpleAudioEngine::getInstance()->playEffect("music/click.wav");
	Director::getInstance()->popScene();
	((BackGround_1 *)m_bg)->scheduleUpdate();
}
void GamePause::menuMain(Ref * pSender) 
{
	SimpleAudioEngine::getInstance()->playEffect("music/click.wav");
	Director::getInstance()->replaceScene(StartLayer::createScene());
}

void GamePause::setBG(void *p) 
{
	m_bg = p;
}
