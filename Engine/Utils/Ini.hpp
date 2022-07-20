#pragma once

#include <map>
#include <string>
#include <vector>

namespace Engine::Utils
{
    class Ini
    {
    public:
        explicit Ini(const char *path);

        int read_integer(const std::string &section, const std::string &key, int default_value = 0);
        bool read_boolean(const std::string &section, const std::string &key, bool default_value = false);
        std::string read_string(const std::string &section, const std::string &key, std::string default_value = "");
        std::vector<std::string> sections();

    private:
        std::map<std::string, std::map<std::string, std::string>> m_sections;

        bool key_exist(const std::string &section, const std::string &key);
    };
} // namespace Engine::Utils