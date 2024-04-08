/*################################################################################################
Interface for dbclient created for GtestMocking													##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Interface for dbclient created for GtestMocking     ##
#################################################################################################*/
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "../../../src/dbclient/tdd_dbclient_dbconnector.hpp"


using namespace testing;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using namespace std;


namespace TDD {

	namespace DBCLIENTTEST {
		
		class MockDBClient : public DBCLIENT::IDbClient {
		public:
			MOCK_METHOD0(checkhealth, int());
			MOCK_METHOD1(logout, bool (string username));
			MOCK_METHOD2(login, bool (string username, string password));
		};

		struct DbClientTest : public testing::Test
		{			
			void SetUp()
			{
			}
			void TearDown()
			{
			}
		};

		TEST_F(DbClientTest, LOGIN_VALIDCREDS)
		{
			//ARRANGE
			MockDBClient mockDbClient;
			TDD::DBCLIENT::DbConnector dbConnector(mockDbClient);
			EXPECT_CALL(mockDbClient, login("byteman-spec", "adminriot")).Times(AtLeast(1)).WillOnce(Return(true));
			
			//ACT
			int connectionSuccess = dbConnector.Init("byteman-spec", "adminriot");
			
			//ASSERT
			EXPECT_EQ(connectionSuccess, 0);

		};

	}
}

//int main(int argc_, char** argv)
//{
//	testing::InitGoogleTest(&argc_, argv);
//	return RUN_ALL_TESTS();
//}
