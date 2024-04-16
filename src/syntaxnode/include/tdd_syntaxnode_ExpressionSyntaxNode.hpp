/*################################################################################################
Header for lexer created 																		##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Header for lexer				       			    ##
#################################################################################################*/
#ifndef TDD_SYNTAXNODE_EXPRESSIONSYNTAXNODE_HPP
#define	TDD_SYNTAXNODE_EXPRESSIONSYNTAXNODE_HPP
#include <string>
#include <vector>
#include "tdd_syntaxnode_SyntaxToken.hpp"
using namespace std;

namespace TDD {

	namespace SyntaxNode {

		class ExpressionSyntaxNode;
		using ExpressionSyntaxNodePtr = shared_ptr<ExpressionSyntaxNode>;

		class ExpressionSyntaxNode : public ISyntaxNode
		{

		};
	}
}
#endif // !TDD_SYNTAXNODE_EXPRESSIONSYNTAXNODE_HPP
