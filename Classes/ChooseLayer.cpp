#include "ChooseLayer.h"
#include "SimpleAudioEngine.h"
#include "GameLayer.h"
#include "AboutLayer.h"
#include "HelpLayer.h"
#include "StartLayer.h"
#include "ChooseLoadLayer.h"
USING_NS_CC;
using namespace CocosDenshion;


Scene* ChooseLayer::createScene()
{
	
	auto scene = Scene::create();
	auto layer = ChooseLayer::create();
	scene->addChild(layer);
	return scene;
}



bool ChooseLayer::init() {

	if (!Layer::init())
	{
		return false;
	}
	auto winSize = Director::getInstance()->getWinSize();
	//�رձ�������
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	//������������
	SimpleAudioEngine::getInstance()->playBackgroundMusic("music/selectlevel.mp3", true);


	//����ͼƬ
	auto ChooseBackGround = Sprite::create("backGround/choose.png");
	ChooseBackGround->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	this->addChild(ChooseBackGround);
	// ��һ��
	auto firstItem = MenuItemImage::create(
		"backGround/first.png",
		"backGround/first.png",
		CC_CALLBACK_1(ChooseLayer::menuCallBack, this));
	firstItem->setTag(1);
	//�ڶ���
	auto secondItem = MenuItemImage::create(
		"backGround/second.png",
		"backGround/second.png",
		CC_CALLBACK_1(ChooseLayer::menuCallBack, this));
	secondItem->setTag(2);
	//������
	auto thirdItem = MenuItemImage::create(
		"backGround/third.png",
		"backGround/third.png",
		CC_CALLBACK_1(ChooseLayer::menuCallBack, this));
	thirdItem->setTag(3);
	//����
	auto returnItem = MenuItemImage::create(
		"backGround/backA.png",
		"backGround/backB.png",
		CC_CALLBACK_1(ChooseLayer::menuCallBack, this));
	returnItem->setTag(4);

	// ��Ӳ˵�
	auto firstMenu = Menu::create(firstItem, NULL);
	firstMenu->setPosition(Vec2(420, 150));
	this->addChild(firstMenu);

	auto secondMenu = Menu::create(secondItem, NULL);
	secondMenu->setPosition(Vec2(81,301));
	this->addChild(secondMenu);

	auto thirdMenu = Menu::create(thirdItem, NULL);
	thirdMenu->setPosition(Vec2(406,449));
	this->addChild(thirdMenu);

	auto returnMenu = Menu::create(returnItem, NULL);
	returnMenu->setPosition(Vec2(60, 47));
	this->addChild(returnMenu);



	return true;

}


void ChooseLayer::menuCallBack(Ref* pSender) {

	SimpleAudioEngine::getInstance()->playEffect("music/click.wav");
	MenuItem * nowItem = (MenuItem *)pSender;
	//ͨ��tag���ٴ�����
	if (nowItem->getTag()==1)
	{
		ChooseLoadLayer *myLoadLayer = ChooseLoadLayer::create();
		myLoadLayer->choose = 1;
		Scene* myScene = Scene::create();
		myScene->addChild(myLoadLayer);
		Director::getInstance()->replaceScene(myScene);
	}
	if (nowItem->getTag() == 2)
	{
		ChooseLoadLayer *myLoadLayer = ChooseLoadLayer::create();
		myLoadLayer->choose = 2;
		Scene* myScene = Scene::create();
		myScene->addChild(myLoadLayer);
		Director::getInstance()->replaceScene(myScene);
	}
	if (nowItem->getTag() == 3)
	{
		ChooseLoadLayer *myLoadLayer = ChooseLoadLayer::create();
		myLoadLayer->choose = 3;
		Scene* myScene = Scene::create();
		myScene->addChild(myLoadLayer);
		Director::getInstance()->replaceScene(myScene);
	}if (nowItem->getTag() == 4)
	{
		Director::getInstance()->replaceScene(StartLayer::createScene());
	}
		
	
	
}