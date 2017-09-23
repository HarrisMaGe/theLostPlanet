#ifndef __FoodLayer_H__  
#define __FoodLayer_H__  
#include "cocos2d.h"  
using namespace cocos2d;

class FoodLayer : public Layer
{
public:
	FoodLayer();
	static FoodLayer* create();

	virtual bool init();
	void newFood(Node * oB, int type);
	void removeFood(Node* myFood);
	Node * oB;//传入的坐标
	int type;//Food的类型

	 Vector<Sprite *> allFood;
};
#endif
