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
//% * Enter the above information in Directory.hpp too.
//% * Edit the "Helpers" line and "Resources" line.
//% * Your group name should be "P3_<userid1>_<userid2>" (eg. P3_stu1_stu2)
//% * Form groups as described at:  https://courses.cs.sfu.ca/docs/students
//% * Submit one or two files to courses.cs.sfu.ca
//
// Name        : TreeNode.hpp
// Description : Course Project Part 3 (Directory Tree)
//============================================================================

#pragma once

#include <vector>
#include <memory>

//#define USE_OSS

#ifndef USE_OSS
#include <iostream>
#define OUT std::cout
#else
#include <sstream>
extern std::ostringstream oss;
#define OUT oss
#endif

namespace ensc251 {

	static unsigned count = 0;

	class TreeNode
	{
	private:
		typedef std::shared_ptr<TreeNode> TreeNodeSP;
		typedef std::vector<TreeNodeSP> TreeNodeSPVect;

	protected:
		TreeNodeSPVect childSPVector;
		typedef void (TreeNode::*action_func)(void);
		typedef void (TreeNode::*traverse_func)(void);

	public:
		virtual ~TreeNode() {
			// do not modify this insertion on OUT
			OUT << "Destroying TreeNode with " << childSPVector.size() << " children."<< std::endl;
		}
		TreeNode() {};

		virtual std::shared_ptr<TreeNode> clone() const { return std::make_shared<TreeNode>(*this); };

		TreeNode(const TreeNode& nodeToCopy) {
			// ***** this needs work *****
			if (nodeToCopy.childSPVector.size())
				add_childP(nodeToCopy.childSPVector[0]->clone());
		}

		friend void swap(TreeNode& first, TreeNode& second) // the swap function (should never fail!)
		{
			  // enable ADL (not necessary in our case, but good practice)
			using std::swap;
			swap(first.childSPVector, second.childSPVector);
		}

		TreeNode & operator = (TreeNode other) // note: argument passed by value, copy made!
		{
			// ***** Complete this code *****
			return *this; // by convention, always return *this
		}// swapped other (original *this) is destroyed

		void add_childP(TreeNodeSP child){ /* ***** Complete this member function ***** */ }
		void add_children(const TreeNodeSPVect& childPV){ childSPVector.insert(childSPVector.end(), childPV.begin(), childPV.end()); }
		const TreeNodeSPVect& get_children() const { return childSPVector; }

		void traverse_children_post_order(traverse_func tf, action_func af)
		{
			// ***** Complete this member function *****
		}

		void traverse_children_in_order(traverse_func tf, action_func af)
		{
			if(childSPVector.size() != 2) {
				OUT << "Error -- can only do inorder traversal on a node with 2 children" << std::endl;
			}
			// ***** Complete this member function *****
		}

		void traverse_children_pre_order(traverse_func tf, action_func af)
		{
			(this->*af)();
			for(auto childP : childSPVector) {
				(childP.get()->*tf)();
			}
		}

		void count_action()
		{
			count++;
		}

		void count_traverse()
		{
			traverse_children_post_order(&ensc251::TreeNode::count_traverse, &ensc251::TreeNode::count_action);
		}
		void reset_count() { count = 0; }
		unsigned get_count() const { return count; }

	};
}
