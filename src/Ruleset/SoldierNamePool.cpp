/*
 * Copyright 2010-2013 OpenXcom Developers.
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "SoldierNamePool.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "../Savegame/Soldier.h"
#include "../Engine/RNG.h"
#include "../Engine/Language.h"
#include "../Engine/Exception.h"
#include "../Engine/CrossPlatform.h"

namespace OpenXcom
{

/**
 * Initializes a new pool with blank lists of names.
 */
SoldierNamePool::SoldierNamePool() : _maleFirst(), _femaleFirst(), _maleLast(), _femaleLast(), _look()
{
}

/**
 *
 */
SoldierNamePool::~SoldierNamePool()
{
}

/**
 * Loads the pool from a YAML file.
 * @param filename YAML file.
 */
void SoldierNamePool::load(const std::string &filename)
{
	std::string s = CrossPlatform::getDataFile("SoldierName/" + filename + ".nam");
	std::ifstream fin(s.c_str());
	if (!fin)
	{
		throw Exception(filename + " not found");
	}
	YAML::Parser parser(fin);
	YAML::Node doc;
	parser.GetNextDocument(doc);

	for (YAML::Iterator i = doc["maleFirst"].begin(); i != doc["maleFirst"].end(); ++i)
	{
		std::string name;
		*i >> name;
		_maleFirst.push_back(Language::utf8ToWstr(name));
	}
	for (YAML::Iterator i = doc["femaleFirst"].begin(); i != doc["femaleFirst"].end(); ++i)
	{
		std::string name;
		*i >> name;
		_femaleFirst.push_back(Language::utf8ToWstr(name));
	}
	for (YAML::Iterator i = doc["maleLast"].begin(); i != doc["maleLast"].end(); ++i)
	{
		std::string name;
		*i >> name;
		_maleLast.push_back(Language::utf8ToWstr(name));
	}
	if (const YAML::Node *pName = doc.FindValue("femaleLast"))
	{
		for (YAML::Iterator i = pName->begin(); i != pName->end(); ++i)
		{
			std::string name;
			*i >> name;
			_femaleLast.push_back(Language::utf8ToWstr(name));
		}
	}
	else
	{
		_femaleLast = _maleLast;
	}

	if (const YAML::Node *pName = doc.FindValue("look"))
	{
		for (YAML::Iterator i = pName->begin(); i != pName->end(); ++i)
		{
			unsigned look;
			*i >> look;
			_look.push_back((unsigned char)look);
		}
	}

    if (_maleLast.empty() || _maleFirst.empty() || _femaleFirst.empty())
	{
		throw Exception(filename + " missing name group");
	}
	fin.close();
}

/**
 * Returns a new random name (first + last) from the
 * lists of names contained within.
 * @param gender Returned gender of the name.
 * @return Soldier name.
 */
std::wstring SoldierNamePool::genName(SoldierGender *gender, SoldierLook *look) const
{
	std::wstringstream name;

	unsigned const lastMaleName= _maleFirst.size() - 1;
	unsigned const pick        = RNG::generate(0, lastMaleName + _femaleFirst.size() - 1);
	if (pick <= lastMaleName)
	{
		*gender = GENDER_MALE;
		name << _maleFirst[pick];
		size_t last = RNG::generate(0, _maleLast.size() - 1);
		name << " " << _maleLast[last];
	}
	else
	{
		*gender = GENDER_FEMALE;
		name << _femaleFirst[pick - lastMaleName];
		size_t last = RNG::generate(0, _femaleLast.size() - 1);
		name << " " << _femaleLast[last];
	}

	// enum SoldierLook { LOOK_BLONDE, LOOK_BROWNHAIR, LOOK_ORIENTAL, LOOK_AFRICAN }
	if (NULL != look)
	{
		if (_look.empty())
			*look = (SoldierLook) RNG::generate(LOOK_BLONDE, LOOK_AFRICAN);
		else
		{
			size_t index = RNG::generate(0, _look.size() - 1);
			*look = (SoldierLook)_look[index];
		}
	}

	return name.str();
}

}
