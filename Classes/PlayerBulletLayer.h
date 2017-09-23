 #ifndef __PlayerBulletLayer_H__  
#define __PlayerBulletLayer_H__  
#include "cocos2d.h"  
USING_NS_CC;

class PlayerBulletLayer : public cocos2d::Layer {
public:
	

	


	static PlayerBulletLayer * create(Node * plane);

	bool init();

	PlayerBulletLayer(Node* plane);
	//系统析构，移除所有
	~PlayerBulletLayer();
	//移除所有
	void removeAllObject();
	//删除子弹
	void removeBullet(Node* pNode);
	
	
	
	void removeBullet_1(Node * pNode);

	void removeBullet_2(Node * pNode);

	void removeBullet_3(Node * pNode);

	void removeBullet_4(Node * pNode);

	void removeBullet_5(Node * pNode);

	void removeBullet_6(Node * pNode);

	void removeBullet_7(Node * pNode);

	//创建子弹
	//参数表 飞行方式，发射频率，飞行速度
	 void createBulletForPlayer(int flyStyle,float fre,float flyVelocity);

	 void stopBulletForPlayer();

	

	
   //子弹发射方式1
    void shootBullet1_ForPlayer(float dt);
	void shootBullet11_ForPlayer(float dt);
	void shootBullet12_ForPlayer(float dt);
	//子弹发射方式2
	void shootBullet2_ForPlayer(float dt);
	void shootBullet10_ForPlayer(float dt);
	//子弹发射方式1
	void shootBullet3_ForPlayer(float dt);

	void shootBullet4_ForPlayer(float dt);

	void shootBullet5_ForPlayer(float dt);

	void shootBullet6_ForPlayer(float dt);

	void shootBullet7_ForPlayer(float dt);
	

public:
	//传入的飞机  
	Node* plane;


	//子弹容器  
	Vector <Sprite *> vecBullet;
	//批次渲染节点  
	SpriteBatchNode* bulletBatchNode_1;
	SpriteBatchNode* bulletBatchNode_2;
	SpriteBatchNode* bulletBatchNode_3;
	SpriteBatchNode* bulletBatchNode_4;
	SpriteBatchNode* bulletBatchNode_5;
	SpriteBatchNode* bulletBatchNode_6;
	SpriteBatchNode* bulletBatchNode_7;





	//飞行速度
	float flyVelocity = 100;
	//发射频率
	float fre = 0.2;
	//飞行方式
	int flyStyle=1;
	

};
#endif