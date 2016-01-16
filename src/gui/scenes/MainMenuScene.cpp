/*
 * MainMenuScene.cpp
 *
 *  Created on: 13.06.2015
 *      Author: Kevin
 */

#include "MainMenuScene.h"
#include "../components/Cursor.h"
#include "../components/UITextureElement.h"
#include "../components/List.h"
#include "Cursor_png.h"
#include "ClassicBackgroundSprite_png.h"
#include "BasicButtonBig_png.h"
#include "BasicButtonBigHighlight_png.h"
#include "MinecraftLogo_png.h"
#include "../../utils/Debug.h"
#include "Hotbar_png.h"

// define all scene components here
#define MMS_BUTTON_SINGLEPLAYER "MMS_btnSingleplayer"
#define MMS_BUTTON_MULTIPLAYER "MMS_btnMultiplayer"
#define MMS_BUTTON_OPTION "MMS_btnOption"
#define MMS_BUTTON_EXIT "MMS_btnExit"
#define MMS_CLASSIC_BACKGROUND "MMS_ClassicBackground"
#define MMS_LOGO "MMS_Logo"
#define MMS_CURSOR "MMS_Cursor"

#define BUTTON_Y_DISTANCE 5


static void startSingleplayer(BasicButton* clickedButton)
{
	Controller::getInstance().getBasicCommandHandler()->executeCommand( SwitchToInGameCommand::Name() );
}

static void exitGame(BasicButton* clickedButton)
{
	Controller::getInstance().end();
}


MainMenuScene::MainMenuScene() {

}

MainMenuScene::~MainMenuScene() {

}

void MainMenuScene::load() {
	Basic2DScene::load();
	m_elements.push_back( new UITextureElement( MMS_CLASSIC_BACKGROUND , m_TextureHandler->createTexture( ClassicBackgroundSprite_png )));
	UITextureElement* logo = new UITextureElement( MMS_LOGO , m_TextureHandler->createTexture( MinecraftLogo_png));
	logo->setX( (rmode->viWidth / 2) - (logo->getWidth() / 2) );
	logo->setY( 30 );
	m_elements.push_back( logo );

	createButtons();

	m_elements.push_back( new Cursor( MMS_CURSOR , m_TextureHandler->createTexture( Cursor_png )));
}

void MainMenuScene::draw() {
	GRRLIB_SetBackgroundColour(0x24, 0x5E, 0x23, 1);
	Basic2DScene::draw();
}

void MainMenuScene::update() {
	Basic2DScene::update();

	// todo kperdlich - just debug stuff, add debug preprocessor definition
	WiiPad* pad = Controller::getInstance().getInputHandler()->getPadByID( WII_PAD_0 );
	if ( pad->buttonsDown() & WPAD_BUTTON_LEFT)
	{
		Controller::getInstance().getBasicCommandHandler()->executeCommand( SwitchToIntroCommand::Name() );
	}
	else if ( pad->buttonsDown() & WPAD_BUTTON_RIGHT )
	{
		Controller::getInstance().getBasicCommandHandler()->executeCommand( SwitchToInGameCommand::Name() );
	}
}

void MainMenuScene::createButtons()
{
	Texture* startButtonTexture = m_TextureHandler->createTexture( BasicButtonBig_png );

	int xPos = (rmode->viWidth / 2) - (startButtonTexture->getWidth() / 2);
	int yPos = (rmode->viHeight / 2) - ( startButtonTexture->getHeight() / 2 );
	int sizeBetweenBtns = startButtonTexture->getHeight() + BUTTON_Y_DISTANCE;

	m_TextureHandler->destroyTextureByID(startButtonTexture->getId());

	List* btnList = new List( xPos, yPos, sizeBetweenBtns );
	btnList->addComponent( createDefaultMainMenuButton( MMS_BUTTON_SINGLEPLAYER, "Singleplayer", &startSingleplayer ));
	btnList->addComponent( createDefaultMainMenuButton( MMS_BUTTON_MULTIPLAYER, "Multiplayer", NULL ));
	btnList->addComponent( createDefaultMainMenuButton( MMS_BUTTON_OPTION, "Option", NULL ));
	btnList->addComponent( createDefaultMainMenuButton( MMS_BUTTON_EXIT, "Exit", &exitGame ));
	m_elements.push_back(btnList);
}


BasicButton* MainMenuScene::createDefaultMainMenuButton(  const char* buttonName, const char* buttontext, void (*clickCallback) (BasicButton*) )
{
	FontHandler* fontHandler = Controller::getInstance().getFontHandler();
	return new BasicButton( 0, 0, buttonName, m_TextureHandler->createTexture( BasicButtonBig_png ), m_TextureHandler->createTexture( BasicButtonBigHighlight_png ), m_TextureHandler->createLabel( buttontext, fontHandler->getNativFontByID( DEFAULT_MINECRAFT_FONT_ID )), clickCallback );
}

