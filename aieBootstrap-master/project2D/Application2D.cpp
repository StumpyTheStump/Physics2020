#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Gizmos.h"

#include "glm/glm.hpp"
#include "glm/ext.hpp"

#include "PhysicsScene.h"
#include "Circle.h"
#include "aligned_bounding_box.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);

	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);

	//m_texture = new aie::Texture("./textures/numbered_grid.tga");
	//m_shipTexture = new aie::Texture("./textures/ship.png");

	m_physicsScene = new PhysicsScene();
	//m_physicsScene->setGravity(glm::vec2(0, 0));
	m_physicsScene->setTimeStep(0.01f);

	/*circle* ball1;
	ball1 = new circle(glm::vec2(5, 5), glm::vec2(0, 0), 1, 1, glm::vec4(1, 0, 0, 1));
	

	circle* ball2;
	ball2 = new circle(glm::vec2(-5, 5), glm::vec2(0, 0), 1, 1, glm::vec4(0, 0, 1, 1));*/
	
	//m_timer = 0;
	star = (new circle(glm::vec2(5, 5), glm::vec2(0, 0), 1, 1, glm::vec4(1, 1, 0, 1)));
	earth = (new circle(glm::vec2(-5, 5), glm::vec2(0, 0), 1, 1, glm::vec4(0, 0, 1, 1)));

	square = (new aligned_bounding_box(glm::vec2(0, 0), glm::vec2(5, 5), glm::vec2(0, 0), 1));

	m_physicsScene->addObject(star);
	m_physicsScene->addObject(earth);
	m_physicsScene->addObject(square);
	//m_physicsScene->addObject(new circle(glm::vec2(-5, 5), glm::vec2(0, 0), 1, 1, glm::vec4(0, 0, 1, 1)));
	return true;
}

void Application2D::shutdown() {
	
	aie::Gizmos::destroy();
	delete m_physicsScene;
	delete m_font;
	//delete m_texture;
	//delete m_shipTexture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	aie::Gizmos::clear();

	m_physicsScene->update(deltaTime);
	m_physicsScene->updateGizmos();

	// Update the camera position using the arrow keys
	float camPosX;
	float camPosY;
	m_2dRenderer->getCameraPos(camPosX, camPosY);

	if (input->isKeyDown(aie::INPUT_KEY_UP))
		camPosY += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		camPosY -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		camPosX -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		camPosX += 500.0f * deltaTime;

	m_2dRenderer->setCameraPos(camPosX, camPosY);

	if (input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
		star->applyForce(glm::vec2(-1, 0));
		earth->applyForce(glm::vec2(0.5f, 0));
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	//// demonstrate animation
	//m_2dRenderer->setUVRect(int(m_timer) % 8 / 8.0f, 0, 1.f / 8, 1.f / 8);
	//m_2dRenderer->drawSprite(m_texture, 200, 200, 100, 100);

	//// demonstrate spinning sprite
	//m_2dRenderer->setUVRect(0,0,1,1);
	//m_2dRenderer->drawSprite(m_shipTexture, 600, 400, 0, 0, m_timer, 1);

	//// draw a thin line
	//m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);

	//// draw a moving purple circle
	//m_2dRenderer->setRenderColour(1, 0, 1, 1);
	//m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);

	//// draw a rotating red box
	//m_2dRenderer->setRenderColour(1, 0, 0, 1);
	//m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);

	//// draw a slightly rotated sprite with no texture, coloured yellow
	//m_2dRenderer->setRenderColour(1, 1, 0, 1);
	//m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);
	//
	//// output some text, uses the last used colour
	//char fps[32];
	//sprintf_s(fps, 32, "FPS: %i", getFPS());
	//m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	//m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	static float aspectRatio = 16 / 9.0f;
	//aie::Gizmos::draw2D(glm::ortho<float>(-100, 100, -100 / aspectRatio, 100 / aspectRatio, -1.0f, 1.0f));
	aie::Gizmos::draw2D(glm::ortho<float>(-16, 16, -9, 9, -1, 1));

	// done drawing sprites
	m_2dRenderer->end();
}