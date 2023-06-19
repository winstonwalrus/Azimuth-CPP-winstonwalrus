#include "Azimuth/Resources/Resources.h"

#include "Azimuth/Application.h"

#include <filesystem>
#include <iostream>
#include <algorithm>

using std::filesystem::path;
using std::filesystem::recursive_directory_iterator;
using std::filesystem::is_directory;
using std::filesystem::exists;

Resources* Resources::m_instance = nullptr;

Resources* Resources::GetInstance()
{
    return m_instance;
}

void Resources::Load()
{
    LocateFiles("textures", ".png");
    LocateFiles("textures", ".jpg");
    LocateFiles("images", ".png");
    LocateFiles("sounds", ".wav");
    LocateFiles("sounds", ".ogg");
    LocateFiles("fonts", ".ttf");
}

void Resources::Unload()
{
    for (auto iter = m_resources.begin(); iter != m_resources.end(); ++iter)
        delete iter->second;

    m_resources.clear();
    m_paths.clear();
}

void Resources::LocateFiles(string _folder, string _extension)
{
    const path dir = path(string(Application::GetApplicationDirectory()) + "\\assets\\" + _folder);
    if (!exists(dir))
        return;

    for (recursive_directory_iterator i(dir), end; i != end; ++i)
    {
        if (!is_directory(i->path()))
        {
            if (i->path().extension() == _extension)
            {
                string filename = i->path().filename().string();

                string id = _folder + "\\" + filename.substr(0, filename.find_last_of('.'));
                std::replace(id.begin(), id.end(), '\\', '/');

                m_paths[id] = i->path().string();
            }
        }
    }
}

bool Resources::HasResource(const string& _id) const
{
    return m_resources.contains(_id);
}

string Resources::PathFromID(const string& _id)
{
    if (m_paths.contains(_id))
        return m_paths[_id];

    return "";
}
