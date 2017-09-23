#include "HelpLayer.h"
#include "StartLayer.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;
Scene* HelpLayer::createScene() {
	auto scene = Scene::create();
	auto layer = HelpLayer::create();
	scene->addChild(layer);
	return scene;
}

bool HelpLayer::init() {
	if (!Layer::init())
	{
		return false;
	}
	//����ͼƬ
	Size winSize = Director::getInstance()->getWinSize();
	Sprite * aboutBackGround = Sprite::create("backGround/help.png");
	aboutBackGround->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	this->addChild(aboutBackGround);

	//���ذ�ť
	auto returnItem = MenuItemImage::create("item/backA.png",
		"item/backB.png",
		CC_CALLBACK_1(HelpLayer::menuCallBack, this));
	returnItem->setTag(1);
	auto returnMenu = Menu::create(returnItem, NULL);
	//���ð�ť����Ļ���½�
	returnMenu->setAnchorPoint(Vec2(1, 0));
	returnMenu->setPosition(Vec2(winSize.width - 40, 47));
	this->addChild(returnMenu);
	return true;
}

void HelpLayer::menuCallBack(Ref* pSender) {
	SimpleAudioEngine::getInstance()->playEffect("music/click.wav");
	MenuItem * nowItem = (MenuItem *)pSender;
	if (nowItem->getTag() == 1) {
		Director::getInstance()->popScene();
	}
}