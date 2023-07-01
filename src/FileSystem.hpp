//============================================================================
//
//% Student Name 1: Deniz Evrendilek
//% Student 1 #: 301340591
//% Student 1 userid (email): devrendi (devrendi@sfu.ca)
//
//% Below, edit to list any people who helped you with the code in this file,
//%      or put ‘none’ if nobody helped (the two of) you.
//
// Helpers: none
//
// Also, list any resources beyond the course textbook and the course pages on Piazza
// that you used in making your submission.
//
// Resources:  none
//
//%% Instructions:
//% * Put your name(s), student number(s), userid(s) in the above section.
//% * Enter the above information in any other files you are also submitting.
//% * Edit the "Helpers" line and "Resources" line.
//% * Your group name should be "P3_<userid1>_<userid2>" (eg. P3_stu1_stu2)
//% * Form groups as described at:  https://courses.cs.sfu.ca/docs/students
//% * Submit files to courses.cs.sfu.ca
//
// Name        : Directory.hpp
// Description : Course Project Part 3 (Directory Tree)
//============================================================================

#pragma once

#include "TreeNode.hpp"
#include <iomanip>
#include <string>
#include <string_view>

class DirectoryEntry :  public ensc251::TreeNode
{
private:
	std::string m_name;

public:
	DirectoryEntry(std::string_view name): m_name{name} {}

    friend void swap(DirectoryEntry& a, DirectoryEntry& b) noexcept
    {
        using std::swap;
        swap(static_cast<ensc251::TreeNode&>(a), static_cast<ensc251::TreeNode&>(b));
        swap(a.m_name, b.m_name);
    }

	void set_name(const std::string_view& name){ m_name = name; }
	const std::string & get_name() { return m_name; }

	virtual void print_action() = 0;
};

class File :  public DirectoryEntry
{
private:
	// std::string m_content;
public:
	File(std::string_view name): DirectoryEntry(name) {}
	std::shared_ptr<TreeNode> clone() const override { /* ***** Complete this member function ***** */ };

	void print_action() override
	{
		// Do not modify insertion on OUT in this member function!
		OUT << std::setw(20) << this->get_name()+"\tF" << std::endl;
	}
};

class Directory :  public DirectoryEntry
{
public:
	Directory(std::string_view dir_name): DirectoryEntry{dir_name} {}
	std::shared_ptr<TreeNode> clone() const override { return std::make_shared<Directory>(*this); };

	void print_action() override
	{
		// Do not modify insertion on OUT in this member function!
		OUT << std::setw(20) << this->get_name()+"\t|" << " ";
		OUT << this->childSPVector.size() << std::endl;
	}

	void print_traverse()
	{
		// ***** this needs work *****
		// ***** encode the rules in the instructions

		traverse_children_pre_order(
				static_cast<traverse_func>(&Directory::print_traverse),
				static_cast<action_func>(&DirectoryEntry::print_action));
	}
};
