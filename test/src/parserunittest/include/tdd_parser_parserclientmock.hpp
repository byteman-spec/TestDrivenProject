/*################################################################################################
#Header to mock IParserClient																	##
#																								##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Initial Creation								    ##
#14-Apr-2024				byteman-spec	Fixed History									    ##
#################################################################################################*/
#ifndef TDD_PARSERUNITTEST_PARSERCLIENTMOCK_HPP
#define	TDD_PARSERUNITTEST_PARSERCLIENTMOCK_HPP
#include <string>
#include <vector>
#include "../../../../src/parser/include/tdd_parser_iparser.hpp"
#include "../../lexerunittest/include/tdd_lexertest_lexerclientmock.hpp"
#include <gmock/gmock.h>

using namespace std;
using namespace TDD::Parser;
using namespace TDD::LexerUnitTest;

namespace TDD {

	namespace ParserUnitTest {
		class ParserClientMock;
		using ParserClientMockPtr = shared_ptr<ParserClientMock>;
		class ParserClientMock : public IParser
		{
		public:
			MOCK_METHOD(ExpressionSyntaxNodePtr, Parse, (const ILexerPtr& iLexerPtr), (override));

			MOCK_METHOD(ExpressionSyntaxNodePtr, Parse, (), (override));

			MOCK_METHOD(ExpressionSyntaxNodePtr, Parse, (const string& queryText, SyntaxTokenList tokenList, bool force), (override));

		};
	}
}
#endif // !TDD_PARSERUNITTEST_PARSERCLIENTMOCK_HPP
