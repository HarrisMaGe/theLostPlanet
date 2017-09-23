#include"BackGround.h"
#include "SimpleAudioEngine.h"
#include"backGround_1.h"
#include"backGround_2.h"
#include"BackGround_3.h"

using namespace CocosDenshion;

Layer * BackGround::createBackGround_1() 
{
	return BackGround_1::create();
}

Layer * BackGround::createBackGround_2()
{

	return BackGround_2::create();
}

Layer * BackGround::createBackGround_3()
{

	return BackGround_3::create();
}




