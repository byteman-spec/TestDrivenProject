/*################################################################################################
Interface for lexer created 																	##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Interface for lexer				       			    ##
#################################################################################################*/
#ifndef TDD_LEXER_IPARSER_HPP
#define	TDD_LEXER_IPARSER_HPP
#include <string>
#include <vector>
#include "../../syntaxnode/include/tdd_syntaxnode_SyntaxToken.hpp"
#include "../../syntaxnode/include/tdd_syntaxnode_ExpressionSyntaxNode.hpp"

using namespace std;
using namespace TDD::SyntaxNode;

namespace TDD {

	namespace Parser {

		class IParser
		{
		public:

			virtual ExpressionSyntaxNode Parse(const string& queryText) = 0;
		};
	}
}
#endif // !TDD_LEXER_IPARSER_HPP