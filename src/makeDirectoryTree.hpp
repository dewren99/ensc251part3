/*
 * makeDirectoryTree.hpp
 *
 *  Created on: Oct 17, 2016
 *      Author: wcs
 */

#pragma once

#include <string_view>
#include "FileSystem.hpp"

std::shared_ptr<Directory> make_directory_tree(const std::string_view& dirPath);
