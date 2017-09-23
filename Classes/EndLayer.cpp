#include "EndLayer.h"
#include "StartLayer.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* EndLayer::createScene() {
	SimpleAudioEngine::getInstance()->playBackgroundMusic("music/main.mp3", true);
	auto scene = Scene::create();
	auto layer = EndLayer::create();
	scene->addChild(layer);
	return scene;
}

bool EndLayer::init() {
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();

	Sprite * background = Sprite::create("Animation/ending/end (1).jpg");
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(background, 0);

	Sprite * sp1 = Sprite::create("Animation/ending/end (10).jpg");
	sp1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	sp1->setOpacity(0);
	this->addChild(sp1, 1);

	Sprite * sp2 = Sprite::create("Animation/ending/end (20).jpg");
	sp2->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	sp2->setOpacity(0);
	this->addChild(sp2, 2);

	Sprite * sp3 = Sprite::create("Animation/ending/end (125).jpg");
	sp3->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	sp3->setOpacity(0);
	this->addChild(sp3, 3);

	Sprite * sp4 = Sprite::create("Animation/ending/end (188).jpg");
	sp4->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	sp4->setOpacity(0);
	this->addChild(sp4, 4);

	auto delay1 = DelayTime::create(5);		//场景切换的等待时间
	auto delay2 = DelayTime::create(3);
	auto delay3 = DelayTime::create(7);
	FadeIn * fade1 = FadeIn::create(3);
	FadeIn * fade2 = FadeIn::create(6);

	auto callFunc = CallFunc::create(this, callfunc_selector(EndLayer::goStartScene));

	auto a1 = Sequence::create(delay1, fade1, NULL);
	auto a2 = Sequence::create(delay1, delay2, fade1, NULL);
	auto a3 = Sequence::create(delay1, delay2, delay2, fade2, NULL);
	auto a4 = Sequence::create(delay1, delay2, delay2, delay3, fade2, callFunc, NULL);
	sp1->runAction(a1);
	sp2->runAction(a2);
	sp3->runAction(a3);
	sp4->runAction(a4);

	return true;
}
void EndLayer::goStartScene() {
	auto transfer = TransitionFade::create(6, StartLayer::createScene());
	Director::getInstance()->replaceScene(transfer);
}