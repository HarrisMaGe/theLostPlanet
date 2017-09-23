#include"backGround_2.h"
#include"GamePause.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;


bool BackGround_2::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	Size winSize = Director::getInstance()->getWinSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto pauseButton = MenuItemImage::create("UI/pause1.png", "UI/pause_pressed.png", CC_CALLBACK_1(BackGround_2::menuPauseCallBack, this));
	auto menu = Menu::create(pauseButton, NULL);
	menu->setPosition(Vec2(winSize.width - 37, 26));
	this->addChild(menu, 4);

	//�ڶ��ر��������
	Sprite* map1 = Sprite::create("/backGround/bg2.jpg");
	Sprite* map2 = Sprite::create("/backGround/bg2.jpg");
	//��һ����������Ļ�м�
	map1->setPosition(Vec2(winSize.width / 2 + origin.x, winSize.height / 2 + origin.y));
	//�ڶ�����������Ļ���Ϸ�
	map2->setPosition(Vec2(winSize.width / 2 + origin.x, winSize.height + origin.y + map2->getContentSize().height / 2));
	this->addChild(map1, 0, Map_2_1);
	this->addChild(map2, 0, Map_2_2);
	//�ڶ��ر�������һ��
	Sprite* map3 = Sprite::create("/backGround/bg2(uplayer).png");
	Sprite* map4 = Sprite::create("/backGround/bg2(uplayer).png");
	map3->setPosition(Vec2(winSize.width / 2 + origin.x, winSize.height / 2 + origin.y));
	map4->setPosition(Vec2(winSize.width / 2 + origin.x, winSize.height + origin.y + map2->getContentSize().height / 2));
	this->addChild(map3, 0, Map_2_3);
	this->addChild(map4, 0, Map_2_4);
	this->scheduleUpdate();
	return true;
}
void BackGround_2::update(float time) 
{
	Size winSize = Director::getInstance()->getWinSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	Sprite*temMap1 = (Sprite*)this->getChildByTag(Map_2_1);
	Sprite*temMap2 = (Sprite*)this->getChildByTag(Map_2_2);
	//������л��ٶ�
	temMap1->setPositionY(temMap1->getPositionY() - 4);
	temMap2->setPositionY(temMap2->getPositionY() - 4);
	//�жϣ����ͼƬ�Ƴ���Ļ���ͽ�ͼƬ�л�����Ļ���Ϸ�
	if (temMap1->getPositionY() + temMap1->getContentSize().height / 2 <= origin.y)
	{
		float offset = temMap1->getPositionY() + temMap1->getContentSize().height / 2 - origin.y;
		temMap1->setPosition(Vec2(winSize.width / 2 + origin.x, temMap1->getContentSize().height / 2 + origin.y + winSize.height + offset));
	}

	if (temMap2->getPositionY() + temMap2->getContentSize().height / 2 <= origin.y)
	{
		float offset = temMap2->getPositionY() + temMap2->getContentSize().height / 2 - origin.y;
		temMap2->setPosition(Vec2(winSize.width / 2 + origin.x, temMap2->getContentSize().height / 2 + origin.y + winSize.height + offset));
	}

	Sprite*temMap3 = (Sprite*)this->getChildByTag(Map_2_3);
	Sprite*temMap4 = (Sprite*)this->getChildByTag(Map_2_4);
	//�����ϲ��ٶ�
	temMap3->setPositionY(temMap3->getPositionY() - 8);
	temMap4->setPositionY(temMap4->getPositionY() - 8);
	if (temMap3->getPositionY() + temMap3->getContentSize().height / 2 <= origin.y) {
		float offset = temMap3->getPositionY() + temMap3->getContentSize().height / 2 - origin.y;
		temMap3->setPosition(Vec2(winSize.width / 2 + origin.x, temMap3->getContentSize().height / 2 + origin.y + winSize.height + offset));
	}
	if (temMap4->getPositionY() + temMap4->getContentSize().height / 2 <= origin.y) {
		float offset = temMap4->getPositionY() + temMap4->getContentSize().height / 2 - origin.y;
		temMap4->setPosition(Vec2(winSize.width / 2 + origin.x, temMap4->getContentSize().height / 2 + origin.y + winSize.height + offset));
	}
}

void BackGround_2::menuPauseCallBack(Ref * pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("music/click.wav");
	//�õ����ڵĴ�С  
	Size winSize = Director::getInstance()->getWinSize();
	RenderTexture *renderTexture = RenderTexture::create(winSize.width, winSize.height);

	//������ǰ��������ӽڵ���Ϣ������renderTexture�С�  
	renderTexture->begin();
	this->getParent()->visit();
	renderTexture->end();

	//����Ϸ������ͣ��ѹ�볡����ջ�����л���GamePause����  
	Scene *se = GamePause::scene(renderTexture);
	GamePause *gp = (GamePause *)se->getChildByTag(123);
	gp->setBG(this);
	Director::getInstance()->pushScene(se);
}

void BackGround_2::onExit() 
{
	this->unscheduleUpdate();
	Layer::onExit();
}


