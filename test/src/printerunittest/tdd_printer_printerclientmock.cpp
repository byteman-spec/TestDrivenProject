///*################################################################################################
//interface for dbclient created for gtestmocking													##
//#history																						##
//#date						#username		#desc												##
//#08-apr-2024				byteman-spec	unit test for lexer created for gtestmocking        ##
//#09-apr-2024				byteman-spec	added lexer_test_10_add_openparm_8_mul_				##
//										    openparam_6_minus_1_closeparam_closeparam_divide_4  ##
//#12-apr-2024				byteman-spec	using mocklexerclient for lexing					##
//#################################################################################################*/
//#include <gtest/gtest.h>
//#include <string>
//#include <vector>
//#include <gmock/gmock.h>
//#include "../lexerunittest/include/tdd_lexertest_lexerclientmock.hpp"
//#include "../parserunittest/include/tdd_parser_parserclientmock.hpp"
//#include "../../../src/utils/comparators/include/tdd_utils_comparator_comparatorutils.hpp"
//
//
//using namespace testing;
//using namespace std;
//using namespace tdd;
//using namespace tdd::lexerunittest;
//using namespace tdd::syntaxnode;
//using namespace tdd::parser;
//using namespace tdd::utils::comparator;
//
//
//namespace tdd {
//
//	namespace printerunittest {
//
//		struct printertest : public testing::test
//		{
//		public : 
//			lexerclientmockptr m_mocklexer;
//			ilexerptr m_castedlexerptr;
//			void setup()
//			{
//				string inputquery = "1+2+3";
//				m_mocklexer = make_shared<lexerclientmock>();
//				m_castedlexerptr = static_pointer_cast<ilexer>(m_mocklexer);
//				vector<syntaxtokenptr> expectedresult{ { make_shared<syntaxtoken>(syntaxkind::numbertoken,0,"1") },
//									{  make_shared<syntaxtoken>(syntaxkind::plustoken,1,"+") },
//									{  make_shared<syntaxtoken>(syntaxkind::numbertoken, 2, "2") },
//									{  make_shared<syntaxtoken>(syntaxkind::plustoken,3,"+") },
//									{  make_shared<syntaxtoken>(syntaxkind::numbertoken, 4, "3") } };
//
//				expect_call(*m_mocklexer, init(inputquery,true)).times(atleast(1)).willonce(return(expectedresult));
//
//			}
//			void teardown()
//			{
//			}
//		};
//
//		test_f(printertest, lexer_test_1_add_2_mul_3)
//		{
//			arrange
//			string inputquery = "1+2+3";
//			vector<syntaxtokenptr> expectedresult{ { make_shared<syntaxtoken>(syntaxkind::numbertoken,0,"1") },
//												{  make_shared<syntaxtoken>(syntaxkind::plustoken,1,"+") },
//												{  make_shared<syntaxtoken>(syntaxkind::numbertoken, 2, "2") },
//												{  make_shared<syntaxtoken>(syntaxkind::plustoken,3,"+") },
//												{  make_shared<syntaxtoken>(syntaxkind::numbertoken, 4, "3") } };
//			
//			parser
//			
//			parserclientptr  parserclientptr = make_shared<parserclient>(m_castedlexerptr);
//			auto procresult = parserclientptr->parse();
//			auto x=procresult->getchildren();
//			binaryexpressionsyntaxnode expectedresult(left, syntaxtoken(syntaxkind::plustoken, 3, "+"), numberexpressionsyntaxnode(3));
//
//			parserclient parser(inputquery);
//			binaryexpressionsyntaxnode parsedsyntax = parser.parse();
//			
//			act
//			auto procresult = m_mocklexer.init("1+2+3", true);
//
//			expect_eq(parsedsyntax, expectedresult);
//			assert_true(comparatorutils<syntaxtokenptr>::sharedptr_comparatorlist(lexedresult, expectedresult));
//
//			assert
//			assert_true(comparatorutils<syntaxtokenptr>::sharedptr_comparatorlist(procresult, expectedresult));
//		};
//
//	}
//}
//
//int main(int argc_, char** argv)
//{
//	testing::initgoogletest(&argc_, argv);
//	return run_all_tests();
//}
