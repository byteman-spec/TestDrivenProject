/*################################################################################################
#Interface for Parser		 																	##
#Used to create a binary syntax tree from the syntax tokens										##
#																								##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Interface for parser			       			    ##
#14-Apr-2024				byteman-spec	Fixed History									    ##
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

		class IParser;
		using IParserPtr = shared_ptr<IParser>;

		class IParser
		{
		public:

			virtual ExpressionSyntaxNodePtr Parse()
			{
				ExpressionSyntaxNodePtr nullExpressionPtr{};
				return nullExpressionPtr;
			};

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
