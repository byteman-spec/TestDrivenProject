/*################################################################################################
Header for lexer created 																		##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Header for lexer				       			    ##
#################################################################################################*/
#ifndef TDD_LEXER_LEXERCLIENT_HPP
#define	TDD_LEXER_LEXERCLIENT_HPP
#include <string>
#include <vector>
#include "tdd_lexer_ilexer.hpp"
#include "tdd_lexer_SyntaxToken.hpp"

using namespace std;

namespace TDD {

	namespace Lexer {

		class LexerClient : ILexer
		{
		private :
			string m_queryText;
			int m_position;
			char GetCurrent();
			void Next();
			SyntaxToken NextToken();
		public:
			LexerClient(string queryText) : m_queryText(queryText)
			{
				m_position = 0;
			}
			SyntaxTokenList Init() override;


		};
	}
}
#endif // !TDD_LEXER_LEXERCLIENT_HPP