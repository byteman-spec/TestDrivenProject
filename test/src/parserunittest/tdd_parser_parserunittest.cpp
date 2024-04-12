/*################################################################################################
Interface for dbclient created for GtestMocking													##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Unit test for Lexer created for GtestMocking        ##
#09-Apr-2024				byteman-spec	Added LEXER_TEST_10_ADD_OPENPARM_8_MUL_				##
										    OPENPARAM_6_MINUS_1_CLOSEPARAM_CLOSEPARAM_DIVIDE_4  ##
#12-Apr-2024				byteman-spec	Using MockLexerCLient for lexing					##
#################################################################################################*/
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <gmock/gmock.h>
#include "../lexerunittest/include/tdd_lexertest_lexerclientmock.hpp"
#include "../../../src/syntaxnode/include/tdd_syntaxnode_SyntaxToken.hpp"
#include "../../../src/utils/comparators/include/tdd_utils_comparator_comparatorutils.hpp"
//#include "../../../src/syntaxnode/include/tdd_syntaxnode_BinaryExpressionSyntaxNode.hpp"
//#include "../../../src/syntaxnode/include/tdd_syntaxnode_NumberExpressionSyntaxNode.hpp"


using namespace testing;
using namespace std;
using namespace TDD;
using namespace TDD::LexerUnitTest;
using namespace TDD::SyntaxNode;
using namespace TDD::Utils::Comparator;


namespace TDD {

	namespace PARSERTEST {

		bool operator==(std::vector<SyntaxTokenPtr>& lhs, std::vector<SyntaxTokenPtr>& rhs) {
			if (lhs.size() != rhs.size()) return false;
			for (size_t i = 0; i < lhs.size(); ++i) {
				if (!(lhs[i] == rhs[i])) return false;
			}
			return true;
		}

		bool operator==(SyntaxTokenPtr& lhs, SyntaxTokenPtr& rhs) {
			if (!lhs && !rhs) {
				return true;
			}
			if (!lhs || !rhs) {
				return false;
			}
			return *lhs == *rhs;
		}

		struct ParserTest : public testing::Test
		{
		public : 
			LexerClientMock m_mockLexer;
			void SetUp()
			{
				string inputQuery = "1+2+3";
				vector<SyntaxTokenPtr> expectedResult{ { make_shared<SyntaxToken>(SyntaxKind::NumberToken,0,"1") },
									{  make_shared<SyntaxToken>(SyntaxKind::PlusToken,1,"+") },
									{  make_shared<SyntaxToken>(SyntaxKind::NumberToken, 2, "2") },
									{  make_shared<SyntaxToken>(SyntaxKind::PlusToken,3,"+") },
									{  make_shared<SyntaxToken>(SyntaxKind::NumberToken, 4, "3") } };
				EXPECT_CALL(m_mockLexer, Init(inputQuery,true)).Times(AtLeast(1)).WillOnce(Return(expectedResult));

			}
			void TearDown()
			{
			}
		};

		TEST_F(ParserTest, LEXER_TEST_1_ADD_2_MUL_3)
		{
			//ARRANGE
			string inputQuery = "1+2+3";
			vector<SyntaxTokenPtr> expectedResult{ { make_shared<SyntaxToken>(SyntaxKind::NumberToken,0,"1") },
												{  make_shared<SyntaxToken>(SyntaxKind::PlusToken,1,"+") },
												{  make_shared<SyntaxToken>(SyntaxKind::NumberToken, 2, "2") },
												{  make_shared<SyntaxToken>(SyntaxKind::PlusToken,3,"+") },
												{  make_shared<SyntaxToken>(SyntaxKind::NumberToken, 4, "3") } };
			
			vector<SyntaxTokenPtr> lexedResult = m_mockLexer.Init(inputQuery, true);
			//BinaryExpressionSyntaxNode left(NumberExpressionSyntaxNode(1),SyntaxToken(SyntaxKind::PlusToken,1,"+"), NumberExpressionSyntaxNode(2));
			//BinaryExpressionSyntaxNode expectedResult(left, SyntaxToken(SyntaxKind::PlusToken, 3, "+"), NumberExpressionSyntaxNode(3));

			//ParserClient parser(inputQuery);
			//BinaryExpressionSyntaxNode parsedSyntax = parser.parse();
			
			//ACT
			

			//EXPECT_EQ(parsedSyntax, expectedResult);
			ASSERT_TRUE(ComparatorUtils<SyntaxTokenPtr>::SharedPtr_ComparatorList(lexedResult, expectedResult));
		};

	}
}

int main(int argc_, char** argv)
{
	testing::InitGoogleTest(&argc_, argv);
	return RUN_ALL_TESTS();
}
