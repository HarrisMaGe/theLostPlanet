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
	//�رձ�������
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	//������������
	SimpleAudioEngine::getInstance()->playBackgroundMusic("music/main.mp3", true);
	SimpleAudioEngine::getInstance()->setEffectsVolume(1);

	auto winSize = Director::getInstance()->getWinSize();

	//��ʼ���汳��ͼƬ
	auto startBackGround = Sprite::create("backGround/main.png");
	startBackGround->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	this->addChild(startBackGround);
	// ��ʼ��ť
	auto startItem = MenuItemImage::create("item/start1.png",
		"item/start2.png",
		CC_CALLBACK_1(StartLayer::menuCallBack, this));
	startItem->setTag(1);
	//���ڰ�ť
	auto aboutItem = MenuItemImage::create("item/about1.png",
		"item/about2.png",
		CC_CALLBACK_1(StartLayer::menuCallBack, this));
	aboutItem->setTag(2);
	//������ť
	auto helpItem = MenuItemImage::create(
		"item/help1.png",
		"item/help2.png",
		CC_CALLBACK_1(StartLayer::menuCallBack, this));
	helpItem->setTag(3);
	//�˳���ť
	auto closeItem = MenuItemImage::create(
		"item/out1.png",
		"item/out2.png",
		CC_CALLBACK_1(StartLayer::menuCallBack, this));
	closeItem->setTag(4);
	//���ְ�ť(����Ĭ�ϲ���)
	auto musicItem_1 = MenuItemImage::create("UI/sound.png", "UI/sound.png");
	auto musicItem_2 = MenuItemImage::create("UI/nosound.png", "UI/nosound.png");
	musicItem = MenuItemToggle::createWithTarget(
		this, menu_selector(StartLayer::menuCallBack),
		musicItem_1, musicItem_2, NULL);
	musicItem->setTag(5);

	// ��Ӳ˵�
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
	//ͨ��tag���ٴ�����
	SimpleAudioEngine::getInstance()->playEffect("music/click.wav");
	switch (nowItem->getTag())
	{
	case 1://��ʼ
		Director::getInstance()->pushScene(ChooseLayer::createScene());
		break;
	case 2://����
		Director::getInstance()->pushScene(AboutLayer::createScene());
		break;
	case 3://����
		Director::getInstance()->pushScene(HelpLayer::createScene());
		break;
	case 4://�˳�
		Director::getInstance()->end();
		break;
	case 5://���ֹرգ�
		musicItem->setTag(6);
		SimpleAudioEngine::getInstance()->stopBackgroundMusic("music/main.mp3");
		break;
	case 6://���ֿ���
		musicItem->setTag(5);
		SimpleAudioEngine::getInstance()->playBackgroundMusic("music/main.mp3", true);
		break;
	}
}