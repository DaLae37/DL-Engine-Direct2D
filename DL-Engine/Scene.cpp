#include "stdafx.h"
#include "Scene.h"

Scene::Scene(std::string sceneName) {
	this->sceneName = sceneName;
	backgroundColor = { 1.0f, 1.0f, 1.0f, 1.0f };
	isSceneLoaded = false;
}

Scene::~Scene() {
	for (auto& object : objects) {
		SAFE_DELETE(object);
	}
	for (auto& ui : UIs) {
		SAFE_DELETE(ui);
	}
}

void Scene::Render() {
	if (isSceneLoaded) {
		std::sort(objects.begin(), objects.end(), Object::compare_z_index);
		for (auto& object : objects) {
			if (object->getIsActive()) {
				object->Render();
			}
		}

		for (auto& ui : UIs) {
			ui->Render();
		}
	}
}

void Scene::Update(float dTime) {
	if (isSceneLoaded) {
		for (auto& object : objects) {
			if (object->getIsActive()) {
				object->Update(dTime);
			}
		}

		for (auto& ui : UIs) {
			ui->Update(dTime);
		}
	}
}

void Scene::LoadResourceFromFiles() {
	int numObjects = objects.size();
	int numUIs = UIs.size();

	for (int i = 0; i < numObjects; i++) {
		objects[i]->LoadResourceFromFiles();
	}
	for (int i = 0; i < numUIs; i++) {
		UIs[i]->LoadResourceFromFiles();
	}

	isSceneLoaded = true;
}

void Scene::AddObject(Object* object) {
	objects.push_back(object);
	object->setParent(nullptr);
}

void Scene::RemoveObject(Object* object) {
	for (std::vector<Object*>::iterator iter = objects.begin(); iter != objects.end(); iter++) {
		if ((*iter) == object) {
			objects.erase(iter);
			SAFE_DELETE(object);
			break;
		}
	}
}

void Scene::AddUI(Object* ui) {
	UIs.push_back(ui);
	ui->setParent(nullptr);
}

void Scene::RemoveUI(Object* ui) {
	for (std::vector<Object*>::iterator iter = UIs.begin(); iter != UIs.end(); iter++) {
		if ((*iter) == ui) {
			UIs.erase(iter);
			SAFE_DELETE(ui);
			break;
		}
	}
}

void Scene::setBackgroundColor(D2D_COLOR_F backgroundColor) {
	this->backgroundColor = backgroundColor;
}

D2D1_COLOR_F Scene::getBackgroundColor() {
	return backgroundColor;
}