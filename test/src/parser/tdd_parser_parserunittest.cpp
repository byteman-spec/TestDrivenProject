/*################################################################################################
Interface for dbclient created for GtestMocking													##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Unit test for Lexer created for GtestMocking        ##
#09-Apr-2024				byteman-spec	Added LEXER_TEST_10_ADD_OPENPARM_8_MUL_				##
										    OPENPARAM_6_MINUS_1_CLOSEPARAM_CLOSEPARAM_DIVIDE_4  ##
#################################################################################################*/
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../../../src/lexer/include/tdd_lexer_lexerclient.hpp"
#include "../../../src/syntaxnode/include/tdd_syntaxnode_SyntaxToken.hpp"


using namespace testing;
using namespace std;
using namespace TDD;
using namespace TDD::Lexer;


namespace TDD {

	namespace PARSERTEST {

		bool operator==(const std::vector<SyntaxToken>& lhs, const std::vector<SyntaxToken>& rhs) {
			if (lhs.size() != rhs.size()) return false;
			for (size_t i = 0; i < lhs.size(); ++i) {
				if (!(lhs[i] == rhs[i])) return false;
			}
			return true;
		}

		struct ParserTest : public testing::Test
		{
			void SetUp()
			{

			}
			void TearDown()
			{
			}
		};

		//TEST_F(ParserTest, LEXER_TEST_1_ADD_2_MUL_3)
		//{
		//	//ARRANGE
		//	string inputQuery = "1+2+3";
		//	LexerClient lexer(inputQuery);
		//	vector<SyntaxToken> expectedResult{ { SyntaxToken(SyntaxKind::NumberToken,0,"1") },
		//										{  SyntaxToken(SyntaxKind::PlusToken,1,"+") },
		//										{  SyntaxToken(SyntaxKind::NumberToken, 2, "2") },
		//										{  SyntaxToken(SyntaxKind::PlusToken,3,"+") },
		//										{  SyntaxToken(SyntaxKind::NumberToken, 4, "3") } };
		//	BinaryExpressionSyntaxNode left(NumberExpressionSyntaxNode(1),SyntaxToken(SyntaxKind::PlusToken,1,"+"), NumberExpressionSyntaxNode(2));
		//	BinaryExpressionSyntaxNode expectedResult(left, SyntaxToken(SyntaxKind::PlusToken, 3, "+"), NumberExpressionSyntaxNode(3));

		//	ParserClient parser(inputQuery);
		//	BinaryExpressionSyntaxNode parsedSyntax = parser.parse();


		//	//ASSERT
		//	EXPECT_EQ(parsedSyntax, expectedResult);

		//};

	}
}

//int main(int argc_, char** argv)
//{
//	testing::InitGoogleTest(&argc_, argv);
//	return RUN_ALL_TESTS();
//}
