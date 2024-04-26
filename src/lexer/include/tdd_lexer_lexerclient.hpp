/*################################################################################################
##Header for Lexer implementing ILexer															##
##																								##
## HISTORY																						##
## DATE						#USERNAME		#DESC												##
## 08-Apr-2024				byteman-spec	Header for lexer				       			    ##
## 14-Apr-2024				byteman-spec	Fixed History									    ##
#################################################################################################*/
#ifndef TDD_LEXER_LEXERCLIENT_HPP
#define	TDD_LEXER_LEXERCLIENT_HPP
#include <string>
#include <vector>
#include "tdd_lexer_ilexer.hpp"
#include "../../syntaxnode/include/tdd_syntaxnode_SyntaxToken.hpp"

using namespace std;

namespace TDD {

	namespace Lexer {
		class LexerClient;
		using LexerClientPtr = shared_ptr<LexerClient>;

		class LexerClient : ILexer
		{
		private :
			string m_queryText;
			int m_position;
			char GetCurrent();
			void Next();
			SyntaxTokenPtr NextToken();
		public:
			LexerClient(string queryText) : m_queryText(queryText)
			{
				m_position = 0;
			}

			LexerClient() : m_queryText("")
			{
				m_position = 0;
			}

			SyntaxTokenList Init() override;

			SyntaxTokenList Init(const string& queryText, bool force = false) override;

			string GetQueryString() const override;
		};
	}
}
#endif // !TDD_LEXER_LEXERCLIENT_HPP
