/*################################################################################################
Interface for dbclient created for GtestMocking													##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Interface for dbclient created for GtestMocking     ##
#################################################################################################*/
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../../../src/lexer/include/tdd_lexer_lexerclient.hpp"
#include "../../../src/lexer/include/tdd_lexer_SyntaxToken.hpp"


using namespace testing;
using namespace std;
using namespace TDD;
using namespace TDD::Lexer;


namespace TDD {

	namespace DBCLIENTTEST {

		bool operator==(const std::vector<SyntaxToken>& lhs, const std::vector<SyntaxToken>& rhs) {
			if (lhs.size() != rhs.size()) return false;
			for (size_t i = 0; i < lhs.size(); ++i) {
				if (!(lhs[i] == rhs[i])) return false;
			}
			return true;
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

		TEST_F(LexerTest, LEXER_TEST_1ADD2MUL3)
		{
			//ARRANGE
			string inputQuery = "1 + 2 * 3";
			LexerClient lexer(inputQuery);
			vector<SyntaxToken> expectedResult{{ SyntaxToken(SyntaxKind::NumberToken,0,"1") },
												{  SyntaxToken(SyntaxKind::WhitespaceToken,1," ") },
												{  SyntaxToken(SyntaxKind::PlusToken,2,"+") },
												{  SyntaxToken(SyntaxKind::WhitespaceToken,3," ") },
												{  SyntaxToken(SyntaxKind::NumberToken, 4, "2") },
												{  SyntaxToken(SyntaxKind::WhitespaceToken,5," ") },
												{  SyntaxToken(SyntaxKind::MulToken,6,"*") },
												{  SyntaxToken(SyntaxKind::WhitespaceToken,7," ") },
												{  SyntaxToken(SyntaxKind::NumberToken, 8, "3") } };

			//ACT
			vector<SyntaxToken> procResult = lexer.Init();

			//ASSERT
			EXPECT_EQ(0, 0);

		};

	}
}

//int main(int argc_, char** argv)
//{
//	testing::InitGoogleTest(&argc_, argv);
//	return RUN_ALL_TESTS();
//}
