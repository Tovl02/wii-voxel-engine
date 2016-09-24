/*
 * Basic3DScene.h
 *
 *  Created on: 13.06.2015
 *      Author: Kevin
 */

#ifndef _BASIC3DSCENE_H_
#define _BASIC3DSCENE_H_

#include "BasicScene.h"
#include "../renderer/Renderer3D.h"
#include "../components/UIElement.h"
#include "../entity/EntityHandler.h"
#include "../world/Camera.h"
#include "../world/GameWorld.h"

class Basic3DScene: public BasicScene {
public:
	Basic3DScene();
	virtual ~Basic3DScene();
	virtual void Load();
	virtual void Unload();

	virtual void Draw();
	virtual void Update();

	class EntityHandler& GetEntityHandler();

	void SetGraphicsMode(bool textureMode, bool normalMode);

protected:
	class Renderer3D& Get3DRenderer();
	class EntityHandler* m_entityHandler;
	std::vector<UIElement*> m_uiElements;
	class Camera* m_mainCamera;
	class CGameWorld* m_pGameWorld;
};

#endif /* _BASIC3DSCENE_H_ */