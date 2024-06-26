/*################################################################################################
## Header class for Parser		 																##
##																								##
## HISTORY																						##
## DATE						#USERNAME		#DESC												##
## 08-Apr-2024				byteman-spec	Header for parser			       					##
## 14-Apr-2024				byteman-spec	Fixed History									    ##
#################################################################################################*/
#ifndef TDD_PARSER_PARSERCLIENT_HPP
#define	TDD_PARSER_PARSERCLIENT_HPP
#include <string>
#include <vector>
#include "tdd_parser_iparser.hpp"
#include "../../syntaxnode/include/tdd_syntaxnode_SyntaxToken.hpp"

using namespace std;
using namespace TDD::Lexer;
using namespace TDD::SyntaxNode;

namespace TDD {

	namespace Parser {
		class ParserClient;
		using ParserClientPtr = shared_ptr<ParserClient>;

		class ParserClient : public IParser
		{
		private :
			ILexerPtr m_lexer;
			SyntaxTokenList m_syntaxTokenPtrs;
			string m_queryText;
			int m_position;
			SyntaxTokenPtr GetCurrent();
			void Next();
			SyntaxTokenPtr GetCurrentInc();
			SyntaxTokenPtr Peek(const int &offset);
			SyntaxTokenPtr Match(const SyntaxKind& kind);
			ExpressionSyntaxNodePtr ParsePrimaryExpression();
		public:
			ParserClient(ILexerPtr lexer);

			ParserClient();
			
			ExpressionSyntaxNodePtr Parse() override;
 
			ExpressionSyntaxNodePtr Parse(const string& queryText, SyntaxTokenList tokenList, bool force = false) override;

		};
	}
}
#endif // !TDD_PARSER_PARSERCLIENT_HPP
