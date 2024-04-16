/*################################################################################################
#Unit test for ILexerClient																		##
#																								##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Unit test for ILexerClient						    ##
#14-Apr-2024				byteman-spec	Fixed History									    ##
#################################################################################################*/
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../../../src/lexer/include/tdd_lexer_lexerclient.hpp"
#include "../../../src/syntaxnode/include/tdd_syntaxnode_SyntaxToken.hpp"
#include "../../../src/utils/comparators/include/tdd_utils_comparator_comparatorutils.hpp"


using namespace testing;
using namespace std;
using namespace TDD;
using namespace TDD::Lexer;
using namespace TDD::SyntaxNode;
using namespace TDD::Utils::Comparator;


namespace TDD {

	namespace DBCLIENTTEST {



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
			vector<SyntaxTokenPtr> expectedResult{{ make_shared<SyntaxToken>(SyntaxKind::NumberToken,0,"1") },
												{  make_shared<SyntaxToken>(SyntaxKind::WhitespaceToken,1," ") },
												{  make_shared<SyntaxToken>(SyntaxKind::PlusToken,2,"+") },
												{  make_shared<SyntaxToken>(SyntaxKind::WhitespaceToken,3," ") },
												{  make_shared<SyntaxToken>(SyntaxKind::NumberToken, 4, "2") },
												{  make_shared<SyntaxToken>(SyntaxKind::WhitespaceToken,5," ") },
												{  make_shared<SyntaxToken>(SyntaxKind::StarToken,6,"*") },
												{  make_shared<SyntaxToken>(SyntaxKind::WhitespaceToken,7," ") },
												{  make_shared<SyntaxToken>(SyntaxKind::NumberToken, 8, "3") } };

			//ACT
			vector<SyntaxTokenPtr> procResult = lexerClientPtr->Init();
		
			//ASSERT
			ASSERT_TRUE(ComparatorUtils<SyntaxTokenPtr>::SharedPtr_ComparatorList(procResult,expectedResult));

		};

		TEST_F(LexerTest, LEXER_TEST_10_ADD_OPENPARM_8_MUL_OPENPARAM_6_MINUS_1_CLOSEPARAM_CLOSEPARAM_DIVIDE_4)
		{
			//ARRANGE
			string inputQuery = "10 + ( 8 * ( 6 - 1 ) ) / 4";
			LexerClientPtr  lexerClientPtr = make_shared<LexerClient>(inputQuery);
			vector<SyntaxTokenPtr> expectedResult{ { make_shared<SyntaxToken>(SyntaxKind::NumberToken,0,"10") },
												{  make_shared<SyntaxToken>(SyntaxKind::WhitespaceToken,2," ") },
												{  make_shared<SyntaxToken>(SyntaxKind::PlusToken,3,"+") },
												{  make_shared<SyntaxToken>(SyntaxKind::WhitespaceToken,4," ") },
												{  make_shared<SyntaxToken>(SyntaxKind::OpenParanthesisToken, 5, "(") },
												{  make_shared<SyntaxToken>(SyntaxKind::WhitespaceToken,6," ") },
												{  make_shared<SyntaxToken>(SyntaxKind::NumberToken,7,"8") },
												{  make_shared<SyntaxToken>(SyntaxKind::WhitespaceToken,8," ") },
												{  make_shared<SyntaxToken>(SyntaxKind::StarToken, 9, "*") }, 											
												{  make_shared<SyntaxToken>(SyntaxKind::WhitespaceToken, 10, " ") }, 
												{  make_shared<SyntaxToken>(SyntaxKind::OpenParanthesisToken, 11, "(") },
												{  make_shared<SyntaxToken>(SyntaxKind::WhitespaceToken, 12, " ") },
												{  make_shared<SyntaxToken>(SyntaxKind::NumberToken,13,"6") },
												{  make_shared<SyntaxToken>(SyntaxKind::WhitespaceToken, 14, " ") },
												{  make_shared<SyntaxToken>(SyntaxKind::HyphenToken,15,"-") },
												{  make_shared<SyntaxToken>(SyntaxKind::WhitespaceToken, 16, " ") },
												{  make_shared<SyntaxToken>(SyntaxKind::NumberToken, 17, "1") },
												{  make_shared<SyntaxToken>(SyntaxKind::WhitespaceToken, 18, " ") },
												{  make_shared<SyntaxToken>(SyntaxKind::CloseParanthesisToken, 19, ")") },
												{  make_shared<SyntaxToken>(SyntaxKind::WhitespaceToken, 20, " ") },
												{  make_shared<SyntaxToken>(SyntaxKind::CloseParanthesisToken, 21, ")") },
												{  make_shared<SyntaxToken>(SyntaxKind::WhitespaceToken, 22, " ") },
												{  make_shared<SyntaxToken>(SyntaxKind::SlashToken, 23, "/") },
												{  make_shared<SyntaxToken>(SyntaxKind::WhitespaceToken, 24, " ") },
												{  make_shared<SyntaxToken>(SyntaxKind::NumberToken, 25, "4") } };

			//ACT
			vector<SyntaxTokenPtr> procResult = lexerClientPtr->Init();

			//ASSERT
			ASSERT_TRUE(ComparatorUtils<SyntaxTokenPtr>::SharedPtr_ComparatorList(procResult, expectedResult));

		};

		TEST_F(LexerTest, LEXER_INIT_TEST_1_ADD_2_MUL_3)
		{
			//ARRANGE
			string inputQuery = "1 + 2 * 3";
			LexerClientPtr  lexerClientPtr = make_shared<LexerClient>();
			vector<SyntaxTokenPtr> expectedResult{ { make_shared<SyntaxToken>(SyntaxKind::NumberToken,0,"1") },
												{  make_shared<SyntaxToken>(SyntaxKind::WhitespaceToken,1," ") },
												{  make_shared<SyntaxToken>(SyntaxKind::PlusToken,2,"+") },
												{  make_shared<SyntaxToken>(SyntaxKind::WhitespaceToken,3," ") },
												{  make_shared<SyntaxToken>(SyntaxKind::NumberToken, 4, "2") },
												{  make_shared<SyntaxToken>(SyntaxKind::WhitespaceToken,5," ") },
												{  make_shared<SyntaxToken>(SyntaxKind::StarToken,6,"*") },
												{  make_shared<SyntaxToken>(SyntaxKind::WhitespaceToken,7," ") },
												{  make_shared<SyntaxToken>(SyntaxKind::NumberToken, 8, "3") } };

			//ACT
			vector<SyntaxTokenPtr> procResult = lexerClientPtr->Init(inputQuery,true);

			//ASSERT
			ASSERT_TRUE(ComparatorUtils<SyntaxTokenPtr>::SharedPtr_ComparatorList(procResult, expectedResult));

		};

	}
}

//int main(int argc_, char** argv)
//{
//	testing::InitGoogleTest(&argc_, argv);
//	return RUN_ALL_TESTS();
//}
