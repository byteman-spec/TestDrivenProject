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
#include <memory>
#include "../../syntaxnode/include/tdd_syntaxnode_SyntaxToken.hpp"
#include "../../syntaxnode/include/tdd_syntaxnode_ExpressionSyntaxNode.hpp"
#include "../../lexer/include/tdd_lexer_ilexer.hpp"

using namespace std;
using namespace TDD::SyntaxNode;
using namespace TDD::Lexer;

namespace TDD {

	namespace Parser {
		
		class IParser
		{
		public:

			virtual ExpressionSyntaxNodePtr Parse() = 0;

			virtual ExpressionSyntaxNodePtr Parse(const ILexerPtr& iLexerPtr)
			{
				ExpressionSyntaxNodePtr nullExpressionPtr{};
				return nullExpressionPtr;
			};

			virtual ExpressionSyntaxNodePtr Parse(const string& queryText, SyntaxTokenList tokenList, bool force = false)
			{
				ExpressionSyntaxNodePtr nullExpressionPtr{};
				return nullExpressionPtr;
			};
		};
	}
}
#endif // !TDD_LEXER_IPARSER_HPP
