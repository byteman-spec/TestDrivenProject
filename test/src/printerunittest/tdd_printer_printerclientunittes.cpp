/*################################################################################################
## Unit test for IPrinterClient																	##
##																								##
## HISTORY																						##
## DATE						#USERNAME		#DESC												##
## 08-Apr-2024				byteman-spec	Unit test for IPrinterClient						##
## 14-Apr-2024				byteman-spec	Fixed History									    ##
#################################################################################################*/
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <gmock/gmock.h>
#include "../lexerunittest/include/tdd_lexertest_lexerclientmock.hpp"
#include "../parserunittest/include/tdd_parser_parserclientmock.hpp"
#include "../printerunittest/include/tdd_printer_printerclientmock.hpp"
#include "../../../src/syntaxnode/include/tdd_syntaxnode_BinaryExpressionSyntaxNode.hpp"
#include "../../../src/syntaxnode/include/tdd_syntaxnode_NumberExpressionSyntaxNode.hpp"
#include "../../../src/utils/comparators/include/tdd_utils_comparator_comparatorutils.hpp"
#include "../../../src/printer/include/tdd_printer_printerclient.hpp"


using namespace testing;
using namespace std;
using namespace TDD;
using namespace TDD::LexerUnitTest;
using namespace TDD::ParserUnitTest;
using namespace TDD::SyntaxNode;
using namespace TDD::Parser;
using namespace TDD::Utils::Comparator;


namespace TDD {

	namespace PrinterUnitTest {

		struct PrinterTest : public testing::Test
		{
		public : 
			LexerClientMockPtr m_mockLexer;
			ParserClientMockPtr m_mockParser;
			PrinterClientMockPtr m_mockPrinter;
			PrinterClientPtr m_Printer;
			ILexerPtr m_castedLexerPtr;
			IParserPtr m_castedParserPtr;
			void SetUp()
			{
				string inputQuery = "1+2+3";
				m_mockLexer = make_shared<LexerClientMock>();
				m_mockParser = make_shared<ParserClientMock>();
				m_mockPrinter = make_shared<PrinterClientMock>();
				const char* resultantTree = R"(
└──BinaryExpression
    ├──BinaryExpression
    │   ├──NumberExpression
    │   │   └──NumberToken 1
    │   ├──PlusToken
    │   └──NumberExpression
    │       └──NumberToken 2
    ├──PlusToken
    └──NumberExpression
        └──NumberToken 3
)";
				m_castedLexerPtr = static_pointer_cast<ILexer>(m_mockLexer);
				m_castedParserPtr = static_pointer_cast<IParser>(m_mockParser);
				m_Printer = make_shared<PrinterClient>(m_castedParserPtr);
				vector<SyntaxTokenPtr> expectedResult{ { make_shared<SyntaxToken>(SyntaxKind::NumberToken,0,"1") },
									{  make_shared<SyntaxToken>(SyntaxKind::PlusToken,1,"+") },
									{  make_shared<SyntaxToken>(SyntaxKind::NumberToken, 2, "2") },
									{  make_shared<SyntaxToken>(SyntaxKind::PlusToken,3,"+") },
									{  make_shared<SyntaxToken>(SyntaxKind::NumberToken, 4, "3") } };

				//EXPECT_CALL(*m_mockLexer, Init(inputQuery,true)).Times(AtLeast(1)).WillOnce(Return(expectedResult));
				EXPECT_CALL(*m_mockPrinter, PrintTree()).Times(AtLeast(1)).WillOnce(Return(resultantTree));
				
			}
			void TearDown()
			{
			}
		};

		TEST_F(PrinterTest, LEXER_TEST_1_ADD_2_MUL_3)
		{
			//ARRANGE
			string inputQuery = "1+2+3";
			BinaryExpressionSyntaxNodePtr expectedResultExp = 
				make_shared<BinaryExpressionSyntaxNode>(
						   (make_shared<BinaryExpressionSyntaxNode>
								        ((make_shared<NumberExpressionSyntaxNode>
						   						     (make_shared<SyntaxToken>(SyntaxKind::NumberToken, 0, "1")))
										,make_shared<SyntaxToken>(SyntaxKind::PlusToken, 1, "+")
										,(make_shared<NumberExpressionSyntaxNode>
													 (make_shared<SyntaxToken>(SyntaxKind::NumberToken, 2, "2")))))
							,(make_shared<SyntaxToken>(SyntaxKind::PlusToken, 3, "+"))
							,((make_shared<NumberExpressionSyntaxNode>
										   (make_shared<SyntaxToken>(SyntaxKind::NumberToken, 4, "3")))));

			//Parser
			vector<SyntaxTokenPtr> lexerResult = m_castedLexerPtr->Init(inputQuery, true);
			//EXPECT_CALL(*m_mockParser, Parse()).Times(AtLeast(1)).WillOnce(Return(expectedResultExp));
			//EXPECT_CALL(*m_mockLexer, GetQueryString()).Times(AtLeast(1)).WillOnce(Return(inputQuery));
			auto res = m_mockPrinter->PrintTree();
			//auto res2 = m_Printer->PrintTree();
			//Parser

			auto procResult = m_mockParser->Parse(inputQuery, lexerResult, true);
			const char* treeString = R"(
└──BinaryExpression
    ├──BinaryExpression
    │   ├──NumberExpression
    │   │   └──NumberToken 1
    │   ├──PlusToken
    │   └──NumberExpression
    │       └──NumberToken 2
    ├──PlusToken
    └──NumberExpression
        └──NumberToken 3
)";
			//ACT


			//ASSERT
		//	ASSERT_STREQ(treeString, res);
		};

	}
}


