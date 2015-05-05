#include "ObjectManager.h"
#include "TextureManager.h"
#include "GameLogger.h"

ObjectManager* ObjectManager::m_pInstance = 0;

void ObjectManager::add(GameObject* object, Uint32 level)
{
	while (this->m_ObjectMap.size() <= level)
	{
		this->m_ObjectMap.push_back(new std::vector<GameObject*>());
	}

	this->m_ObjectMap[level]->push_back(object);
}

void ObjectManager::remove(std::string ID)
{
	std::vector<GameObject*>::iterator p;

	for (Uint32 l = 0; l < this->m_ObjectMap.size(); l++) // Level | 0 = Background
	{
		for (Uint32 i = 0; i < this->m_ObjectMap[l]->size(); i++, p++)
		{
			if (this->m_ObjectMap[l]->at(i)->getID() == ID)
			{
				this->m_ObjectMap[l]->erase(p);
				std::stringstream ss;

				ss << "Erased Object (l=" << l << " i=" << i << " id=" << this->m_ObjectMap[l]->at(i)->getID() << " address=" << this->m_ObjectMap[l]->at(i) << std::endl;

				DEBUG(ss);
			}
		}
	}
}

void ObjectManager::render(float camX, float camY)
{
	for (Uint32 l = 0; l < this->m_ObjectMap.size(); l++) // Level | 0 = Background
	{
		for (Uint32 i = 0; i < this->m_ObjectMap[l]->size(); i++)
		{
			this->m_ObjectMap[l]->at(i)->render(camX, camY);
		}
	}
}

void ObjectManager::update(Timer* timer)
{
	for (Uint32 l = 0; l < this->m_ObjectMap.size(); l++) // Level | 0 = Background
	{
		for (Uint32 i = 0; i < this->m_ObjectMap[l]->size(); i++)
		{
			this->m_ObjectMap[l]->at(i)->update(timer->GetTicks() + 1);
			//timer->restart();
		}
		/*SDL_Color tc = { 255, 255, 255, 255 };
		std::stringstream ss;
		ss << timer->GetTicks();
		TextureManager::Instance()->loadText(ss.str(), tc, "Text1");*/
	}
}

void ObjectManager::handleInput(SDL_Event e)
{
	for (Uint32 l = 0; l < this->m_ObjectMap.size(); l++) // Level | 0 = Background
	{
		for (Uint32 i = 0; i < this->m_ObjectMap[l]->size(); i++)
		{
			this->m_ObjectMap[l]->at(i)->handleInput(e);
		}
	}
}

GameObject* ObjectManager::getObject(std::string ID)
{
	for (Uint32 l = 0; l < this->m_ObjectMap.size(); l++) // Level | 0 = Background
	{
		for (Uint32 i = 0; i < this->m_ObjectMap[l]->size(); i++)
		{
			if (this->m_ObjectMap[l]->at(i)->getID() == ID)
			{
				return this->m_ObjectMap[l]->at(i);
			}
		}
	}
	
	return NULL;
}