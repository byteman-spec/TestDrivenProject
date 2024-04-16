/*################################################################################################
#Header class for DBClient																		##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Interface for dbclient created for GtestMocking     ##
#14-Apr-2024				byteman-spec	Fixed History									    ##
#################################################################################################*/
#ifndef TDD_DBCLIENT_DBCONNECTOR_HPP
#define	TDD_DBCLIENT_DBCONNECTOR_HPP
#include <string>
#include "include/tdd_dbclient_idbclient.hpp"
using namespace std;

namespace TDD {

	namespace DBCLIENT {

		class DbConnector{
		private: 
				IDbClient& m_dbClient;
		public :

			DbConnector(IDbClient &dbClient) : m_dbClient(dbClient)
			{
			}

			int Init(string username,string password) 
			{
				auto x = m_dbClient.login(username, password);
				if (x)
					return  0;
				else
					return -1;
			}
		};
	}
}
#endif // !TDD_DBCLIENT_DBCONNECTOR_HPP
