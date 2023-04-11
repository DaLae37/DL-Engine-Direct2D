#include "stdafx.h"
#include "Scene.h"

Scene::Scene() {

}

Scene::~Scene() {
	for (auto& object : objectList) {
		SAFE_DELETE(object);
	}
	for (auto& ui : uiList) {
		SAFE_DELETE(ui);
	}
}

void Scene::Render() {
	for (auto& object : objectList) {
		object->Render();
	}

	for (auto& ui : uiList) {
		ui->Render();
	}
}

void Scene::Update(float dTime) {
	for (auto& object : objectList) {
		object->Update(dTime);
	}

	for (auto& ui : uiList) {
		ui->Update(dTime);
	}
}

void Scene::AddObject(Object* object) {
	objectList.push_back(object);
	object->setParent(nullptr);
}

void Scene::RemoveObject(Object* object) {
	objectList.remove(object);
}

void Scene::AddUI(Object* ui) {
	uiList.push_back(ui);
	ui->setParent(nullptr);
}

void Scene::RemoveUI(Object* ui) {
	uiList.remove(ui);
}