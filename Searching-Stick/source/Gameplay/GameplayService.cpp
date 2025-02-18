﻿#include "Gameplay/GameplayService.h"
#include "Gameplay/GameplayController.h"
#include "Gameplay/StickCollection/StickCollectionController.h"

namespace Gameplay
{
	GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
		collection_controller = new StickCollectionContoller();
	}

	GameplayService::~GameplayService()
	{
		delete (gameplay_controller);
		delete (collection_controller);

	}

	void GameplayService::initialize()
	{
		gameplay_controller->initialize();
		collection_controller->initialize();

		initializeRandomSeed();
	}

	void GameplayService::update()
	{
		gameplay_controller->update();
	}

	void GameplayService::render()
	{
		gameplay_controller->render();
		collection_controller->render();

	}

	void GameplayService::reset()
	{
		gameplay_controller->reset();
		collection_controller->reset();
	}

	void GameplayService::initializeRandomSeed()
	{
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
	}

	void GameplayService::searchElement(Collection::SearchType search_type)
	{
		collection_controller->searchElement(search_type);
	}

	Collection::SearchType GameplayService::getCurrentSearchType()
	{
		return collection_controller->getSearchType();
	}

	int GameplayService::getNumberOfComparisons()
	{
		return collection_controller->getNumberOfComparisons();
	}

	int GameplayService::getNumberOfArrayAccess()
	{
		return collection_controller->getNumberOfArrayAccess();
	}

	int GameplayService::getNumberOfSticks()
	{
		return collection_controller->getNumberOfSticks();
	}

	int GameplayService::getDelayMilliseconds()
	{
		return collection_controller->getDelayMilliseconds();
	}

}