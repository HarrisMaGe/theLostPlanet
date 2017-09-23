#include"GameOver.h"
#include"BackGround_1.h"
#include"StartLayer.h"
#include "ChooseLoadLayer.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

Scene *GameOver::scene(RenderTexture * sqr)
{
	Scene * scene = Scene::create();
	GameOver * layer = GameOver::create();
	scene->addChild(layer, 1);
	layer->setTag(123);

	Size winSize = Director::getInstance()->getWinSize();
	Sprite * back = Sprite::createWithTexture(sqr->getSprite()->getTexture());


	back->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	back->setFlipY(true);
	//back->setColor(ccGRAY);
	scene->addChild(back);
	return scene;
}

bool GameOver::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//得到窗口的大小  
	Size winSize = Director::getInstance()->getWinSize();
	Point origin = Director::getInstance()->getVisibleOrigin();



	auto deathBackGround = Sprite::create("UI/death.png");
	deathBackGround->setPosition(winSize.width / 2, winSize.height / 2);





	MenuItemImage * continueItem = MenuItemImage::create("UI/reStart01.png", "UI/reStart02.png", this, menu_selector(GameOver::menuContinueCallBack));
	//continueItem->setPosition(Vec2(256, 404));

	MenuItemImage * backItem = MenuItemImage::create("UI/return01.png", "UI/return02.png", this, menu_selector(GameOver::menuMain));
	//backItem->setPosition(Vec2(256, 364));

	Menu * pmenu = Menu::create(continueItem, backItem, NULL);
	pmenu->alignItemsHorizontallyWithPadding(10);
	pmenu->setPosition(Vec2(winSize.width / 2, winSize.height / 2));


	this->addChild(deathBackGround);
	this->addChild(pmenu);
	return true;
}
//重新开始
void GameOver::menuContinueCallBack(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("music/click.wav");
	if (choose == 1)
	{
		ChooseLoadLayer *myLoadLayer = ChooseLoadLayer::create();
		myLoadLayer->choose = 1;
		Scene* myScene = Scene::create();
		myScene->addChild(myLoadLayer);
		Director::getInstance()->replaceScene(myScene);
	}
	if (choose == 2)
	{
		ChooseLoadLayer *myLoadLayer = ChooseLoadLayer::create();
		myLoadLayer->choose = 2;
		Scene* myScene = Scene::create();
		myScene->addChild(myLoadLayer);
		Director::getInstance()->replaceScene(myScene);
	}
	if (choose == 3)
	{
		ChooseLoadLayer *myLoadLayer = ChooseLoadLayer::create();
		myLoadLayer->choose = 3;
		Scene* myScene = Scene::create();
		myScene->addChild(myLoadLayer);
		Director::getInstance()->replaceScene(myScene);
	}if (choose == 4)
	{
		ChooseLoadLayer *myLoadLayer = ChooseLoadLayer::create();
		myLoadLayer->choose = 4;
		Scene* myScene = Scene::create();
		myScene->addChild(myLoadLayer);
		Director::getInstance()->replaceScene(myScene);
	}
}

void GameOver::menuMain(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("music/click.wav");
	Director::getInstance()->replaceScene(StartLayer::createScene());
}

void GameOver::setBG(void *p)
{
	m_bg = p;
}