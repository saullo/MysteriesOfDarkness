#include <Engine/Utils/Ini.hpp>
#include <fstream>
#include <sstream>

namespace Engine::Utils
{
    Ini::Ini(const char *path)
    {
        std::map<std::string, std::string> *section = nullptr;
        std::fstream file(path);
        std::string line;
        while (std::getline(file, line, '\n'))
        {
            if (line.starts_with("#") || line.starts_with(";"))
                continue;

            size_t i = 0;
            while (i < line.length() && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'))
                i++;

            if (i > line.length())
                continue;

            switch (line[i])
            {
            case '[': {
                i++;
                std::stringstream section_stream;
                while (i < line.length() && line[i] != ']')
                {
                    section_stream << line[i];
                    i++;
                }
                auto pair = std::make_pair<std::string, std::map<std::string, std::string>>(section_stream.str(), {});
                section = &m_sections.emplace(pair).first->second;
                break;
            }
            default: {
                std::stringstream key_stream;
                while (i < line.length() && line[i] != '=')
                {
                    key_stream << line[i];
                    i++;
                }
                i++;

                std::stringstream value_stream;
                while (i < line.length() && line[i] != '\n')
                {
                    value_stream << line[i];
                    i++;
                }

                if (!section)
                {
                    auto pair = std::make_pair<std::string, std::map<std::string, std::string>>("", {});
                    section = &m_sections.emplace(pair).first->second;
                }

                section->emplace(key_stream.str(), value_stream.str());
            }
            }
        }
    }

    int Ini::read_integer(const std::string &section, const std::string &key, int default_value)
    {
        auto entry = read_string(section, key);
        if (entry.empty())
            return default_value;
        return std::stoi(entry);
    }

    bool Ini::read_boolean(const std::string &section, const std::string &key, bool default_value)
    {
        auto entry = read_string(section, key, default_value ? "true" : "false");
        return entry == "true";
    }

    std::string Ini::read_string(const std::string &section, const std::string &key, std::string default_value)
    {
        if (!key_exist(section, key))
            return default_value;
        return m_sections.find(section)->second.find(key)->second;
    }

    bool Ini::key_exist(const std::string &section, const std::string &key)
    {
        if (m_sections.contains(section))
            return m_sections.find(section)->second.contains(key);
        return false;
    }

    std::vector<std::string> Ini::sections()
    {
        std::vector<std::string> sections;
        for (const auto &section : m_sections)
            sections.emplace_back(section.first);
        return sections;
    }
} // namespace Engine::Utils