/*################################################################################################
## Header to mock ILexerClient																	##
## 																								##
## HISTORY																						##
## DATE						#USERNAME		#DESC												##
## 08-Apr-2024				byteman-spec	Initial Creation								    ##
## 14-Apr-2024				byteman-spec	Fixed History									    ##
#################################################################################################*/
#ifndef TDD_LEXERUNITTEST_LEXERCLIENTMOCK_HPP
#define	TDD_LEXERUNITTEST_LEXERCLIENTMOCK_HPP
#include <string>
#include <vector>
#include "../../../../src/lexer/include/tdd_lexer_ilexer.hpp"
#include <gmock/gmock.h>

using namespace std;
using namespace TDD::Lexer;

namespace TDD {

	namespace LexerUnitTest {
		class LexerClientMock;
		using LexerClientMockPtr = shared_ptr<LexerClientMock>;
		class LexerClientMock : public ILexer
		{

		public:
			MOCK_METHOD(SyntaxTokenList, Init,(), (override));

			MOCK_METHOD(string, GetQueryString,(),(const override));

			MOCK_METHOD(SyntaxTokenList, Init, (const string& queryText, bool force ), (override));

		};
	}
}
#endif // !TDD_LEXERUNITTEST_LEXERCLIENTMOCK_HPP
