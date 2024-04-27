/*################################################################################################
## Unit test for IDBClient																		##
## 																								##
## HISTORY																						##
## DATE						#USERNAME		#DESC												##
## 08-Apr-2024				byteman-spec	Unit test for IDBClient							    ##
## 14-Apr-2024				byteman-spec	Fixed History									    ##
#################################################################################################*/
#include "../../src/include/ind_sanitizer_historysanitizer.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>


using namespace testing;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using namespace std;
using namespace IND::SANITIZER;


namespace TDD {

	namespace SANITIZER {
		
		struct HistorySanitizerTest : public testing::Test
		{			
			void SetUp()
			{
			}
			void TearDown()
			{
			}
		};

		TEST_F(HistorySanitizerTest, SANITIZE_HISTORY_FAIL)
		{
			//ARRANGE
			vector<string> invalidFileList{};
			const char* resultantTree = R"(
+++ b/CMakeLists.txt
+++ b/ind/b_push.bat
+++ b/ind/sanitizer/CMakeLists.txt
+++ b/ind/sanitizer/src/historysanitizer/include/tdd_lexertest_lexerclientmock.hpp
+## 08-Apr-2024				byteman-spec	Initial Creation								    ##
+## 14-Apr-2024				byteman-spec	Fixed History									    ##
+++ b/ind/sanitizer/src/historysanitizer/tdd_lexer_lexerunittest.cpp
+## 08-Apr-2024				byteman-spec	Unit test for ILexerClient						    ##
+## 14-Apr-2024				byteman-spec	Fixed History									    ##
+++ b/ind/sanitizer/src/isanitizer/ind_sanitizer_isanitizer.hpp
+## 08-Apr-2024				byteman-spec	Unit test for IDBClient							    ##
+## 14-Apr-2024				byteman-spec	Fixed History									    ##
+++ b/ind/sanitizer/test/historysanitizerunittest/include/ind_historysanitizer_mockhistorysanitizer.hpp
+## 08-Apr-2024				byteman-spec	Unit test for IDBClient							    ##
+## 14-Apr-2024				byteman-spec	Fixed History									    ##
)";
			
			//ACT
			HistorySanitizerPtr historySanitizorPtr = make_shared<HistorySanitizer>(resultantTree, false);
			bool sanity = historySanitizorPtr->Sanitize(invalidFileList);
			//ASSERT
			EXPECT_EQ(sanity, false);

		};

	}
}

//int main(int argc_, char** argv)
//{
//	testing::InitGoogleTest(&argc_, argv);
//	return RUN_ALL_TESTS();
//}
