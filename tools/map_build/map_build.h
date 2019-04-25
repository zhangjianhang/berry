#ifndef __MAP_BUILD_H
#define __MAP_BUILD_H

#include <map>
#include <vector>
#include <string>

class map_build {
public:
	map_build(const std::string &str, const std::string &path = ".");
	std::string str();

private:
	struct block {
		std::string type;
		std::string name;
        std::map<std::string, std::string> attr;
		std::map<std::string, std::string> data;
	};

	void parse_block(const std::string &str);
    std::map<std::string, std::string> parse_body(const std::string &str);
    std::map<std::string, std::string> parse_attr(const std::string &str);
	std::string block_tostring(const block &block);
	std::string class_tostring(const block &block);
	std::string map_tostring(const block &block, const std::string &name, bool local = false);
	void writefile(const std::string &filename, const std::string &text);
    std::string scope(const block &block);
    std::string super(const block &block);
    std::string name(const block &block);

private:
	std::vector<block> m_block;
    std::string m_outpath;
};

#endif // !__MAP_BUILD_H
