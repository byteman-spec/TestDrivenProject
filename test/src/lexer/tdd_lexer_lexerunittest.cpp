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
using namespace TDD::SyntaxNode;


namespace TDD {

	namespace DBCLIENTTEST {

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

		struct LexerTest : public testing::Test
		{
			void SetUp()
			{

			}
			void TearDown()
			{
			}
		};

		TEST_F(LexerTest, LEXER_TEST_1_ADD_2_MUL_3)
		{
			//ARRANGE
			string inputQuery = "1 + 2 * 3";
			LexerClientPtr  lexerClientPtr = make_shared<LexerClient>(inputQuery);
			vector<SyntaxToken> expectedResult{{ SyntaxToken(SyntaxKind::NumberToken,0,"1") },
												{  SyntaxToken(SyntaxKind::WhitespaceToken,1," ") },
												{  SyntaxToken(SyntaxKind::PlusToken,2,"+") },
												{  SyntaxToken(SyntaxKind::WhitespaceToken,3," ") },
												{  SyntaxToken(SyntaxKind::NumberToken, 4, "2") },
												{  SyntaxToken(SyntaxKind::WhitespaceToken,5," ") },
												{  SyntaxToken(SyntaxKind::StarToken,6,"*") },
												{  SyntaxToken(SyntaxKind::WhitespaceToken,7," ") },
												{  SyntaxToken(SyntaxKind::NumberToken, 8, "3") } };

			//ACT
			vector<SyntaxTokenPtr> procResult = lexerClientPtr->Init();

			//ASSERT
			EXPECT_EQ(procResult, expectedResult);

		};

		TEST_F(LexerTest, LEXER_TEST_10_ADD_OPENPARM_8_MUL_OPENPARAM_6_MINUS_1_CLOSEPARAM_CLOSEPARAM_DIVIDE_4)
		{
			//ARRANGE
			string inputQuery = "10 + ( 8 * ( 6 - 1 ) ) / 4";
			LexerClientPtr  lexerClientPtr = make_shared<LexerClient>(inputQuery);
			vector<SyntaxToken> expectedResult{ { SyntaxToken(SyntaxKind::NumberToken,0,"10") },
												{  SyntaxToken(SyntaxKind::WhitespaceToken,2," ") },
												{  SyntaxToken(SyntaxKind::PlusToken,3,"+") },
												{  SyntaxToken(SyntaxKind::WhitespaceToken,4," ") },
												{  SyntaxToken(SyntaxKind::OpenParanthesisToken, 5, "(") },
												{  SyntaxToken(SyntaxKind::WhitespaceToken,6," ") },
												{  SyntaxToken(SyntaxKind::NumberToken,7,"8") },
												{  SyntaxToken(SyntaxKind::WhitespaceToken,8," ") },
												{  SyntaxToken(SyntaxKind::StarToken, 9, "*") }, 											
												{  SyntaxToken(SyntaxKind::WhitespaceToken, 10, " ") }, 
												{  SyntaxToken(SyntaxKind::OpenParanthesisToken, 11, "(") },
												{  SyntaxToken(SyntaxKind::WhitespaceToken, 12, " ") },
												{  SyntaxToken(SyntaxKind::NumberToken,13,"6") },
												{  SyntaxToken(SyntaxKind::WhitespaceToken, 14, " ") },
												{  SyntaxToken(SyntaxKind::HyphenToken,15,"-") },
												{  SyntaxToken(SyntaxKind::WhitespaceToken, 16, " ") },
												{  SyntaxToken(SyntaxKind::NumberToken, 17, "1") },
												{  SyntaxToken(SyntaxKind::WhitespaceToken, 18, " ") },
												{  SyntaxToken(SyntaxKind::CloseParanthesisToken, 19, ")") },
												{  SyntaxToken(SyntaxKind::WhitespaceToken, 20, " ") },
												{  SyntaxToken(SyntaxKind::CloseParanthesisToken, 21, ")") },
												{  SyntaxToken(SyntaxKind::WhitespaceToken, 22, " ") },
												{  SyntaxToken(SyntaxKind::SlashToken, 23, "/") },
												{  SyntaxToken(SyntaxKind::WhitespaceToken, 24, " ") },
												{  SyntaxToken(SyntaxKind::NumberToken, 25, "4") } };

			//ACT
			vector<SyntaxTokenPtr> procResult = lexerClientPtr->Init();

			//ASSERT
			EXPECT_EQ(procResult, expectedResult);

		};

	}
}

//int main(int argc_, char** argv)
//{
//	testing::InitGoogleTest(&argc_, argv);
//	return RUN_ALL_TESTS();
//}
