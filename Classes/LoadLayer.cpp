#include "LoadLayer.h"
#include "SimpleAudioEngine.h"
#include "StartLayer.h"

USING_NS_CC;
using namespace CocosDenshion;

//设置等待时间3,5,5,3
float d1 = 2.0;
float d2 = 4.0;
float i = 4.0;
float o = 2.0;
float bg = d1 + d2 + i + o + 1.0;

Scene* LoadLayer::createScene()
{
	SimpleAudioEngine::getInstance()->playBackgroundMusic("music/main.mp3", true);
	auto scene = Scene::create();
	auto layer = LoadLayer::create();
	scene->addChild(layer);
	return scene;
}


bool LoadLayer::init() {
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//创建Animation
	Animation * animation = Animation::create();
	//直接添加图片资源
	for (int i = 778; i <= 990; i++) {
		char str[80];
		sprintf(str, "Animation/startloading/begin (%d).jpg", i);
		animation->addSpriteFrameWithFile(str); //添加动画帧
	}
	//设置属性
	animation->setDelayPerUnit(0.03);
	animation->setLoops(1);

	AnimationCache::sharedAnimationCache()->addAnimation(animation, "planet");

	auto background_1 = Sprite::create("Animation/startloading/bg1.png");
	background_1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(background_1, 5);

	//第一个动画
	auto sp1 = Sprite::create("Animation/startloading/begin1.png");
	sp1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	sp1->setOpacity(0);
	this->addChild(sp1, 5);

	//初始化等待时间与淡入淡出时间
	auto delay1 = DelayTime::create(d1);
	auto delay2 = DelayTime::create(d2);
	auto delay_bg = DelayTime::create(bg);
	auto in = FadeIn::create(i);
	auto out = FadeOut::create(o);

	auto callFunc = CallFunc::create(this, callfunc_selector(LoadLayer::secondLoading));
	auto action_sp1 = Sequence::create(delay1, in, delay2, out, NULL);
	auto action_bg1 = Sequence::create(delay_bg, out, callFunc, NULL);
	sp1->runAction(action_sp1);
	background_1->runAction(action_bg1);

	//添加监听器跳过
	auto keyListener = EventListenerKeyboard::create();
	keyListener->onKeyPressed = CC_CALLBACK_2(LoadLayer::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(LoadLayer::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	return true;
}

void LoadLayer::onKeyPressed(
	EventKeyboard::KeyCode keyCode, Event* event) {
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_SPACE:
	case EventKeyboard::KeyCode::KEY_ENTER:
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		this->schedule(schedule_selector(LoadLayer::skipAnimation), 0.01);
		break;
	default:
		break;
	}
}
void LoadLayer::onKeyReleased(
	EventKeyboard::KeyCode keyCode, Event* event) {
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_SPACE:
	case EventKeyboard::KeyCode::KEY_ENTER:
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		unschedule(schedule_selector(LoadLayer::skipAnimation));
		break;
	default:
		break;
	}
}

//跳过剧情的调度器
void LoadLayer::skipAnimation(float dt) {
	AnimationCache::destroyInstance();
	Director::getInstance()->replaceScene(StartLayer::createScene());
}

void LoadLayer::goStartScene() {
	AnimationCache::destroyInstance();
	Director::getInstance()->replaceScene(StartLayer::createScene());
}

void LoadLayer::secondLoading() {
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto background_2 = Sprite::create("Animation/startloading/bg2.png");
	background_2->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(background_2, 4);

	auto sp2 = Sprite::create("Animation/startloading/begin2.png");
	sp2->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	sp2->setOpacity(0);
	this->addChild(sp2, 4);

	//初始化等待时间与淡入淡出时间
	auto delay1 = DelayTime::create(d1);
	auto delay2 = DelayTime::create(d2);
	auto delay_bg = DelayTime::create(bg);
	auto in = FadeIn::create(i);
	auto out = FadeOut::create(o);

	auto callFunc_2 = CallFunc::create(this, callfunc_selector(LoadLayer::thirdLoading));
	auto action_sp2 = Sequence::create(delay1, in, delay2, out, NULL);
	auto action_bg2 = Sequence::create(delay_bg, out, callFunc_2, NULL);
	sp2->runAction(action_sp2);
	background_2->runAction(action_bg2);
}

void LoadLayer::thirdLoading() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto background_3 = Sprite::create("Animation/startloading/bg3.png");
	background_3->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(background_3, 3);

	auto sp3 = Sprite::create("Animation/startloading/begin3.png");
	sp3->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	sp3->setOpacity(0);
	this->addChild(sp3, 3);

	//初始化等待时间与淡入淡出时间
	auto delay1 = DelayTime::create(d1);
	auto delay2 = DelayTime::create(d2);
	auto delay_bg = DelayTime::create(bg);
	auto in = FadeIn::create(i);
	auto out = FadeOut::create(o);

	auto callFunc_3 = CallFunc::create(this, callfunc_selector(LoadLayer::fourthLoading));
	auto action_sp3 = Sequence::create(delay1, in, delay2, out, NULL);
	auto action_bg3 = Sequence::create(delay_bg, out, callFunc_3, NULL);
	sp3->runAction(action_sp3);
	background_3->runAction(action_bg3);
}

void LoadLayer::fourthLoading() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto background_4 = Sprite::create("Animation/startloading/bg4.png");
	background_4->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(background_4, 2);

	auto sp4 = Sprite::create("Animation/startloading/begin4.png");
	sp4->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	sp4->setOpacity(0);
	this->addChild(sp4, 2);

	//初始化等待时间与淡入淡出时间
	auto delay1 = DelayTime::create(d1);
	auto delay2 = DelayTime::create(d2);
	auto delay_bg = DelayTime::create(bg);
	auto in = FadeIn::create(i);
	auto out = FadeOut::create(o);

	auto callFunc_4 = CallFunc::create(this, callfunc_selector(LoadLayer::fifthLoading));
	auto action_sp4 = Sequence::create(delay1, in, delay2, out, NULL);
	auto action_bg4 = Sequence::create(delay_bg, out, callFunc_4, NULL);
	sp4->runAction(action_sp4);
	background_4->runAction(action_bg4);
}

void LoadLayer::fifthLoading() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto background_5 = Sprite::create("Animation/startloading/bg5.png");
	background_5->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(background_5, 1);

	auto sp5 = Sprite::create("Animation/startloading/begin5.png");
	sp5->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	sp5->setOpacity(0);
	this->addChild(sp5, 1);

	//初始化等待时间与淡入淡出时间
	auto delay1 = DelayTime::create(d1);
	auto delay2 = DelayTime::create(d2);
	auto delay_bg = DelayTime::create(bg);
	auto in = FadeIn::create(i);
	auto out = FadeOut::create(o);

	auto callFunc_5 = CallFunc::create(this, callfunc_selector(LoadLayer::sixthLoading));
	auto action_sp5 = Sequence::create(delay1, in, delay2, out, NULL);
	auto action_bg5 = Sequence::create(delay_bg, out, callFunc_5, NULL);
	sp5->runAction(action_sp5);
	background_5->runAction(action_bg5);

}

void LoadLayer::sixthLoading() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	//创建精灵sprite
	auto sprite = Sprite::create();
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(sprite);

	Animation * planet = AnimationCache::sharedAnimationCache()->animationByName("planet");
	Animate * animate = Animate::create(planet);
	auto callFunc = CallFunc::create(this, callfunc_selector(LoadLayer::goStartScene));
	auto action = Sequence::create(animate, callFunc, NULL);
	sprite->runAction(action);
	SimpleAudioEngine::getInstance()->playEffect("music/planet.wav");

}