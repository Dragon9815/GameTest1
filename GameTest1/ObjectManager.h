#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "GameObject.h"
#include "IGameObject.h"
#include "Timer.h"
#include "Vector2D.h"
#include <map>
#include <vector>

class ObjectManager
{
public:

	static ObjectManager* Instance()
	{
		if (m_pInstance == 0)
		{
			m_pInstance = new ObjectManager();
		}

		return m_pInstance;
	}

	void add(GameObject* object, Uint32 level);
	void remove(std::string ID);

	void render(float camX, float camY);
	void update(Timer* timer);
	void handleInput(SDL_Event e);

	void intoForeground(std::string ID);
	void levelUp(std::string ID);
	void intoBackground(std::string ID);
	void levelDown(std::string ID);

	GameObject* getObject(std::string ID);


	Vector2D* getCamera() 
	{
		return this->Camera;
	}

private:

	ObjectManager() 
	{
		this->m_ObjectMap.push_back(new std::vector<GameObject*>);
		this->Camera = new Vector2D(0, 0);
	}

	~ObjectManager() {}

	std::vector<std::vector<GameObject*>*> m_ObjectMap;

	Vector2D* Camera;


	static ObjectManager* m_pInstance;
};


#define REGISTER(obj, lvl) ObjectManager::Instance()->add(obj, lvl);

#endif