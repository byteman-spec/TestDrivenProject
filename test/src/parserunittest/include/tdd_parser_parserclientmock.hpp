/*################################################################################################
Header for lexer created 																		##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Header for lexer				       			    ##
#################################################################################################*/
#ifndef TDD_PARSERUNITTEST_PARSERCLIENTMOCK_HPP
#define	TDD_PARSERUNITTEST_PARSERCLIENTMOCK_HPP
#include <string>
#include <vector>
#include "../../../../src/parser/include/tdd_parser_iparser.hpp"
#include <gmock/gmock.h>

using namespace std;

namespace TDD {

	namespace ParserUnitTest {
		class ExpressionSyntaxNode;

		class ParserClientMock : IParser
		{

		public:
			MOCK_METHOD(ExpressionSyntaxNode, Parse, (const string& queryText), (override));
		};
	}
}
#endif // !TDD_PARSERUNITTEST_PARSERCLIENTMOCK_HPP