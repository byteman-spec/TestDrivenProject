///*################################################################################################
//Interface for dbclient created for GtestMocking													##
//#HISTORY																						##
//#DATE						#USERNAME		#DESC												##
//#08-Apr-2024				byteman-spec	Unit test for Lexer created for GtestMocking        ##
//#09-Apr-2024				byteman-spec	Added LEXER_TEST_10_ADD_OPENPARM_8_MUL_				##
//										    OPENPARAM_6_MINUS_1_CLOSEPARAM_CLOSEPARAM_DIVIDE_4  ##
//#12-Apr-2024				byteman-spec	Using MockLexerCLient for lexing					##
//#################################################################################################*/
//#include <gtest/gtest.h>
//#include <string>
//#include <vector>
//#include <gmock/gmock.h>
//#include "../lexerunittest/include/tdd_lexertest_lexerclientmock.hpp"
//#include "../parserunittest/include/tdd_parser_parserclientmock.hpp"
//
//
//
//using namespace testing;
//using namespace std;
//using namespace TDD;
//using namespace TDD::LexerUnitTest;
//using namespace TDD::SyntaxNode;
//using namespace TDD::Parser;
//using namespace TDD::Utils::Comparator;
//
//
//namespace TDD {
//
//	namespace PrinterUnitTest {
//
//		struct PrinterTest : public testing::Test
//		{
//		public : 
//			LexerClientMockPtr m_mockLexer;
//			ILexerPtr m_castedLexerPtr;
//			void SetUp()
//			{
//				string inputQuery = "1+2+3";
//				m_mockLexer = make_shared<LexerClientMock>();
//				m_castedLexerPtr = static_pointer_cast<ILexer>(m_mockLexer);
//				vector<SyntaxTokenPtr> expectedResult{ { make_shared<SyntaxToken>(SyntaxKind::NumberToken,0,"1") },
//									{  make_shared<SyntaxToken>(SyntaxKind::PlusToken,1,"+") },
//									{  make_shared<SyntaxToken>(SyntaxKind::NumberToken, 2, "2") },
//									{  make_shared<SyntaxToken>(SyntaxKind::PlusToken,3,"+") },
//									{  make_shared<SyntaxToken>(SyntaxKind::NumberToken, 4, "3") } };
//
//				EXPECT_CALL(*m_mockLexer, Init(inputQuery,true)).Times(AtLeast(1)).WillOnce(Return(expectedResult));
//
//			}
//			void TearDown()
//			{
//			}
//		};
//
//		TEST_F(ParserTest, LEXER_TEST_1_ADD_2_MUL_3)
//		{
//			//ARRANGE
//			string inputQuery = "1+2+3";
//			vector<SyntaxTokenPtr> expectedResult{ { make_shared<SyntaxToken>(SyntaxKind::NumberToken,0,"1") },
//												{  make_shared<SyntaxToken>(SyntaxKind::PlusToken,1,"+") },
//												{  make_shared<SyntaxToken>(SyntaxKind::NumberToken, 2, "2") },
//												{  make_shared<SyntaxToken>(SyntaxKind::PlusToken,3,"+") },
//												{  make_shared<SyntaxToken>(SyntaxKind::NumberToken, 4, "3") } };
//			
//			//Parser
//			
//			ParserClientPtr  parserClientPtr = make_shared<ParserClient>(m_castedLexerPtr);
//			auto procResult = parserClientPtr->Parse();
//			auto x=procResult->GetChildren();
//			//BinaryExpressionSyntaxNode expectedResult(left, SyntaxToken(SyntaxKind::PlusToken, 3, "+"), NumberExpressionSyntaxNode(3));
//
//			//ParserClient parser(inputQuery);
//			//BinaryExpressionSyntaxNode parsedSyntax = parser.parse();
//			
//			//ACT
////			auto procResult = m_mockLexer.Init("1+2+3", true);
//
//			//EXPECT_EQ(parsedSyntax, expectedResult);
//			//ASSERT_TRUE(ComparatorUtils<SyntaxTokenPtr>::SharedPtr_ComparatorList(lexedResult, expectedResult));
//
//			//ASSERT
//		//	ASSERT_TRUE(ComparatorUtils<SyntaxTokenPtr>::SharedPtr_ComparatorList(procResult, expectedResult));
//		};
//
//	}
//}
//
//int main(int argc_, char** argv)
//{
//	testing::InitGoogleTest(&argc_, argv);
//	return RUN_ALL_TESTS();
//}
