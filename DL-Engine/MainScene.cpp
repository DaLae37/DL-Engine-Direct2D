#include "stdafx.h"
#include "MainScene.h"
#include "GameScene.h"

MainScene::MainScene() {
	icon = new Sprite(L"Resources/Images/MainScene/mainScene.jpg");
	icon->setPos(0, 0);
	icon->setRotationCenter(icon->getWidth() / 2, icon->getHeight() / 2);
	AddObject(icon);

	soundManager->LoadAudioFromFile(L"Resources/Sounds/BackgroundSound.wav");
}

MainScene::~MainScene() {

}

void MainScene::Render() {
	Scene::Render();
}

void MainScene::Update(float dTime) {
	Scene::Update(dTime);
	icon->setRotation(180);

	if (inputManager->GetKeyState(VK_SPACE) == KEY_DOWN) {
		sceneManager->ChangeScene(new GameScene());
	}
}