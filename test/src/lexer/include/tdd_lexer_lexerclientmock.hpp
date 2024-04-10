/*################################################################################################
Header for lexer created 																		##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Header for lexer				       			    ##
#################################################################################################*/
#ifndef TDD_LEXER_LEXERCLIENTMOCK_HPP
#define	TDD_LEXER_LEXERCLIENTMOCK_HPP
#include <string>
#include <vector>
#include "../../../../src/lexer/include/tdd_lexer_ilexer.hpp"
#include <gmock/gmock.h>

using namespace std;

namespace TDD {

	namespace Lexer {

		class LexerClientMock : ILexer
		{

		public:
			MOCK_METHOD(SyntaxTokenList, Init, (), (override));
		};
	}
}
#endif // !TDD_LEXER_LEXERCLIENTMOCK_HPP
