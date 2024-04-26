/*################################################################################################
## Interface for Lexer		 																	##
## Used to break down the input into Syntax Tokens.												##
##																								##
## HISTORY																						##
## DATE						#USERNAME		#DESC												##
## 08-Apr-2024				byteman-spec	Interface for lexer				       			    ##
## 14-Apr-2024				byteman-spec	Fixed History									    ##
#################################################################################################*/
#ifndef TDD_LEXER_ILEXER_HPP
#define	TDD_LEXER_ILEXER_HPP
#include <string>
#include <vector>
#include "../../syntaxnode/include/tdd_syntaxnode_SyntaxToken.hpp"

using namespace std;
using namespace TDD::SyntaxNode;

namespace TDD {

	namespace Lexer {
		class ILexer;
		using ILexerPtr = shared_ptr<ILexer>;

		class ILexer
		{
		public:
			virtual SyntaxTokenList Init()
			{
				SyntaxTokenList emptyList{};
				return emptyList;
			};

			virtual SyntaxTokenList Init(const string& queryText, bool force = false)
			{
				SyntaxTokenList emptyList{};
				return emptyList;
			};

			virtual string GetQueryString() const
			{
				return "";
			}

		};
	}
}
#endif // !TDD_LEXER_ILEXER_HPP
