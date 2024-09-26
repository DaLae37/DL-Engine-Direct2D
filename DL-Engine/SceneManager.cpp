#include "stdafx.h"
#include "SceneManager.h"

SceneManager::SceneManager() {
	currentScene = nullptr;
}

SceneManager::~SceneManager() {
	SAFE_DELETE(currentScene);
}

void SceneManager::Render() {
	currentScene->Render();
}

void SceneManager::Update(float dTime) {
	currentScene->Update(dTime);
}

void SceneManager::ChangeScene(Scene* scene, std::string sceneName, bool deleteBeforeScene) {
	if (deleteBeforeScene) {
		SAFE_DELETE(currentScene);
		scenes.erase(sceneName);
	}

	scene->LoadResourceData();
	std::unique_ptr<std::thread*> sceneLoad = std::make_unique<std::thread*>(new std::thread(&Scene::LoadResourceFromFiles, scene));
	currentScene = scene;

	if (scenes.find(sceneName) != scenes.end()) {
		SAFE_DELETE(scenes[sceneName]);
		scenes.erase(sceneName);
	}
	else {
		scenes[sceneName] = scene;
	}
}

D2D_COLOR_F SceneManager::GetCurrentSceneBackgroundColor() {
	return currentScene->getBackgroundColor();
}