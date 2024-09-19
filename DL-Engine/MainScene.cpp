#include "stdafx.h"
#include "MainScene.h"
#include "GameScene.h"

MainScene::MainScene() {
	setBackgroundColor(Color::black);
	LoadResource();
}

MainScene::~MainScene() {

}

void MainScene::LoadResource() {
	soundManager->LoadAudioFromFile(L"Resources/Sounds/BackgroundSound.wav");

	background = new Sprite(L"Resources/Images/MainScene/mainScene.jpg");
	AddObject(background);

	resetButton = new Sprite(L"Resources/Images/MainScene/reset1.png");
	resetButton->setPos(100, 400);
	resetButton->set_z_index(2);
	AddObject(resetButton);

	startButton = new Sprite(L"Resources/Images/MainScene/start1.png");
	startButton->setPos(100, 400);
	startButton->set_z_index(1);
	AddObject(startButton);

	endButton = new Sprite(L"Resources/Images/MainScene/end1.png");
	endButton->setPos(100, 550);
	AddObject(endButton);
}

void MainScene::Render() {
	Scene::Render();
}

void MainScene::Update(float dTime) {
	Scene::Update(dTime);

	if (inputManager->GetKeyState(VK_LBUTTON) == KEY_DOWN) {
		if (startButton->IsPointInRect(inputManager->GetMousePos())) {
			sceneManager->ChangeScene(new GameScene());
			return;
		}
		if (endButton->IsPointInRect(inputManager->GetMousePos())) {
			PostQuitMessage(0);
			return;
		}
	}
}