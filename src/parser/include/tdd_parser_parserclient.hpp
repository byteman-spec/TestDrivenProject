/*################################################################################################
Header for lexer created 																		##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Header for lexer				       			    ##
#################################################################################################*/
#ifndef TDD_PARSER_PARSERCLIENT_HPP
#define	TDD_PARSER_PARSERCLIENT_HPP
#include <string>
#include <vector>
#include "tdd_parser_iparser.hpp"
#include "../../syntaxnode/include/tdd_syntaxnode_SyntaxToken.hpp"
#include "../../lexer/include/tdd_lexer_ilexer.hpp"

using namespace std;
using namespace TDD::Lexer;
using namespace TDD::SyntaxNode;

namespace TDD {

	namespace Parser {

		class ParserClient : IParser
		{
		private :
			ILexer m_lexer;
			SyntaxTokenList m_syntaxTokens;
			string m_queryText;
			int m_position;
			SyntaxToken GetCurrent();
			void Next();
			SyntaxToken GetCurrentInc();
			SyntaxToken Peek(const int &offset);
			SyntaxToken Match(const SyntaxKind& kind);
			ExpressionSyntaxNode ParsePrimaryExpression();
		public:
			ParserClient(ILexer lexer) : m_lexer(lexer)
			{
				m_position = 0;
				m_queryText="";
				m_syntaxTokens = {};
			}
			ExpressionSyntaxNode Parse(const string& parse) override;


		};
	}
}
#endif // !TDD_PARSER_PARSERCLIENT_HPP
