/*
 * BasicScene.cpp
 *
 *  Created on: 13.06.2015
 *      Author: Kevin
 */

#include "BasicScene.h"

BasicScene::BasicScene() {
	m_TextureHandler = new TextureHandler();
}

BasicScene::~BasicScene() {

}

void BasicScene::Unload() {
	m_TextureHandler->DestroyAllTextures();
}

