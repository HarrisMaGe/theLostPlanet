#include "StartLayer.h"
#include "SimpleAudioEngine.h"
#include "GameLayer.h"
#include "AboutLayer.h"
#include "HelpLayer.h"
#include "ChooseLayer.h"
USING_NS_CC;
using namespace CocosDenshion;


Scene* StartLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = StartLayer::create();
	scene->addChild(layer);
	return scene;
}



bool StartLayer::init() {

	if (!Layer::init())
	{
		return false;
	}
	//关闭背景音乐
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	//新增背景音乐
	SimpleAudioEngine::getInstance()->playBackgroundMusic("music/main.mp3", true);
	SimpleAudioEngine::getInstance()->setEffectsVolume(1);

	auto winSize = Director::getInstance()->getWinSize();

	//开始界面背景图片
	auto startBackGround = Sprite::create("backGround/main.png");
	startBackGround->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	this->addChild(startBackGround);
	// 开始按钮
	auto startItem = MenuItemImage::create("item/start1.png",
		"item/start2.png",
		CC_CALLBACK_1(StartLayer::menuCallBack, this));
	startItem->setTag(1);
	//关于按钮
	auto aboutItem = MenuItemImage::create("item/about1.png",
		"item/about2.png",
		CC_CALLBACK_1(StartLayer::menuCallBack, this));
	aboutItem->setTag(2);
	//帮助按钮
	auto helpItem = MenuItemImage::create(
		"item/help1.png",
		"item/help2.png",
		CC_CALLBACK_1(StartLayer::menuCallBack, this));
	helpItem->setTag(3);
	//退出按钮
	auto closeItem = MenuItemImage::create(
		"item/out1.png",
		"item/out2.png",
		CC_CALLBACK_1(StartLayer::menuCallBack, this));
	closeItem->setTag(4);
	//音乐按钮(音乐默认播放)
	auto musicItem_1 = MenuItemImage::create("UI/sound.png", "UI/sound.png");
	auto musicItem_2 = MenuItemImage::create("UI/nosound.png", "UI/nosound.png");
	musicItem = MenuItemToggle::createWithTarget(
		this, menu_selector(StartLayer::menuCallBack),
		musicItem_1, musicItem_2, NULL);
	musicItem->setTag(5);

	// 添加菜单
	auto startMenu = Menu::create(startItem, NULL);
	startMenu->setPosition(Vec2(131, 454));
	this->addChild(startMenu);

	auto aboutMenu = Menu::create(aboutItem, NULL);
	aboutMenu->setPosition(Vec2(381, 454));
	this->addChild(aboutMenu);

	auto helpMenu = Menu::create(helpItem, NULL);
	helpMenu->setPosition(Vec2(52, 565));
	this->addChild(helpMenu);

	auto closeMenu = Menu::create(closeItem, NULL);
	closeMenu->setPosition(Vec2(453, 565));
	this->addChild(closeMenu);

	auto musicMenu = Menu::create(musicItem, NULL);
	musicMenu->setAnchorPoint(Vec2(1, 0));
	musicMenu->setPosition(Vec2(winSize.width-60,55));
	this->addChild(musicMenu);

	return true;

}


void StartLayer::menuCallBack(Ref* pSender) {
	MenuItem * nowItem = (MenuItem *)pSender;
	//通过tag减少代码量
	SimpleAudioEngine::getInstance()->playEffect("music/click.wav");
	switch (nowItem->getTag())
	{
	case 1://开始
		Director::getInstance()->pushScene(ChooseLayer::createScene());
		break;
	case 2://关于
		Director::getInstance()->pushScene(AboutLayer::createScene());
		break;
	case 3://帮助
		Director::getInstance()->pushScene(HelpLayer::createScene());
		break;
	case 4://退出
		Director::getInstance()->end();
		break;
	case 5://音乐关闭：
		musicItem->setTag(6);
		SimpleAudioEngine::getInstance()->stopBackgroundMusic("music/main.mp3");
		break;
	case 6://音乐开启
		musicItem->setTag(5);
		SimpleAudioEngine::getInstance()->playBackgroundMusic("music/main.mp3", true);
		break;
	}
}