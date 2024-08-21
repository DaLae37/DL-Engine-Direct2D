#include "stdafx.h"
#include "MainScene.h"
#include "GameScene.h"

MainScene::MainScene() {
	setBackgroundColor(Color::black);

	LoadResource();
	soundManager->LoadAudioFromFile(L"Resources/Sounds/BackgroundSound.wav");
}

MainScene::~MainScene() {

}

void MainScene::LoadResource() {
	background = new Sprite(L"Resources/Images/MainScene/mainScene.jpg");
	AddObject(background);

	resetButton = new Sprite(L"Resources/Images/MainScene/reset1.png");
	AddObject(resetButton);

	startButton = new Sprite(L"Resources/Images/MainScene/start1.png");
	AddObject(startButton);

	endButton = new Sprite(L"Resources/Images/MainScene/end1.png");
	AddObject(endButton);
}

void MainScene::Render() {
	Scene::Render();
}

void MainScene::Update(float dTime) {
	Scene::Update(dTime);

	if (inputManager->GetKeyState(VK_SPACE) == KEY_DOWN) {
		sceneManager->ChangeScene(new GameScene());
	}
}