#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

// We need an ID for each of our component (position, physics, AI, input handling etc.

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID()
{

	static ComponentID lastID = 0; // every time we call this last id will remember what it was last
	return lastID++; // every time we call it we will get the next one
}

// template function to get the component id

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
	static ComponentID typeID = getComponentTypeID(); // generate new last id and put it into our type id
	return typeID;
}

// allows us i.e. to find out if an entity has a selection of components
constexpr std::size_t maxComponents = 32; 
using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>; 


// baseclass for our components

class Component
{
public:
	Entity* entity;

	virtual void init() {}
	virtual void update() {}
	virtual void draw() {}

	virtual ~Component() {}


};

class Entity
{
private:
	bool active = true;
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;

public:
	void update()
	{
		for (auto& c : components) c->update(); 
		
	}
	void draw() 
	{
		for (auto& c : components) c->draw();
	}
	bool isActive() const { return active; }
	void destroy() { active = false; }

	template <typename T> bool hasComponent() const
	{
		//return componentBitSet[getComponentID<T>];
		/*
		return componentBitSet[getComponentID<T>];
		*/
		return componentBitSet[getComponentTypeID<T>()];

		//return componentBitSet[getComponentID<T>()];
		//return componentBitSet[getComponentID<T>=true];
	}

	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs) 
	{
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		componentArray[getComponentTypeID<T>()] = c;
		componentBitSet[getComponentTypeID<T>()] = true;

		c->init();
		return *c;
	}

	template<typename T> T& getComponent() const
	{
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}

};

class Manager
{
private:
	// vector to hold a list of all our entities
	std::vector<std::unique_ptr<Entity>> entities;

public:
	void update()
	{
		for (auto& e : entities) e->update();
	}
	void draw()
	{
		for (auto& e : entities) e->draw();
	}

	//remove the entities that are not there
	void refresh()
	{
		entities.erase(std::remove_if(std::begin(entities), std::end(entities),
			[](const std::unique_ptr<Entity> &mEntity)
			{
				return !mEntity->isActive();
			}),
		std::end(entities));
	}

	// add an entity to our world through our manager class

	Entity& addEntity()
	{
		Entity* e = new Entity();
		std::unique_ptr<Entity> uPtr{ e };
		// add to our entity list
		entities.emplace_back(std::move(uPtr));
		return *e;
	}




};