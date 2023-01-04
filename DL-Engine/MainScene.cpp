#include "stdafx.h"
#include "MainScene.h"

MainScene::MainScene() {
	icon = new Sprite(L"Resources/Images/icon.png");
	AddObject(icon);
	icon->setPos(0, 0);
	
	icon->setRotationCenter(icon->getWidth() / 2, icon->getHeight() / 2);
	icon->setScale(0.5f, 0.5f);
}

MainScene::~MainScene() {

}

void MainScene::Render() {
	icon->Render();
}

void MainScene::Update(float dTime) {
	Scene::Update(dTime);
	if(inputManager->GetKeyState('A') == KEY_ON)
		icon->setRotation(icon->getRotation() + dTime * 100);
}