#include "ChooseLoadLayer.h"
#include "SimpleAudioEngine.h"
#include "StartLayer.h"
#include "GameLayer.h"
#include "GameLayer_2.h"
#include "GameLayer_3.h"

USING_NS_CC;
using namespace CocosDenshion;


Scene* ChooseLoadLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = ChooseLoadLayer::create();
	scene->addChild(layer);
	return scene;
}


bool ChooseLoadLayer::init() {

	if (!Layer::init())
	{
		return false;
	}

	
	


	auto visibleSize = Director::getInstance()->getVisibleSize();
	//设置背景
	
	
	Sprite * sprite = Sprite::create("Animation/chooseloading/loading_1.png");
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(sprite, 2);
	//创建Animation
	Animation* animation = Animation::create();

	//直接添加图片资源
	for (int i = 1; i <= 40; i++) {
		char str[80];
		sprintf(str, "Animation/chooseloading/loading_%d.png", i);
		animation->addSpriteFrameWithFile(str); //添加动画帧
	}
	//设置属性
	animation->setRestoreOriginalFrame(true); //还原第一帧
	animation->setDelayPerUnit(0.08);     //单位帧间隔
	animation->setLoops(1);

	Animate* animate = Animate::create(animation);
	auto callFunc = CallFunc::create(this, callfunc_selector(ChooseLoadLayer::goGameScene));
	auto action = Sequence::create(animate, callFunc, NULL);
	sprite->runAction(action);
	
	
	
	
	
	
/*	
	auto ChooseLoadBackGround = Sprite::create("backGround/loadLayer.png");
	ChooseLoadBackGround->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(ChooseLoadBackGround);
	//设置为条形进度条
	Sprite * bar = Sprite::create("backGround/loadLayer (2).png");
	auto ChooseLoadingBar = ProgressTimer::create(bar);
	ChooseLoadingBar->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(ChooseLoadingBar);

	ChooseLoadingBar->setPercentage(10);
	ChooseLoadingBar->setType(kCCProgressTimerTypeBar);
	ChooseLoadingBar->setBarChangeRate(Point(1, 0));
	ChooseLoadingBar->setMidpoint(Point(1, 0));

	//进度条从右往左加载
	ProgressFromTo * action_1 = ProgressFromTo::create(10.0, 20, 100);
	auto action = EaseExponentialInOut::create(action_1);
	ChooseLoadingBar->runAction(action);
	*/

	
	
	return true;
}

void ChooseLoadLayer::goGameScene() {
	SimpleAudioEngine::getInstance()->stopBackgroundMusic("music/selectlevel.mp3");
	if (choose==1)
	{
		Director::getInstance()->replaceScene(GameLayer::createScene());
	}
	if (choose == 2)
	{
		Director::getInstance()->replaceScene(GameLayer_2::createScene());
	}
	if (choose == 3)
	{
		Director::getInstance()->replaceScene(GameLayer_3::createScene());
	}
	
}
