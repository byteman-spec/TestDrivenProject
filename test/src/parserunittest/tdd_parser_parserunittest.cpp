/*################################################################################################
#Unit test for IParserClient																	##
#																								##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Unit test for IParserClient						    ##
#14-Apr-2024				byteman-spec	Fixed History									    ##
#################################################################################################*/
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <gmock/gmock.h>
#include "../lexerunittest/include/tdd_lexertest_lexerclientmock.hpp"
#include "../../../src/syntaxnode/include/tdd_syntaxnode_SyntaxToken.hpp"
#include "../../../src/utils/comparators/include/tdd_utils_comparator_comparatorutils.hpp"
#include "../../../src/syntaxnode/include/tdd_syntaxnode_BinaryExpressionSyntaxNode.hpp"
#include "../../../src/syntaxnode/include/tdd_syntaxnode_NumberExpressionSyntaxNode.hpp"
#include "../../../src/parser/include/tdd_parser_parserclient.hpp"


using namespace testing;
using namespace std;
using namespace TDD;
using namespace TDD::LexerUnitTest;
using namespace TDD::SyntaxNode;
using namespace TDD::Parser;
using namespace TDD::Utils::Comparator;


namespace TDD {

	namespace PARSERTEST {

		struct ParserTest : public testing::Test
		{
		public : 
			LexerClientMockPtr m_mockLexer;
			ILexerPtr m_castedLexerPtr;
			void SetUp()
			{
				string inputQuery = "1+2+3";
				m_mockLexer = make_shared<LexerClientMock>();
				m_castedLexerPtr = static_pointer_cast<ILexer>(m_mockLexer);
				vector<SyntaxTokenPtr> expectedResult{ { make_shared<SyntaxToken>(SyntaxKind::NumberToken,0,"1") },
									{  make_shared<SyntaxToken>(SyntaxKind::PlusToken,1,"+") },
									{  make_shared<SyntaxToken>(SyntaxKind::NumberToken, 2, "2") },
									{  make_shared<SyntaxToken>(SyntaxKind::PlusToken,3,"+") },
									{  make_shared<SyntaxToken>(SyntaxKind::NumberToken, 4, "3") } };

				EXPECT_CALL(*m_mockLexer, Init(inputQuery,true)).Times(AtLeast(1)).WillOnce(Return(expectedResult));

			}
			void TearDown()
			{
			}
		};

		TEST_F(ParserTest, PARSER_TEST_1_ADD_2_MUL_3)
		{
			//ARRANGE
			string inputQuery = "1+2+3";
			EXPECT_CALL(*m_mockLexer, GetQueryString()).Times(AtLeast(1)).WillOnce(Return(inputQuery));
			vector<ISyntaxNodePtr> expectedResult{ { make_shared<BinaryExpressionSyntaxNode>
																((make_shared<NumberExpressionSyntaxNode>
										   									(make_shared<SyntaxToken>(SyntaxKind::NumberToken, 0, "1")))
																,make_shared<SyntaxToken>(SyntaxKind::PlusToken,1,"+"),
																(make_shared<NumberExpressionSyntaxNode>
																			(make_shared<SyntaxToken>(SyntaxKind::NumberToken, 2, "2")))) },
												{  make_shared<SyntaxToken>(SyntaxKind::PlusToken,3,"+") },
												{ (make_shared<NumberExpressionSyntaxNode>
																			(make_shared<SyntaxToken>(SyntaxKind::NumberToken, 4, "3")))} };
			
			//Parser
			
			ParserClientPtr  parserClientPtr = make_shared<ParserClient>(m_castedLexerPtr);
			auto procResult = parserClientPtr->Parse();
			//ASSERT
			ASSERT_TRUE(ComparatorUtils<ISyntaxNodePtr>::SharedPtr_ComparatorList(procResult->GetChildren(), expectedResult));
		};

		TEST_F(ParserTest, PARSER_QUERY_TEST_1_ADD_2_MUL_3)
		{
			//ARRANGE
			string inputQuery = "1+2+3";

			vector<ISyntaxNodePtr> expectedResult{ { make_shared<BinaryExpressionSyntaxNode>
																((make_shared<NumberExpressionSyntaxNode>
																			(make_shared<SyntaxToken>(SyntaxKind::NumberToken, 0, "1")))
																,make_shared<SyntaxToken>(SyntaxKind::PlusToken,1,"+"),
																(make_shared<NumberExpressionSyntaxNode>
																			(make_shared<SyntaxToken>(SyntaxKind::NumberToken, 2, "2")))) },
												{  make_shared<SyntaxToken>(SyntaxKind::Plus,3,"+") },
												{ (make_shared<NumberExpressionSyntaxNode>
																			(make_shared<SyntaxToken>(SyntaxKind::NumberToken, 4, "3")))} };

			vector<SyntaxTokenPtr> lexerResult =  m_castedLexerPtr->Init(inputQuery,true);

			//Parser

			ParserClientPtr  parserClientPtr = make_shared<ParserClient>();
			auto procResult = parserClientPtr->Parse(inputQuery, lexerResult,true);
			//ASSERT
			ASSERT_TRUE(ComparatorUtils<ISyntaxNodePtr>::SharedPtr_ComparatorList(procResult->GetChildren(), expectedResult));
		};

	}
}

